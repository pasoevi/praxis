'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function hourglassSum(hourglass) {
    let sum = 0;
    const top = hourglass[0].reduce((x, accum) => x + accum, 0)
    const mid = hourglass[1]
    const bot = hourglass[2].reduce((x, accum) => x + accum, 0)
    
}

// Complete the array2D function below.
function array2D(arr) {
    

}

function main() {
    let arr = Array(6);

    for (let i = 0; i < 6; i++) {
        arr[i] = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));
    }

    console.log(arr)
    let result = array2D(arr);
    console.log(result)
}
