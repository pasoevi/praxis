import inputStream from '../src/istream';

QUnit.test("hello test", function(assert) {
    let istream = inputStream('sergi');
    assert.ok(istream.next() === "s", "Passed!");
});