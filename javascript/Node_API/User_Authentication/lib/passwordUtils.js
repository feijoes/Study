const crypto = require('crypto');


function validPassword(password, hash, salt) {
    const hashVerify = crypto.pbkdf2Sync(password, salt, 1000, 64, "sha512").toString("hex")
    return hash = hashVerify;
}
function genPassword(password) {
    const salt = crypto.randomBytes(32).toString('hex')
    const genhash = crypto.pbkdf2Sync(password, salt, 1000, 64, "sha512").toString("hex")

    return {
        salt: salt,
        hash: genhash
    }

}

module.exports.validPassword = validPassword;
module.exports.genPassword = genPassword;