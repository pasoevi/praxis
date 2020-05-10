function contiguousArray(array) {
    let longestSoFar = 0;
    for (let i = 0; i < array.length; i++) {
        let longestEndingHere = 0;
        let balance = 0;
        let j = i;
        while (j >= 0) {
            balance += array[j] === 1 ? 1 : -1;
            if (balance === 0) {
                longestEndingHere = i - j;
                console.log(`j: ${j}, i: ${i}, ${array.slice(j, i + 1)}`)
            }
            j--;
        }
        if (longestEndingHere > longestSoFar) {
            longestSoFar = longestEndingHere;
        }
    }

    return longestSoFar;
}

function contiguousArrayHash(nums) {
    const counts = {};
    counts[0] = -1;
    let maxlen = 0;
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        count = count + (nums[i] == 1 ? 1 : -1);
        if (counts[count] !== undefined) {
            maxlen = Math.max(maxlen, i - counts[count]);
        } else {
            counts[count] = i;
        }
    }
    return maxlen;
}

// console.log(contiguousArray([0, 1]));
// console.log(contiguousArray([0, 1, 0]));
console.log(contiguousArrayHash([0, 0, 1, 0, 1, 1, 0, 1, 1, 0]));