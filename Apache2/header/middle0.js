/*
middle0.js, middle1.js have middleware functions;
these are executed after getting req and before sending res;
including any middleware function in app.use () means the middleware function
will be executed after getting req and before sending res
for the routes specified in app.use;

If no route is specified in app.use, then the route is "/";
If route is specified in app.use, included middlewares
are executed for all routes that begin in route included in app.use;

Middlewares are executed in the order they appear
in app.use from left to right;


It is necessary to include next as parameter in all middlewares;
invoking
next ();
ends the current middleware function and begins the next middleware function;
alternative to including next is somehow ending middleware
 */

const logging = (req, res, next) => {
    console.log (req.method + " " + req.path + " " + req.ip);
    // alternative is:
    // console.log (`${req.method} ${req.path} ${req.ip}`);
    next ();
}

module.exports = logging;