
function route( handle, path, response )
{
    if( typeof handle[path] == 'function')
    {
        handle[path]( response );
    }
    else
    {
        console.log("no handler found for " + path )

        response.writeHead( 200, {"Content-Type " : "text/plain"});
        response.write("404 file not found");
        response.end();
    }
}

exports.route = route;
