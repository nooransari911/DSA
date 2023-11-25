const express = require ("express");
const app = express ();


app.use ("/static", express.static(__dirname + "/static"));

app.use ((req, res, next) => {
        console.log (`${req.method} ${req.path} ${req.ip}`);
        next ();
});


/*

function greet () {
    console.log ("hello");
    console.log ("hello world!");
}



app.get ("/", (req, res) => {
		res.sendFile (__dirname + "/static/index0.html");
});


app.get ("/json", (req, res) => { 
        res.json ({name: "11", id: 24, fr: "rs"});
});




 



app.listen (3000, () => console.log ("Listening on port 3000 rn;"));


greet ();
*/
