"use strict";

Object.defineProperty(exports, "__esModule", {
    value: true
});
exports.tokenStream = tokenStream;
function tokenStream(input) {
    var current = null;
    var keywords = " if then else lambda λ true false ";

    var is_keyword = function is_keyword(x) {
        return keywords.indexOf(" " + x + " ") >= 0;
    };

    var is_digit = function is_digit(ch) {
        return (/[0-9]/i.test(ch)
        );
    };

    var is_id_start = function is_id_start(ch) {
        return (/[a-zλ_]/i.test(ch)
        );
    };

    var is_id = function is_id(ch) {
        return is_id_start(ch) || "?!-<>=0123456789".indexOf(ch) >= 0;
    };

    var is_op_char = function is_op_char(ch) {
        return "+-*/%=&|<>!".indexOf(ch) >= 0;
    };

    var is_punc = function is_punc(ch) {
        return ",;(){}[]".indexOf(ch) >= 0;
    };

    var is_whitespace = function is_whitespace(ch) {
        return " \t\n".indexOf(ch) >= 0;
    };

    var read_while = function read_while(predicate) {
        var str = "";
        while (!input.eof() && predicate(input.peek())) {
            str += input.next();
        }return str;
    };

    var read_number = function read_number() {
        var has_dot = false;
        var number = read_while(function (ch) {
            if (ch == ".") {
                if (has_dot) return false;
                has_dot = true;
                return true;
            }
            return is_digit(ch);
        });
        return { type: "num", value: parseFloat(number) };
    };

    var read_ident = function read_ident() {
        var id = read_while(is_id);
        return {
            type: is_keyword(id) ? "kw" : "var",
            value: id
        };
    };

    var read_escaped = function read_escaped(end) {
        var escaped = false,
            str = "";
        input.next();
        while (!input.eof()) {
            var ch = input.next();
            if (escaped) {
                str += ch;
                escaped = false;
            } else if (ch == "\\") {
                escaped = true;
            } else if (ch == end) {
                break;
            } else {
                str += ch;
            }
        }
        return str;
    };

    var read_string = function read_string() {
        return { type: "str", value: read_escaped('"') };
    };
    var skip_comment = function skip_comment() {
        read_while(function (ch) {
            return ch != "\n";
        });
        input.next();
    };

    var read_next = function read_next() {
        read_while(is_whitespace);
        if (input.eof()) return null;
        var ch = input.peek();
        if (ch == "#") {
            skip_comment();
            return read_next();
        }
        if (ch == '"') return read_string();
        if (is_digit(ch)) return read_number();
        if (is_id_start(ch)) return read_ident();
        if (is_punc(ch)) return {
            type: "punc",
            value: input.next()
        };
        if (is_op_char(ch)) return {
            type: "op",
            value: read_while(is_op_char)
        };
        input.croak("Can't handle character: " + ch);
    };

    var peek = function peek() {
        return current || (current = read_next());
    };

    var next = function next() {
        var tok = current;
        current = null;
        return tok || read_next();
    };

    var eof = function eof() {
        return peek() == null;
    };

    return Object.freeze({
        next: next,
        peek: peek,
        eof: eof,
        croak: input.croak
    });
};