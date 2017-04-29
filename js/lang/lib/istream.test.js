"use strict";

var _istream = require("./istream");

QUnit.test("hello test", function (assert) {
    var istream = (0, _istream.inputStream)('sergi');
    assert.ok(istream.next() === "s", "Passed!");
});