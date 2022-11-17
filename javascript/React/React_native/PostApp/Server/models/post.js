const mongoose = require('mongoose');

const PostSchema = new mongoose.Schema({
    Id : Number,
    user: String,
    title: String,
    body: String,
    likes: Number
});

mongoose.model('posts', PostSchema);