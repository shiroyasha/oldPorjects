var http = require("http")
var url = require("url");


function start( router , handle )
{
    function onRequest(request, response) 
    {
        var putanja = url.parse(request.url).pathname;
        console.log("Request recieved from    " + putanja + " ." )
        
        router( handle, putanja , response );

        console.log("")
    }

    http.createServer(onRequest).listen(8888);

    console.log("Server has started.");
}

exports.start = start;
