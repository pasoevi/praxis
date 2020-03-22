fs = require('fs');
import { inputStream } from './src/istream';

function test(programText) {
    let istream = inputStream(programText);
    console.log(istream.next());
}

fs.readFile('example.spc', 'utf8', function(err, data) {
    if (err) {
        return console.log(err);
    }
    console.log(data);
    test(data);
});