var moveZeros = function(arr) {
    let zeroesRemoved = 0;
    arr.forEach(function(el, i) {
        if (el === 0) {
            arr.splice(i, 1);
            zeroesRemoved += 1;
        }
    });
    while (zeroesRemoved > 0) {
        arr.push(0);
        zeroesRemoved -= 1;
    }

    return arr;
}

console.log(moveZeros([1, 2, 0, 1, 0, 1, 0, 3, 0, 1]));