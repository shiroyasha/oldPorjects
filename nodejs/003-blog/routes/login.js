var db = require('../db/db');

exports.login = function( app ) {
    
    app.get('/login', function(req, res) {
        res.render('login', {} );   
    });

    app.post('/login', function(req, res) {
        
        var name = req.body.username;
        var pass = req.body.password;

        if( name && pass ) 
        {
            var index = db.findUser(name, pass);

            if( index > -1 ) 
            {
                req.session.user = db.users[index];
                res.redirect('/');
            }
            else 
            {
                //flash message
                res.redirect('/login');
            }
        }
        else 
        {
            res.redirect('/login');
        }
    });

    app.get('/logout', function(req, res){
        req.session.user = null;
        res.redirect('/');
    });
/*
    app.get('/register', function(req, res){
        res.render('register');
    });

    app.post('/register', function(req, res){
    
    });
*/
};


exports.requireLogin = function(req, res, next) {
    if (req.session.user) 
    {
        next();
    } 
    else 
    {
        res.redirect('/login');
    }
};

