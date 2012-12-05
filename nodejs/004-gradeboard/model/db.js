
var users = [ { username : 'admin', password : 'p1' },
              { username : 'shiroyasha', password : 'p2'},
              { username : 'veverica', passwird : 'p3'}
            ];


var predmeti = [ { naziv : 'baze', 
                   sifra : 'I101', 
                   zakljucano : false, 
                   pass : '', 
                   moderatori : [0, 2] 
                 },
                 { naziv : 'diskretna',
                   sifra : 'I203', 
                   zakljucano : false, 
                   pass : '',
                   moderatori : [0] 
                 }
               ];


var kolone = [ {
                    index : 0,
                    naziv : 'rez 1',
                    tip   : 'result',
                    visible : true,
                    funkcija : 'avg(a, b, c)'
               },
               {
                    index : 1,
                    naziv : 'kolokvijum 1',
                    visible : true,
                    tip   : 'integer'
               }
             ];



var podaci = [
                { user : 1, predmet : 1, kolona : 1, 123 }
             ];




exports.getPredmeti = function( func )
{
    var err = null;
    
    func( err, predmeti );
};

exports.getPredmet = function( id, func )
{
    if( id < 0 || id >= predmeti.length ) {
        var err = 'greska';
        func( err , null );
    }
    else
    {
        var err = null;
        var predmet = predmeti[id];
        
        func( err, predmet );        
    }  
};

exports.addPredmet = function( naziv, sifra, zakljucano, pass, moderatori ) {
    var error = null;
    // TODO implement this 
};


exports.getUser = function( username, password , func) {
    var index = -1;
    
    for( var i = 0; i < users.length; i++ )
    {
        if( users[i].username == username && users[i].password == password )
        {
            index = i;
            break;
        }
    }

    var error = null;
    var user = null;
    if( index == -1 ) {
        error = 1; // TODO put something meaningfull in error
    }else {
        user = users[index];
    }
    
    func( error, user );
};
