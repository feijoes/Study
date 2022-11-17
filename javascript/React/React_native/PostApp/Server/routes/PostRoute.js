const mongoose = require("mongoose");
const router = require("express").Router();
const Post = mongoose.model("posts");

router.post("/", (req, res, next) => {});

router.patch("/", (req, res, next) => {
  const saltHash = utils.genPassword(req.body.password);

  const { salt, hash } = saltHash;

  const user = {
    username: req.body.username,
    email: req.body.email,
    hash: hash,
    salt: salt,
  };

  const newUser = new Post(user);
  newUser
    .save()
    .then((user) => {
      const { token, expires } = utils.issueJWT(user);

      res.json({ success: true, user: user, token: token, expires: expires });
    })
    .catch((err) => next(err));
});

module.exports = router;
