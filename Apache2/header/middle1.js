const auth0 = (req, res, next) => {
    console.log ("THOU SHALL NOT PASS VALIDATION");
    next ();
}

module.exports = auth0;