let  FALSE = { type: "bool", value: false };

export function parse(input) {
    const PRECEDENCE = {
        "=": 1,
        "||": 2,
        "&&": 3,
        "<": 7, ">": 7, "<=": 7, ">=": 7, "==": 7, "!=": 7,
        "+": 10, "-": 10,
        "*": 20, "/": 20, "%": 20,
    };
    
    let is_punc = function (ch) {
        let tok = input.peek();
        return tok && tok.type == "punc" && (!ch || tok.value == ch) && tok;
    };

    let is_kw = function (kw) {
        let tok = input.peek();
        return tok && tok.type == "kw" && (!kw || tok.value == kw) && tok;
    };

    let is_op = function (op) {
        let tok = input.peek();
        return tok && tok.type == "op" && (!op || tok.value == op) && tok;
    };

    let skip_punc = function (ch) {
        if (is_punc(ch)) input.next();
        else input.croak("Expecting punctuation: \"" + ch + "\"");
    };

    let skip_kw = function (kw) {
        if (is_kw(kw)) input.next();
        else input.croak("Expecting keyword: \"" + kw + "\"");
    };

    let skip_op = function (op) {
        if (is_op(op)) input.next();
        else input.croak("Expecting operator: \"" + op + "\"");
    };

    let unexpected = function () {
        input.croak("Unexpected token: " + JSON.stringify(input.peek()));
    };

    let maybe_binary = function (left, my_prec) {
        let tok = is_op();
        if (tok) {
            let his_prec = PRECEDENCE[tok.value];
            if (his_prec > my_prec) {
                input.next();
                return maybe_binary({
                    type     : tok.value == "=" ? "assign" : "binary",
                    operator : tok.value,
                    left     : left,
                    right    : maybe_binary(parse_atom(), his_prec)
                }, my_prec);
            }
        }
        return left;
    };

    let delimited = function (start, stop, separator, parser) {
        let a = [], first = true;
        skip_punc(start);
        while (!input.eof()) {
            if (is_punc(stop)) break;
            if (first) first = false; else skip_punc(separator);
            if (is_punc(stop)) break;
            a.push(parser());
        }
        skip_punc(stop);
        return a;
    };

    let parse_call = function (func) {
        return {
            type: "call",
            func: func,
            args: delimited("(", ")", ",", parse_expression),
        };
    };

    let parse_varname = function () {
        let name = input.next();
        if (name.type != "var") input.croak("Expecting variable name");
        return name.value;
    };

    let parse_if = function () {
        skip_kw("if");
        let cond = parse_expression();
        if (!is_punc("{")) skip_kw("then");
        let then = parse_expression();
        let ret = {
            type: "if",
            cond: cond,
            then: then,
        };
        if (is_kw("else")) {
            input.next();
            ret.else = parse_expression();
        }
        return ret;
    };

    let parse_lambda = function () {
        return {
            type: "lambda",
            vars: delimited("(", ")", ",", parse_varname),
            body: parse_expression()
        };
    };
    
    let parse_bool = function () {
        return {
            type  : "bool",
            value : input.next().value == "true"
        };
    };

    let maybe_call = function (expr) {
        expr = expr();
        return is_punc("(") ? parse_call(expr) : expr;
    };

    let parse_atom = function () {
        return maybe_call(function(){
            if (is_punc("(")) {
                input.next();
                let exp = parse_expression();
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
            let tok = input.next();
            if (tok.type == "var" || tok.type == "num" || tok.type == "str")
                return tok;
            unexpected();
        });
    };

    let parse_toplevel = function () {
        let prog = [];
        while (!input.eof()) {
            prog.push(parse_expression());
            if (!input.eof()) skip_punc(";");
        }
        return { type: "prog", prog: prog };
    };

    let parse_prog = function () {
        let prog = delimited("{", "}", ";", parse_expression);
        if (prog.length == 0) return FALSE;
        if (prog.length == 1) return prog[0];
        return { type: "prog", prog: prog };
    };
    
    let parse_expression = function () {
        return maybe_call(function(){
            return maybe_binary(parse_atom(), 0);
        });
    };

    return parse_toplevel();
}