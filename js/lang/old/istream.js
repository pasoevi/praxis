function inputStream(input) {
    let pos = 0,
        line = 1,
        col = 0;
    /*
     * Return the next value from the stream and discard it.
     */
    let next = function() {
        var ch = input.charAt(pos++);
        if (ch === '\n') {
            line++;
            col = 0;
        } else {
            col++;
        }

        return ch;
    }

    /*
     * Return the next value from the stream without removing it.
     */
    let peek = function() {
        var ch = input.charAt(pos);
        return ch;
    }

    /*
     * Return true if there are no more values to to be read in
     * the stream.
     */
    let eof = function() {
        return peek() === '';
    }

    /*
     * Throw new Error(msg).
     */
    let croak = function(msg) {
        throw new Error(msg + ' (' + line + ':' + col + ')');
    }

    return Object.freeze({
        next: next,
        peek: peek,
        eof: eof,
        croak: croak
    });
}