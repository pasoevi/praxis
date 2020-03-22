function removeBulb(array, item) {
    const index = array.indexOf(item);
    if (index !== -1) {
        array.splice(index, 1);
    }
}

function solution(A) {
    const extraBulbs = [];
    for (let i = 0; i < A.length; i++) {
        if (A[i] > i + 1) {
            extraBulbs.push(A[i])
        }
    }



    console.log(extraBulbs);
    // write your code in JavaScript (Node.js 8.9.4)
}

const example = [2, 1, 3, 5, 4];
console.log(example);
console.log(solution(example));
