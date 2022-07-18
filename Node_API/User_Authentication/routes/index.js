const router = require('express').Router();
const passport = require('passport');
const passwordUtils = require('../lib/passwordUtils');
const connection = require('../config/database');
const { isAdmin, isAuth } = require('./authMiddlewar');
const User = connection.models.User;


 router.post('/login', passport.authenticate("local", {
    failureRedirect: "/login-failure",
    successRedirect: "/login-success"
  }));

 router.post('/register',(req, res)=>{
    const saltHash = passwordUtils.genPassword(req.body.password);
    
    const {salt, hash} = saltHash
    // very unsafe admin creation
    if (req.body.admin){
        const user = {
            usename: req.body.usename,
            hash:hash,
            salt: salt,
            admin: true
        }
    } else {
        const user = {
            usename: req.body.usename,
            hash:hash,
            salt: salt,
            admin: false
        }
    }
    const newUser = new User(user)
    newUser.save()

    res.redirect('/login')
 });



router.get('/', (req, res, next) => {
    res.send('<h1>Home</h1><p>Please <a href="/register">register</a></p>');
});

router.get('/admin',isAuth, isAdmin ,(req, res, next) => {
    res.send("Admin here")
});
router.get('/login', (req, res, next) => {
   
    const form = '<h1>Login Page</h1><form method="POST" action="/login">\
    Enter Username:<br><input type="text" name="username">\
    <br>Enter Password:<br><input type="password" name="password">\
    <br><br><input type="submit" value="Submit"></form>';

    res.send(form);

});

router.get('/register', (req, res, next) => {

    const form = '<h1>Register Page</h1><form method="post" action="register">\
                    Enter Username:<br><input type="text" name="username">\
                    <br>Enter Password:<br><input type="password" name="password">\
                    <br><br><input type="submit" value="Submit"></form>';

    res.send(form);
    
});


router.get('/logout', (req, res, next) => {
    req.logout();
    res.redirect('/protected-route');
});


router.get('/login-failure', (req, res, next) => {
    res.send('You entered the wrong password.');
});

router.get('/protected-route', isAuth, (req, res, next) => {
    res.send('<h1>You are authenticated</h1><p><a href="/logout">Logout and reload</a></p>');
 
});

router.get('/login-success',isAuth , (req, res, next) => {
    res.send('<p>You successfully logged in. --> <a href="/protected-route">Go to protected route</a></p>');
});

module.exports = router;