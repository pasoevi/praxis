function quicksort(array, start, end) {
    if (start < end) {
        const pivot = partition(array, start, end);
        quicksort(array, start, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

function partition(array, start, end) {
    let pivot = Math.floor((start + end) / 2);
    let i = start - 1;
    let j = start;
    wihle (j < pivot) {

    }
}

function swap(array, firstIndex, secondIndex) {
    const temp = array[firstIndex];
    array[firstIndex] = array[secondIndex]
    array[secondIndex] = temp;
}


const example = [2, 8, 1, 7, 23, 3];
console.log(example);
quicksort(example, 0, example.length - 1);
console.log(example);