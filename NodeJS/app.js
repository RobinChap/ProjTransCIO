var express = require('express');

var app = express();

app.get('/etage/:etagenum/chambre', function(req, res) {
    res.render('chambre.ejs', {etage: req.params.etagenum});
});


app.use(function(req, res, next){
    res.setHeader('Content-Type', 'text/plain');
    res.send(404, 'Page introuvable !');
});

app.listen(8080);