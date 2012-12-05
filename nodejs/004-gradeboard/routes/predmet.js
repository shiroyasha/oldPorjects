

var db = require('../model/db')
var mw = require('./utilities/viewMiddlewares')


exports.predmet = function(app) {

    app.get('/predmeti/new', mw.requireUser, function( req, res ) {
        res.render('predmeti/new'); 
    });

    app.post('/predmeti/new', mw.requireUser, function( req, res ) {
        res.redirect('/');  
    });


    app.get('/predmeti/:id', mw.requireUser, function( req, res ) {
        
        db.getPredmet( req.params.id, function( err, predmet ) {
            if( err )
                throw new Error( err );
            else
                res.render('predmeti/main', { predmet : predmet } );
        });

    } );
};

