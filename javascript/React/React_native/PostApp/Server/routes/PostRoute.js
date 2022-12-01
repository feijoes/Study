const mongoose = require("mongoose");
const router = require("express").Router();
const Post = mongoose.model("posts");
const passport = require("passport");
const { v4 } = require("uuid");

router.use(passport.authenticate("jwt", { session: false }));

router.get("/", (req, res, next) => {
  Post.find()
    .then((posts) => res.json({ posts }))
    .catch((err) => next(err));
});

router.post("/", (req, res, next) => {
  const post = {
    Id: v4(),
    user: req.user.username,
    body: req.body.body,
  };
  const newPost = new Post(post);
  newPost
    .save()
    .then((post) => {
      res.status(201).json({ success: true, post: post });
    })
    .catch((err) => next(err));
});


module.exports = router;
