import { inputStream } from "./istream";
import { tokenStream } from "./tstream";

test("tokenStream", () => {
    let istream = inputStream('123');
    let tstream = tokenStream(istream);

    expect(istream.peek()).toEqual("1");

    const token = tstream.next();
    expect(token.type).toEqual("num"); //, "type: number");
    expect(token.value).toEqual(123); // "value: number");
});