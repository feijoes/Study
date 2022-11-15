const router = require('express').Router();

router.use('/users', require('./UserRoute'));

module.exports = router;