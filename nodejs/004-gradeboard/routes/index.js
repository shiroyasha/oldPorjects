
/*
 * GET home page.
 */
var db = require('../model/db')
var mw = require('./utilities/viewMiddlewares')

exports.index = function(app) {
    
    app.get('/', mw.requireUser, function(req, res) {
        
        db.getPredmeti( function(err, predmeti) {
            if( err) 
                throw new Error('greska pri ispisu predmeta');
            else {
                console.log(predmeti)
                res.render('index', { predmeti : predmeti } );    
            }    
        });

    });
};
