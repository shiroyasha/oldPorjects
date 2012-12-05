
/*
 * GET home page.
 */

var db = require('../db/db')


exports.index = function(req, res) {

  res.render('index', { naslov  : 'Moj prvi blog',
                        postovi : db.postovi 
                      });

};



exports.post = function(req, res) {
  var id = req.params.id;

  if( db.postovi[id] )
  {
    res.render('post', { index : id, naslov: 'Moj prvi blog', post : db.postovi[id] });
  }
  else
  {
    throw new Error("no post with id : " + id );
  }
};




exports.newEntry = function(req, res) { 
    res.render('new', {naslov : 'Moj prvi blog'});
};


/*
 *  removes empty lines from string
 */
function cleanUpString(s)
{

    var rez = '';
    var redovi = s.trim().replace(/\r/g, '').split('\n');

    var noviPasus = true;
    for( var i= 0; i < redovi.length; i++ ) {
        if( redovi[i].length == 0 ){
            noviPasus = true;
            rez += '\n';
        }
        else {
            if( noviPasus ) {
                rez += redovi[i];
                noviPasus = false;
            }
            else
            {
                rez += ' ' + redovi[i];
            }
        }
    }

    return rez;
}

exports.newEntrePut = function(req, res) {
    if( req.body.text )
    {
        var text = cleanUpString( req.body.text );
        console.log( text );

        db.postovi.push( { text : text, datum : '20/02/2010', komentari : [] } );
    }   
    res.redirect('/'); 
};

exports.postEdit = function(req, res) {
   console.log( db.postovi[ req.params.id].text );
   res.render('edit', { naslov : "Moj prvi blog", index : req.params.id, 
                        post : db.postovi[ req.params.id ] } ); 
};

exports.postEditPut = function(req, res) {
    console.log( req.body.text );

    db.postovi[req.params.id].text = req.body.text;
    
    res.redirect('/post/'+ req.params.id);
};

