function inputStream(input) {
    let pos = 0, line = 1, col = 0;
   
    const next = function () {
        let ch = input.charAt(pos++);
        if (ch == "\n") line++, col = 0; else col++;
        return ch;
    };

    const peek = function () {
        return input.charAt(pos);
    };

    const eof = function () {
        return peek() == "";
    };

    const croak = function (msg) {
        throw new Error(msg + " (" + line + ":" + col + ")");
    };

    return Object.freeze({
        next,
        peek,
        eof,
        croak
    });
};

function tokenStream(input) {
    let current = null;
    let keywords = " if then else lambda λ true false ";
    
    const is_keyword = function (x) {
        return keywords.indexOf(" " + x + " ") >= 0;
    };

    const is_digit = function (ch) {
        return /[0-9]/i.test(ch);
    };
    
    const is_id_start = function (ch) {
        return /[a-zλ_]/i.test(ch);
    };

    const is_id = function (ch) {
        return is_id_start(ch) || "?!-<>=0123456789".indexOf(ch) >= 0;
    };
    
    const is_op_char = function (ch) {
        return "+-*/%=&|<>!".indexOf(ch) >= 0;
    };
    
    let  is_punc = function (ch) {
        return ",;(){}[]".indexOf(ch) >= 0;
    };

    let is_whitespace = function (ch) {
        return " \t\n".indexOf(ch) >= 0;
    };
    
    let read_while = function (predicate) {
        let str = "";
        while (!input.eof() && predicate(input.peek()))
            str += input.next();
        return str;
    };

    let read_number = function () {
        let has_dot = false;
        let number = read_while(function(ch){
            if (ch == ".") {
                if (has_dot) return false;
                has_dot = true;
                return true;
            }
            return is_digit(ch);
        });
        return { type: "num", value: parseFloat(number) };
    };

    let read_ident = function () {
        let id = read_while(is_id);
        return {
            type  : is_keyword(id) ? "kw" : "var",
            value : id
        };
    };

    let read_escaped = function (end) {
        let escaped = false, str = "";
        input.next();
        while (!input.eof()) {
            let ch = input.next();
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

    let read_string = function () {
        return { type: "str", value: read_escaped('"') };
    }
    let skip_comment = function () {
        read_while(function(ch){ return ch != "\n" });
        input.next();
    };

    let read_next = function () {
        read_while(is_whitespace);
        if (input.eof()) return null;
        let ch = input.peek();
        if (ch == "#") {
            skip_comment();
            return read_next();
        }
        if (ch == '"') return read_string();
        if (is_digit(ch)) return read_number();
        if (is_id_start(ch)) return read_ident();
        if (is_punc(ch)) return {
            type  : "punc",
            value : input.next()
        };
        if (is_op_char(ch)) return {
            type  : "op",
            value : read_while(is_op_char)
        };
        input.croak("Can't handle character: " + ch);
    };

    let peek = function () {
        return current || (current = read_next());
    };

    let next = function () {
        let tok = current;
        current = null;
        return tok || read_next();
    };

    let eof = function () {
        return peek() == null;
    }

    return Object.freeze({
        next,
        peek,
        eof,
        croak : input.croak
    });
};

let  FALSE = { type: "bool", value: false };

function parse(input) {
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

let istream = inputStream('lambda (x) 10');
let tstream = tokenStream(istream);

   
let parsed = parse(tstream);
console.log(JSON.stringify(parsed));

