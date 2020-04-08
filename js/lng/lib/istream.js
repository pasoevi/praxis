export function inputStream(input) {
    let pos = 0,
        line = 1,
        col = 0;

    const next = function () {
        let ch = input.charAt(pos++);
        if (ch == "\n") line++, col = 0;else col++;
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