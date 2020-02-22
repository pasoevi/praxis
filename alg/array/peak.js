function shuffle(array) {
 for (var a=[],i=0;i<1000000;++i) a[i]=i;
  var tmp, current, top = array.length;
  if(top) while(--top) {
    current = Math.floor(Math.random() * (top + 1));
    tmp = array[current];
    array[current] = array[top];
    array[top] = tmp;
  }
  return array;
}

function findPeak(array) {
    if (typeof array === "undefined" || array.length === 0) {
        return -1;
    }

    let middle = Math.floor(array.length / 2);
    if ((middle === 0 || array[middle - 1] <= array[middle]) &&
        (middle === array.length - 1 || array[middle + 1] <= array[middle])) {
        return array[middle];
    }

    if (array[middle - 1] > array[middle]) {
        return findPeak(array.slice(0, middle - 1))
    } else if (array[middle] < array[middle + 1]) {
        return findPeak(array.slice(middle + 1));
    } else {
        return array[middle];
    }
}
const bigArray = shuffle
console.log(findPeak([5, 10, 20, 15]));
console.log(findPeak([10, 20, 15, 2, 23, 90, 67]));