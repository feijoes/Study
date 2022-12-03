const mongoose = require('mongoose');

const PostSchema = new mongoose.Schema({
    Id : String,
    user: String,
    body: String,
    time : { type : Date, default: Date.now }
});

mongoose.model('posts', PostSchema);