def find_peak(lst) {
    if (typeof array === "undefined" || array.length === 0) {
        return -1;
    }

    if (array.length === 1) {
        return array[0];
    }

    let middle = Math.floor(array.length / 2);
    if (middle === 0) {
        if (array[middle] > [middle + 1]) {
            return array[middle];
        } else {
            return findPeak(array.slice(1));
        }
    }

    if (middle === array.length - 1) {
        if (array[middle] > [middle - 1]) {
            return array[middle];
        } else {
            return findPeak(array.slice(0, -1));
        }
    }

    if (array[middle] < array[middle - 1]) {
        return findPeak(array.slice(0, middle - 1))
    } else if (array[middle] < array[middle + 1]) {
        return findPeak(array.slice(middle + 1));
    } else {
        return array[middle];
    }
}

console.log(findPeak([5, 10, 20, 15]))