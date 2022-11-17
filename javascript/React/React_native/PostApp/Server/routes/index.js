const router = require("express").Router();

router.use("/users", require("./UserRoute"));
router.use("/posts", require("./PostRoute"));
module.exports = router;
