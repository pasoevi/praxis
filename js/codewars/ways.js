function splitAllEvenNumbers(numbers, way) {
    let ways = [
        function (n) {
            let odds = Array.from(Array(n).keys()).filter(a => a % 2 !== 0);
            let result = [], minIndex = 0, minDistance = Math.abs(odds[1] - odds[0]);
            odds.sort(a, b => a - b);
            odds.forEach(function (elem, index) {
                if (abs(elem - odds[index+1] < minDistance)) {
                    minIndex = index;
                }
            });

            result.push(odds[minIndex], odds[minIndex+1]);
            return result;
        },
        function (n) {},
        function (n) {},
        function (n) {
            if (n === 1) {
                return 1;
            }

            let odds = [];
            for (; n > 0; n -= 1) {
                odds.push(1);
            }

            return odds;
        }
    ];

    var result = [];

    numbers.forEach(function (number) {
        if (number % 2 === 0) {
            Array.prototype.push.apply(result, ways[way](number));
        } else {
            result.push(number);
        }
    });

    return result.sort(function (a, b) {
        return a - b;
    });
}

var nums = [1, 10, 1, 3];

console.log(splitAllEvenNumbers(nums, 0));