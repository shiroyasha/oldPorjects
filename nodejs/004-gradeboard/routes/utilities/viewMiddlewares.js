
exports.checkAjax = function(req, res, next) {
    if( req.xhr ) { 
        next();
    }
    else {
        //Something is trying to access 
        //this area without ajax 
        //that should not be allowed
        
        res.redirect('/'); 
    } 
};


exports.requireUser = function(req, res, next) {
    if( req.session.user )
    {
        next();
    }
    else{
        // if there is no user in the session
        // redirect to login page
        res.redirect('/login');
    }
};
