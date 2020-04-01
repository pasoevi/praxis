/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

function gcd(a, b) {
    if (!b) {
        return a;
    }

    return gcd(b, a % b);
}

// 3/5 -> 3/5
// 3/6 -> 1/2
function normalize(rational) {
    const gcdAB = gcd(rational[0], rational[1]);
    return rational.map((x) => x / gcdAB);
}

function mediant(a, b) {
    return normalize([a[0] + b[0], a[1] + b[1]]);
}

function solveLR(str) {
    const path = str.split("");
    let current = [1, 1];
    let leftParent = [0, 1];
    let rightParent = [1, 0];
    for (let branch of path) {
        if (branch === "L") {
            const newBranch = mediant(current, leftParent);
            rightParent = current;
            current = newBranch;
        } else if (branch === "R") {
            const newBranch = mediant(current, rightParent);
            leftParent = current;
            current = newBranch;
        }
    }
    return current;
}

function value(rational) {
    return rational[0] / rational[1];
}

function solveRational(target) {

    let current = [1, 1];
    console.log(target);
    console.log(current);
    console.log(`${current[0]} !== ${target[0]} && ${current[1]} !== ${target[1]}`);

    let left = [0, 1];
    let right = [1, 0];
    const path = [];
    while ((current[0] !== target[0]) || (current[1] !== target[1])) {
        current = mediant(left, right);

        if (value(current) < value(target)) {
            left = current;
            path.push("R");
        } else {
            right = current;
            path.push("L");
        }
    }
    return path.join("");
}

let data =[
    1,
    "1/50",
]

var j = 0;

function readline() {
    return data[j++];
}

const N = parseInt(readline());

for (let i = 0; i < N; i++) {
    const line = readline();
    if (line.includes("/")) {
        console.log(solveRational(line.split("/").map((x) => parseInt(x))));
    } else {
        console.log(solveLR(line).join("/"));
    }
}
