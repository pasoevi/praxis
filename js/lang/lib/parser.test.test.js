"use strict";

var _istream = require("./istream");

var _tstream = require("./tstream");

var _parser = require("./parser");

QUnit.test("hello test", function (assert) {
    var istream = (0, _istream.inputStream)('lambda (x) 10');
    var tstream = (0, _tstream.tokenStream)(istream);

    assert.ok(istream.peek() === "l", "character stream");

    var parsed = (0, _parser.parse)(tstream);
    console.log(JSON.stringify(parsed));

    // const token = tstream.next();
    // assert.equal(token.type, "num", "type: number");
    // assert.equal(token.value, 123, "value: number");
});