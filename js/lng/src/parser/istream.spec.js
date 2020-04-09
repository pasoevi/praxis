import { inputStream } from "./istream";

test("reads character from stdin", () => {
    let istream = inputStream("sergi");
    expect(istream.next()).toEqual("s");
});
