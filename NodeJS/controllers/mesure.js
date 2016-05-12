require('../models/mesure');

var mongoose = require('mongoose'),
    Info = mongoose.model('Info');

var Infos = {
    index: function (req, res) {

        Info.find({}, function (err, infos) {
            if (err) throw err;

            // object of all the users
            console.log(infos);
        });
    },

    create: function (req, res) {

        var i = new Info({
            CPU: req.body.CPU,
            Flux: req.body.Flux,
            Memoire: req.body.Memoire
        });

        i.save(function (err) {
            if (err) {
                console.log(err);
            }
            console.log('L\'info a été enregistré!');
            console.log(i);
        });

    }
};

module.exports = Infos;