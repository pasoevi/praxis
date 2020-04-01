const fs = require('fs');

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

function readline() {
    fs.readFile("farmer_input.txt", function(err, buffer) {
        if (err) {
            return callback(err.message);
        }

        callback(null, toArrayBuffer(buffer));
    });
}

const L = parseInt(readline());
const N = parseInt(readline());

const wall = []

for (let i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    const st = parseInt(inputs[0]);
    const ed = parseInt(inputs[1]);
    wall.push({
        start: st,
        end: ed
    });
}

wall.sort((a, b) => a.start - b.start);

for (let [index, segment] of wall) {

}


// Write an action using console.log()
// To debug: console.error('Debug messages...');

console.log('answer');