/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

function sumDigitSquares(numString) {
    return numString
        .split("")
        .map((x) => parseInt(x) * parseInt(x))
        .reduce((a, b) => a + b, 0);
}

function isHappy(numString) {
    let a = parseInt(numString); // sumDigitSquares(numString);
    let i = 0;
    while (a !== 1) {
        a = sumDigitSquares(a.toString());
        if (i > 1000) {
            return false;
        }
        i++;
    }
    return true;
}

const N = parseInt(readline());
for (let i = 0; i < N; i++) {
    const x = readline();
    if (isHappy(x)) {
        console.log(`${x} :)`);
    } else {
        console.log(`${x} :(`);
    }
}

console.log("23 :)");
