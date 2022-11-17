const mongoose = require('mongoose');
const router = require('express').Router();   
const User = mongoose.model('users');
const passport = require('passport');
const utils = require('../lib/utils');


router.get('/protected', passport.authenticate('jwt', { session:false }),(req, res, next) => {
    res.status(200).json({ success:true, msg: "You are login" })
});

router.post('/login', (req, res, next)=>{

    User.findOne({ email : req.body.email })
        .then((user)=>{
            if (!user){
                res.status(401).json({ success:false, msg: "Could not find user "})
            }

            const isValid = utils.validPassword(req.body.password, user.hash , user.salt)

            if (isValid){
                
                const { token, expires } = utils.issueJWT(user)

                res.status(200).json({ success: true, user:user, token: token, expires: expires })
            }
            else res.status(401).json({ success: false, msg: "Invalid password" })
        })
        .catch(( err )=> next( err ))

});

router.post('/register', (req, res, next)=>{
    const saltHash = utils.genPassword(req.body.password);
    console.log(req.body)
    const {salt, hash} = saltHash
  
    const user = {
        username: req.body.username,
        email: req.body.email,
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