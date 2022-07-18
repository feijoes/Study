const express = require("express");
const app = express();
const moongose = require("mongoose");
require("dotenv/config");
const User = require("./model/user.js");

app.use(express.json());
app.get("/",(req,res) =>{
    res.send("Fist request !!");
});
app.get("/users",(req,res) =>{
    let users = ["Pedro","Joao","Facundo"]
    res.send({
        users: users
    });
});
app.post("/createUser", async (req,res)=>{
    try{
        const newUser = new User(req.body);
        await newUser.save();
        res.send(newUser);
    } catch (error){
        res.send({message:error});
    };
});
moongose.connect(process.env.DB_CONECCTION_STRING,
    {useUnifiedTopology:true,useNewUrlParser:true},(req,res)=>{
        console.log(req)
});

app.listen(3000,() => {
    console.log('Listening to "http://localhost:3000/"');
});