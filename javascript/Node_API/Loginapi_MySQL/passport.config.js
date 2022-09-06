const Passport = require('passport-local').Strategy;
const bcrypt = require("bcrypt");

const initialize =  (passport,getUserByEmail,getUserById)=>{
    passport.use( new Passport({ usernameField: "email"},(email,password,done)=>{
        const user = getUserByEmail(email);
        if (user == null) return done(null, false, { message: "No such User"});
        try {
            if (bcrypt.compareSync(password, user.password) == true)return done(null, user)
            else return done(null, false, { message : "incorrect password" });
        }  catch (e) { 
            return done(e)
        } 
    }))
    passport.serializeUser((user, done) => done(null,user.id))
    passport.deserializeUser((id, done) => done(null,getUserById(id)))
};

module.exports = initialize