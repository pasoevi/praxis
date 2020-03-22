function range(start, count) {
    return Array.apply(0, Array(count))
        .map(function (element, index) {
            return index + start;
        });
}

let nums = range(1, 100);
let sumOfSquares = nums.reduce(function (sum, value) {
    return sum + value * value;
}, 0);

let sum = nums.reduce(function (sum, value) {
    return sum + value;
}, 0);

let difference = sum * sum - sumOfSquares;