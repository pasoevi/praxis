/*
 * Grammar
 * Skip whitespace.
 * * If input.eof, then return null.
 * If it is a sharp sign (#), skip comment and retry after the end of
 * line)
 * * If it's a quote, read a string.
 * * If it's a digit, then proceed to read a number.
 * * If it's letter, then read an identifier or a keyword token.
 * * If it's one of the punctuation characters, return a punctuation
 * token.
 * * If it's one of the operator characters, return an operator token.
 * * If none of the above, error out with input.croak().
 */
function tokenStream(input) {
    let current = null,
        keywords = " if then else lambda true false ";

    function is_keyword(tok) {
        return keywords.indexOf(" " + tok + " ") >= 0;
    }

    function is_digit(ch) {
        return /[0-9]/i.test(ch);
    }

    function is_id_start(ch) {
        return /[a-z_]/i.test(ch);
    }

    function is_id(ch) {
        return is_id_start(ch) || "?!-<>=0123456789".indexOf(ch) >= 0;
    }

    function is_op_char(ch) {
        return "-*/%=&|<>!".indexOf(ch) >= 0;
    }

    function is_punc(ch) {
        return ",;(){}[]".indexOf(ch) >= 0;
    }

    function is_whitespace(ch) {
        return " \t\n".indexOf(ch) >= 0;
    }

    function read_while(predicate) {
        var str = '';
        while (!input.eof() && predicate(input.peek()))
            str += input.next();

        return str;
    }

    function read_number() {
        var has_dot = false;
        var number = read_while(function(ch) {
            if (ch == '.') {
                if (has_dot)
                    return false;
                has_dot = true;
                return true;
            }
            return is_digit(ch);
        });
        return {
            type: "num",
            value: parseFloat(number)
        };
    }

    function read_indent() {
        var id = read_while(is_id);
        return {
            type: is_keyword(id) ? "kw" : "var",
            value: id
        };
    }

    function read_escaped(end) {
        var escaped = false;
        str = '';

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
    }

    function read_string() {
        return {
            type: "str",
            value: read_escaped('"')
        };
    }

    function skip_comment() {
        read_while(function(ch) {
            return ch != "\n";
        });
        input.next();
    }

    function read_next() {
        read_while(is_whitespace);

        if (input.eof()) {
            return null;
        }

        let ch = input.peek();
        if (ch == "#") {
            skip_comment();
            return read_next();
        }

        if (ch == '"') {
            return read_string();
        }

        if (is_digit(ch)) {
            return read_number();
        }

        if (is_id_start(ch)) {
            return read_ident();
        }

        if (is_punc(ch)) {
            return Object.freeze({
                type: "punc",
                value: input.next()
            });
        }

        if (is_op_char(ch)) {
            return Object.freeze({
                type: "op",
                value: read_while(is_op_char)
            });
        }

        /*
         * If none of the above matched ch, ch is incorrect syntax.
         */
        input.croak("can't handle character: " + ch);
    }

    function peek() {
        return current || (current = read_next());
    }

    function next() {
        var tok = current;
        current = null;
        return tok || read_next();
    }

    function eof() {
        return peek() == null;
    }

    return Object.freeze({
        next: next,
        peek: peek,
        eof: eof,
        croak: input.croak
    });
}