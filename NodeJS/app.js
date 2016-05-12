var express = require('express');
var session = require('express-session');
var cookieParser = require('cookie-parser');
var path = require('path');
var bodyParser = require('body-parser');
var mongoose = require('mongoose');
var routes = require('./routes/index.js');

var app = express();


app.listen(3006);

// view engine setup
app.set('views', path.join(__dirname, 'app/views'));
app.set('view engine', 'jade');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
//app.use(express.static(path.join(__dirname, 'app/public')));
app.use(express.static(__dirname + '/../www'));

app.use(cookieParser());
app.use(session({secret: "any",
				saveUninitialized:true,
				resave: true }));

app.use('/', routes);

mongoose.connect('mongodb://localhost/bdd', function(err){
	if(err) { throw err; }
});

// catch 404 and forward to error handler
/*app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});*/


module.exports = app;