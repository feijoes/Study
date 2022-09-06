const mongoose = require("mongoose")

const User = new mongoose.Schema({
    name: {type: String},
    age: {type: Number}
});
module.exports= mongoose.model("User",User)