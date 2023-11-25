const express = require ("express");
const app = express ();
const logging = require ("./header/middle0");
const auth0 = require ("./header/middle1");

const {exec} = require ("child_process");
exec ("./hello", (error, stdout, stderr) => {
	console.log (stdout);
});





//this callback function is called for every HTTP verb used;
//console logs method, path, ip in request;
/*
app.use ((req, res, next) => {
	console.log (`${req.method} ${req.path} ${req.ip} ${__dirname}`);
	next ();
});*/
app.use (logging, auth0);
app.use (express.static ("./static"));
app.use (express.urlencoded({extended : false}));



//root; sends file in directory "./static.index0.html";
app.get ("/", (req, res) => {
	res.sendFile (__dirname + "/static/index0.html");
	//res.send ("<h1>This is HTML embedded</h1>");
	//res.end ();
})


//callbacks can be chained using next;
app.get ("/now", (req, res, next) => {
	req.time = new Date().toString ();
	next ();
}, (req, res) => {
	res.json ({"time": req.time});
	console.log (`${req.time}`);
});


//route parameters; stored in req.params of form {id0: value, id1: value}
app.get ("/para/:id0/:id1", (req, res) => {
	res.json (req.params);
	console.log (`id0 is : ${req.params.id0}; id1 is : ${req.params.id1}`);
});


//query parameters; stored in req.query of form {first: value, last: value, ....}
//note that size of req.params is fixed but size of req.query is not fixed and take any size;
/*app.get ("/name", (req, res, next) => {
	res.json ({ name : `${req.query.first} ${req.query.last}`});
})*/

app.get ("/name", (req, res) => {
	//res.sendFile ("index2.html");
	res.sendFile (__dirname + "/static/index2.html");
})


//body parameters; user input is stored in req.body object;

app.post ("/name", (req, res, next) => {
	//res.sendFile (__dirname + "/static/index0.html");
	res.json ({ name : `${req.body.first} ${req.body.last}`});
	console.log (`${req.body.first} ${req.body.last}`);
})




app.listen (3000, () => {
	console.log ("listening on port 3000 rn");

})
