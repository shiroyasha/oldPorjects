
/**
 * Module dependencies.
 */

var express = require('express');

var app = module.exports = express.createServer();

// Configuration

app.dynamicHelpers({
  session: function(req, res){
    return req.session;
  },
  title: function(req, res){
    return 'gradeBook';
  }

});

app.configure(function(){
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.use(express.bodyParser());
  app.use(express.methodOverride());
  app.use(express.cookieParser());
  app.use(express.session( { secret : 'some secret code'} ));
  app.use(app.router);
  app.use(express.static(__dirname + '/public'));
});

app.configure('development', function(){
  app.use(express.errorHandler({ dumpExceptions: true, showStack: true }));
});

app.configure('production', function(){
  app.use(express.errorHandler());
});

// Routes
var login = require('./routes/login');
login.login( app );

var index = require('./routes/index');
index.index( app );

var predmet = require('./routes/predmet')
predmet.predmet( app );

app.listen(3000);
console.log("Express server listening on port %d in %s mode", app.address().port, app.settings.env);
