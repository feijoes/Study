const mongoose = require('mongoose');
const router = require('express').Router();   
const User = mongoose.model('User');
const passport = require('passport');
const utils = require('../lib/utils');


router.get('/protected', passport.authenticate('jwt', { session:false }),(req, res, next) => {
    res.status(200).json({ success:true, msg: "You are login" })
});

router.post('/login', (req, res, next)=>{
    User.findOne({ username : req.body.username })
        .then((user)=>{

            if (!user){
                res.status(401).json({ success:false, msg: " could not find user "})
            }

            const isValid = utils.validPassword(req.body.password, user.hash , user.salt)

            if (isValid){
                
                const { token, expires } = utils.issueJWT(user)

                res.status(200).json({ success: true, user:user, token: token, expires: expires })
            }
            else res.status(401).json({ success: false, msg: "invalid password" })
        })
        .catch(( err )=> next( err ))

});

router.post('/register', (req, res, next)=>{
    const saltHash = passwordUtils.genPassword(req.body.password);
    
    const {salt, hash} = saltHash
  
    const user = {
        usename: req.body.usename,
        hash:hash,
        salt: salt,
    }

    const newUser = new User(user)
    newUser.save().then((user)=>{

        const {token, expires} = utils.issueJWT(user);

        res.json({ success:true , user:user, token:token, expires:expires });
    })
    .catch(err => next(err))

});

module.exports = router;