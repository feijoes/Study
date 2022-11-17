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
    title: req.body.title,
    body: req.body.body,
    likes: 0,
  };
  const newPost = new Post(post);
  newPost
    .save()
    .then((post) => {
      res.status(201).json({ success: true, post: post });
    })
    .catch((err) => next(err));
});

router.patch("/", (req, res, next) => {
  Post.findOne({ Id: req.body.postId }).then((post) => {
    if (!post) {
      res.status(401).json({ success: false, msg: "Could not find Post" });
    }
    if (Object.keys(req.body).length === 1) {
      if (req.body.add == true)
        Post.findOneAndUpdate(post, { likes: post.likes + 1 });
      else if (req.body.add == false)
        Post.findOneAndUpdate(post, { likes: post.likes + 1 });
      else res.status(401).json({ success: false, msg: "bad request" });
      res.status(204);
    }
    if (post.user === req.user.username) {
      Post.findOneAndUpdate(post, req.body)
        .then((newPost) => {
          res.status(200).json({ success: true, post: newPost });
        })
        .catch((err) => next(err));
    }
    res.status(400).json({ success: false, msg: "Unauthorized to edit post" });
  });
});
router.delete("/", (req, res, next) => {
  Post.findOne({ Id: req.body.postId }).then((post) => {
    if (!post) {
      res.status(401).json({ success: false, msg: "Could not find Post" });
    }
    if (post.user === req.user.username) {
        Post.findOneAndDelete(post)
        res.status(200).json({success: true})
    }

    res.status(400).json({ success: false, msg: "Unauthorized to edit post" });
  });
});

module.exports = router;
