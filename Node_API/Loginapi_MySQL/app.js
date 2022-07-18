if (process.env.NODE_ENV !== "production") require("dotenv").config()


// Expreess
const express = require("express");
const app = express();
const flash = require("express-flash");
const session = require("express-session");

// DB Conecction
const mySQL = require("mysql2")
const db = mySQL.createConnection({
    host: "localhost",
    user: "root",
    password: process.env.MYSQL_PASSWORD,
    database: "nodemysql"
})
db.connect((error)=>{
    if (error) throw error;
    console.log("MySQL conected...")
})

// Create DB
app.get("/createdb",(req,res)=>{
    let sql = "CREATE DATABASE nodemysql"
    db.query(sql, (err, result)=>{
        if (err) throw err;
        console.log(result)
        res.send("database created")
    })
})
app.get("/deletetable",(req,res)=>{
    let sql = "DROP TABLE users"
    db.query(sql, (err, result)=>{
        if (err) throw err;
        res.send("TABLE delete")
    })
})
app.get("/createuserstable",(req,res)=>{
    let sql = "CREATE TABLE users(id int AUTO_INCREMENT, email VARCHAR(255), name VARCHAR(255),password VARCHAR(255), PRIMARY KEY(id))"
    db.query(sql, (err, result)=>{
        if (err) throw err;
        res.send("TABLE created")
    })
})
// passport 
const passport = require("passport");
const initialpassport = require("./passport.config");

// Others dependecies
const bcrypt = require("bcrypt");
const methotOverride = require("method-override");



const checkAuthenticated = (req,res,next)=> {
    if (req.user) return next()
    return res.redirect("/login")
};
const checkNotAuthenticated = (req,res,next)=> {
    if (!req.user) return next()
    return res.redirect("/")
};

db.query("SELECT * FROM users",(err, results)=>{
    if (err) throw err;

    initialpassport(
        passport,
        email => results.find(user => user.email === email),
        id => results.find(user => user.id === id)
    )
    return results
})



app.set("view-engine","ejs");
/* APPS USE */
app.use(express.urlencoded({extended:false}));
app.use(flash());
app.use(session({secret: process.env.SESSION_SECRET, resave:false , saveUninitialized: false}));
app.use(passport.initialize());
app.use(passport.session());
app.use(methotOverride("_method"))



app.get("/", checkAuthenticated , (req, res)=>{
    db.query("SELECT * FROM users",(err, results)=>{
        if (err) throw err;
        results.forEach(item => delete item["password"])
        res.json({ users: results })
    })
});


app.get("/user/:id", checkAuthenticated , (req, res)=>{
    id = req.params.id
    db.query("SELECT * FROM users WHERE id = " + id ,(err, results)=>{
        if (err) throw err;
        res.json(results[0])
    })
});
app.get("/logout", (req, res)=>{
    req.logout((err)=> {
    if (err) {return next(err);}
    res.redirect('/login');});
});
app.use(checkNotAuthenticated);

app.get("/register",(req, res)=>{
    res.render("register.ejs")
});

app.post("/register", async (req, res)=>{
    try{
        const encript = await bcrypt.hash(req.body.password, 10)
        user = {
            name: req.body.name,
            email: req.body.email,
            password: encript
        }
        let sql = 'INSERT INTO users SET ?'
        let query = db.query(sql,user, (err, result)=>{
            if (err) throw err;
            console.log(result)
        })
        res.redirect("/login")
    } catch{
        res.redirect("/login")
    }
});

app.get("/login",(req, res)=>{

    res.render("login.ejs")
});

app.post("/login", passport.authenticate("local",{
    successRedirect:"/",
    failureRedirect: "/login",
    failureFlash: true
}),(req,res)=>{
    return res.redirect("/")
});





app.listen(3000,() => {
    console.log('Listening to "http://localhost:3000/"');
});