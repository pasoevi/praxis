export function tokenStream(input) {
    let current = null;
    let keywords = " if then else lambda λ true false ";

    const is_keyword = function (x) {
        return keywords.indexOf(" " + x + " ") >= 0;
    };

    const is_digit = function (ch) {
        return (/[0-9]/i.test(ch)
        );
    };

    const is_id_start = function (ch) {
        return (/[a-zλ_]/i.test(ch)
        );
    };

    const is_id = function (ch) {
        return is_id_start(ch) || "?!-<>=0123456789".indexOf(ch) >= 0;
    };

    const is_op_char = function (ch) {
        return "+-*/%=&|<>!".indexOf(ch) >= 0;
    };

    let is_punc = function (ch) {
        return ",;(){}[]".indexOf(ch) >= 0;
    };

    let is_whitespace = function (ch) {
        return " \t\n".indexOf(ch) >= 0;
    };

    let read_while = function (predicate) {
        let str = "";
        while (!input.eof() && predicate(input.peek())) str += input.next();
        return str;
    };

    let read_number = function () {
        let has_dot = false;
        let number = read_while(function (ch) {
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
            type: is_keyword(id) ? "kw" : "var",
            value: id
        };
    };

    let read_escaped = function (end) {
        let escaped = false,
            str = "";
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
    };
    let skip_comment = function () {
        read_while(function (ch) {
            return ch != "\n";
        });
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
            type: "punc",
            value: input.next()
        };
        if (is_op_char(ch)) return {
            type: "op",
            value: read_while(is_op_char)
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
    };

    return Object.freeze({
        next,
        peek,
        eof,
        croak: input.croak
    });
};