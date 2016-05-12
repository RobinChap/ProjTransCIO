var express = require('express');
router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('charts-gauge');
});

module.exports = router;