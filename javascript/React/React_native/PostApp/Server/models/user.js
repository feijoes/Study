const mongoose = require('mongoose');

const UserSchema = new mongoose.Schema({
    username: String,
    email: String,
    hash: String,
    salt: String
});

mongoose.model('User', UserSchema);