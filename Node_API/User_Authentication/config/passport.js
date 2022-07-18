
const passport = require('passport');
const { validPassword } = require('../lib/passwordUtils');
const LocalStrategy = require('passport-local').Strategy;
const connection = require('./database');
const User = connection.models.User;

const Fields = {
    usernameField : "username",
    passwordField : "password"
}
const VerifiyCallback =  ( username, password, done )=>{
    
    User.finOne({ username:username }
    ).then((user)=>{

        if (!user) { return done(null, false ) }

        const Valid = validPassword(password, user.hash, user.salt)

        if (Valid){
            return done(null, user)
        } else {
            return done(null, false)
        }
    }).catch((err)=>{
        done(err);
    })

}
const Strategy = new LocalStrategy();

passport.use(Strategy);

passport.serializeUser((user,done)=>{
    done(null,user.id)
})

passport.deserializeUser(( userId, done )=>{
    User.findById(userId
        ).then((user)=>{
            
            done(null,user)
            
        }).catch((err) => done(err))
})
