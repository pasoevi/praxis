// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    if (A.length < 2) {
        return 0;
    }

    A.sort((a, b) => a - b);
    let lastListLength = A[0];
    const sortTimes = []
    for (let i = 1; i < A.length; i++) {
        lastListLength += A[i];
        sortTimes.push(lastListLength);
    }
    const sortTimeMS = sortTimes.reduce((result, currentList) => {
        return result + currentList;
    }, 0)
    return sortTimeMS;
}

const example = [100, 250, 1000];
console.log(solution(example));