
var mw = require('./utilities/viewMiddlewares');
var db = require('../model/db');

exports.login = function( app )
{
    app.get('/login', function(req, res) {
        var redirectUrl = req.params.redirectUrl || '/';
        
        if( req.session.user ) {
            res.redirect( redirectUrl );
        }
        else {
            res.render('login/login', { redirectUrl : redirectUrl } );
        }
    });

    app.post('/login', function(req, res) {
         var redirectUrl = req.body.redirectUrl || '/';

         // TODO keep logged in logic

         db.getUser( req.body.username, req.body.password, function(err, user) {
            if( err ) {
                // TODO flash some message
                res.redirect('/login');
            }
            else {
                req.session.user = user;
                res.redirect( redirectUrl );
            }     
         });
    });

    app.get('/logout', mw.requireUser, function(req, res) {
        req.session.user = null;
        
        res.redirect('/');    
    });



    app.get('/register', function(req, res) {
        res.render('login/register');     
    });

    app.post('/register/check', mw.checkAjax, function(req, res) {
        //TODO check things
    });

    app.post('/register', function(req, res) {
        // TODO check data

        // TODO register new user

        // TODO redirect to root
    });

    //TODO lost password logic

};
