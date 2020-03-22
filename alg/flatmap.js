function flatPrint(arr) {
    return flat(arr).join(".");
}

function flat(arr) {
    console.log(arr);
    if (arr.length === 0) {
        return [];
    }
    const [ first, ...rest ] = arr;
    if (Array.isArray(first)) {
        return flat ? [...flat(first), flat(rest)] : [first];
    }

    return rest ? [first, ...flat(rest)] : [first];
}

const example = [1, 4, [7, 8, 10], 12];

console.log(flatPrint(example));