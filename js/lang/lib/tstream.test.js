"use strict";

var _istream = require("./istream");

var _tstream = require("./tstream");

QUnit.test("hello test", function (assert) {
    var istream = (0, _istream.inputStream)('123');
    var tstream = (0, _tstream.tokenStream)(istream);

    assert.ok(istream.peek() === "1", "character stream");

    var token = tstream.next();
    assert.equal(token.type, "num", "type: number");
    assert.equal(token.value, 123, "value: number");
});