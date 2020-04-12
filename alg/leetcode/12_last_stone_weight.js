function lastWeight(array) {
    let stones = array.slice();
    while (stones.length > 1) {
        stones.sort((a, b) => b - a);
        console.log(stones);
        let first = stones[1];
        let second = stones[0];
        if (first === second) {
            stones.splice(0, 2);
        } else {
            stones.splice(0, 1);
            stones[0] = second - first;
        }
    }

    return stones.length === 0 ? 0 : stones[0];
}

console.log(lastWeight([2, 7, 4, 1, 8, 1]));