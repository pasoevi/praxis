import { inputStream } from "./istream";
import { tokenStream } from "./tstream";
import { parse } from "./parser";

test("", () => {
    let istream = inputStream('lambda (x) 10');
    let tstream = tokenStream(istream);

    expect(istream.peek()).toEqual("l");
    let parsed = parse(tstream);
    console.log(JSON.stringify(parsed));
});