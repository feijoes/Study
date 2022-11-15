const fs = require('fs');
const path = require('path');
const User = require('mongoose').model('User');
const JwtStategy = require('passport-jwt').Strategy;
const ExtractJwt = require('passport-jwt').ExtractJwt;
const pathToKey = path.join(__dirname, '..', 'id_rsa_pub.pem');
const PUB_KEY = fs.readFileSync(pathToKey, 'utf8');


const options = {
    jwtFromRequest: ExtractJwt.fromAuthHeaderWithScheme("jwt"),
    secretOrKey : PUB_KEY ,
    algorithms: ['RS256']
};
const Strategy = new JwtStategy(options, (payload, done) =>{

    User.findOne({ _id: payload.sub }).then((user)=>{

        if (user) {
            return done(null, user)
        }
        else {
            return done(null, false)
        }

    })
    .catch(err => done(err, false))

})
module.exports = (passport) => {
    passport.use(Strategy)
};