var express = require('express');

var app = express();

app.get('/etage/:etagenum/chambre', function(req, res) {
    res.render('gauge.jade', {etage: req.params.etagenum});
});


app.use(function(req, res, next){
    res.setHeader('Content-Type', 'text/plain');
    res.status(status).send(body)
});

app.listen(8080);