
exports.users = [
                 {
                   username : "shiroyasha",
                   password : 'pass1',
                   permission : 'admin',
                   karma    : 0
                 },
                 {
                   username : "admin",
                   password : 'pass2',
                   permission : 'admin',
                   karma    : 0
                 },
                 {
                     username : 'veverica',
                     password : 'pass3',
                     karma    : 0,
                     permission : 'user'
                 }
                ]

exports.findUser = function(user, pass) {
    var index = -1;

    for( var i = 0; i < exports.users.length; i++)
    {
        if( exports.users[i].username == user && exports.users[i].password == pass )
        {
            index = i;
            break;
        }
    }

    return index;
};


exports.posts = [
                 {
                   title : "Prerada studentskog portala",
                   datum  : new Date(),
                   autor : exports.users[1],
                   text  : "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.",
                   comments : [
                                {
                                    datum : new Date(),
                                    text : "prvi komentar",
                                    autor : exports.users[0]
                                }    
                              ]  
                 },
 
                 {
                   title : "post2",
                   datum  : new Date(),
                   autor : exports.users[1],
                   text  : "text drugog\nposta",
                   comments : [
                                {
                                    datum : new Date(),
                                    text : "prvi komentar drugog posta",
                                    autor : exports.users[2]
                                }    
                              ]  
                 }

                ]

