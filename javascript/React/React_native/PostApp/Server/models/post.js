const mongoose = require('mongoose');

const PostSchema = new mongoose.Schema({
    user: String,
    title: String,
    body: String,
    likes: Number
});

mongoose.model('posts', PostSchema);