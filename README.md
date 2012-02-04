A basic nil object for use in javascript.

## Usage Ideas
One of the common pain points that started the conversations to create this 
project was working with JSON.  You commonly have a lot of hasOwnProperty or 
key related calls to see if a value is availble before searching deeper on
the object.  Using this nil module you would be able to assume that any 
depth of key is at least valid and then just use basic boolean expressions
to check values.

Here's a JSON.parse wrapper to use nil:

    var nil = require("nil");
    function json_parse(str) {
        var js = {}
        try {
          js = JSON.parse(str);
        } catch(E) {
        }
        js.__proto__ = nil.Nil();
        return js;
    }

