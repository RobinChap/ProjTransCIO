var mongoose = require ('mongoose'), // Nous appelons le module mongoose
Schema = mongoose.Schema; // Nous créeons un schéma mongoose

var schema = new Schema ({
    CPU: {type: double},
    Flux: {type: double},
    Memory: {type: double},
    createdOn: {type: Date, default: Date.now},
}) 

// Nous exportons notre modèle avec comme nom 'Info', 'mesures' sera le nom de notre table
exports.model= mongoose.model('Info', schema, 'mesures');