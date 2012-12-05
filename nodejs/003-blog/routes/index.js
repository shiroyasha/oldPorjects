var db = require('../db/db');
var posts = db.posts;
var requireLogin = require('./login').requireLogin;

exports.index = function( app ) {

    app.get('/', function(req, res) {
        console.log( req.xhr );
        res.render('index', { posts : posts })
    });
    
    /*
     * TODO: check user = autor
     */

    function checkAutor(req, res, next)
    {
        console.log( req.params.id );
        console.log( req.session.user.username );
        console.log( db.users[req.params.id].username);

        if( req.params.id >= 0 && req.params.id < db.users.length &&
            req.session.user.username == db.posts[req.params.id].autor.username )
            next();
        else
            res.redirect('/')
    }

    app.get('/post/:id/edit', requireLogin, checkAutor, function(req, res){
        res.render('blog/postEdit',{ post: db.posts[req.params.id] } );
    });

    app.post('/post/:id/edit', requireLogin, checkAutor, function(req, res){
            var id = req.params.id;
            db.posts[id].title = req.body.title;
            var text = req.body.text.replace('[\r]+', '');
            db.posts[id].text = text.replace(/[\n\r][\n\r]+/g, '\n\n');
            if( req.body.updateDate )
                db.posts[id].datum = new Date();

            res.redirect('/');
    });

    app.get('/post/new', requireLogin, function(req, res) {
        res.render('blog/postNew');
    });

    app.post('/post/new', requireLogin, function(req, res){
        var title = req.body.title;
        var text = req.body.text;

        if( title && text )
        {
            var post = { title : title,
                         text  : text,
                         autor : req.session.user,
                         comments : {} 
                       };

            db.posts.push( post );
        }
        res.redirect('/'); 
    });
    
    /* 
    *  Comments
    */  

    app.post('/post/:id/comment/new', requireLogin, function(req, res) {
        if( posts.length > req.params.id )
        {
            posts[req.params.id].comments.push({
                datum : new Date(),
                text : req.body.text,
                autor : req.session.user
            });

            res.send('novi komentar');
        }   
        else
        {
            throw new Error('nije dobar id');
        }    
    });

};
