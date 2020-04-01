"use strict";

Object.defineProperty(exports, "__esModule", {
    value: true
});
exports.inputStream = inputStream;
function inputStream(input) {
    var pos = 0,
        line = 1,
        col = 0;

    var next = function next() {
        var ch = input.charAt(pos++);
        if (ch == "\n") line++, col = 0;else col++;
        return ch;
    };

    var peek = function peek() {
        return input.charAt(pos);
    };

    var eof = function eof() {
        return peek() == "";
    };

    var croak = function croak(msg) {
        throw new Error(msg + " (" + line + ":" + col + ")");
    };

    return Object.freeze({
        next: next,
        peek: peek,
        eof: eof,
        croak: croak
    });
};