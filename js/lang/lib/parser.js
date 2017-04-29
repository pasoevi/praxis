"use strict";

Object.defineProperty(exports, "__esModule", {
    value: true
});
exports.parse = parse;
var FALSE = { type: "bool", value: false };

function parse(input) {
    var PRECEDENCE = {
        "=": 1,
        "||": 2,
        "&&": 3,
        "<": 7, ">": 7, "<=": 7, ">=": 7, "==": 7, "!=": 7,
        "+": 10, "-": 10,
        "*": 20, "/": 20, "%": 20
    };

    var is_punc = function is_punc(ch) {
        var tok = input.peek();
        return tok && tok.type == "punc" && (!ch || tok.value == ch) && tok;
    };

    var is_kw = function is_kw(kw) {
        var tok = input.peek();
        return tok && tok.type == "kw" && (!kw || tok.value == kw) && tok;
    };

    var is_op = function is_op(op) {
        var tok = input.peek();
        return tok && tok.type == "op" && (!op || tok.value == op) && tok;
    };

    var skip_punc = function skip_punc(ch) {
        if (is_punc(ch)) input.next();else input.croak("Expecting punctuation: \"" + ch + "\"");
    };

    var skip_kw = function skip_kw(kw) {
        if (is_kw(kw)) input.next();else input.croak("Expecting keyword: \"" + kw + "\"");
    };

    var skip_op = function skip_op(op) {
        if (is_op(op)) input.next();else input.croak("Expecting operator: \"" + op + "\"");
    };

    var unexpected = function unexpected() {
        input.croak("Unexpected token: " + JSON.stringify(input.peek()));
    };

    var maybe_binary = function maybe_binary(left, my_prec) {
        var tok = is_op();
        if (tok) {
            var his_prec = PRECEDENCE[tok.value];
            if (his_prec > my_prec) {
                input.next();
                return maybe_binary({
                    type: tok.value == "=" ? "assign" : "binary",
                    operator: tok.value,
                    left: left,
                    right: maybe_binary(parse_atom(), his_prec)
                }, my_prec);
            }
        }
        return left;
    };

    var delimited = function delimited(start, stop, separator, parser) {
        var a = [],
            first = true;
        skip_punc(start);
        while (!input.eof()) {
            if (is_punc(stop)) break;
            if (first) first = false;else skip_punc(separator);
            if (is_punc(stop)) break;
            a.push(parser());
        }
        skip_punc(stop);
        return a;
    };

    var parse_call = function parse_call(func) {
        return {
            type: "call",
            func: func,
            args: delimited("(", ")", ",", parse_expression)
        };
    };

    var parse_varname = function parse_varname() {
        var name = input.next();
        if (name.type != "var") input.croak("Expecting variable name");
        return name.value;
    };

    var parse_if = function parse_if() {
        skip_kw("if");
        var cond = parse_expression();
        if (!is_punc("{")) skip_kw("then");
        var then = parse_expression();
        var ret = {
            type: "if",
            cond: cond,
            then: then
        };
        if (is_kw("else")) {
            input.next();
            ret.else = parse_expression();
        }
        return ret;
    };

    var parse_lambda = function parse_lambda() {
        return {
            type: "lambda",
            vars: delimited("(", ")", ",", parse_varname),
            body: parse_expression()
        };
    };

    var parse_bool = function parse_bool() {
        return {
            type: "bool",
            value: input.next().value == "true"
        };
    };

    var maybe_call = function maybe_call(expr) {
        expr = expr();
        return is_punc("(") ? parse_call(expr) : expr;
    };

    var parse_atom = function parse_atom() {
        return maybe_call(function () {
            if (is_punc("(")) {
                input.next();
                var exp = parse_expression();
                skip_punc(")");
                return exp;
            }
            if (is_punc("{")) return parse_prog();
            if (is_kw("if")) return parse_if();
            if (is_kw("true") || is_kw("false")) return parse_bool();
            if (is_kw("lambda") || is_kw("λ")) {
                input.next();
                return parse_lambda();
            }
            var tok = input.next();
            if (tok.type == "var" || tok.type == "num" || tok.type == "str") return tok;
            unexpected();
        });
    };

    var parse_toplevel = function parse_toplevel() {
        var prog = [];
        while (!input.eof()) {
            prog.push(parse_expression());
            if (!input.eof()) skip_punc(";");
        }
        return { type: "prog", prog: prog };
    };

    var parse_prog = function parse_prog() {
        var prog = delimited("{", "}", ";", parse_expression);
        if (prog.length == 0) return FALSE;
        if (prog.length == 1) return prog[0];
        return { type: "prog", prog: prog };
    };

    var parse_expression = function parse_expression() {
        return maybe_call(function () {
            return maybe_binary(parse_atom(), 0);
        });
    };

    return parse_toplevel();
}