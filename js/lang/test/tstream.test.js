import { inputStream } from "../src/istream";
import { tokenStream } from "../src/tstream";

QUnit.test("hello test", function(assert) {
    let istream = inputStream('123');
    let tstream = tokenStream(istream);

    assert.ok(istream.peek() === "1", "character stream");

    const token = tstream.next();
    assert.equal(token.type, "num", "type: number");
    assert.equal(token.value, 123, "value: number");
});