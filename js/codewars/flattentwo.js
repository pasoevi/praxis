function flatten(arr) {
    if (arr === undefined) {
        return undefined;
    }
    
    if (arr.length === 0) {
        return arr;
    }
    
    if (arr.length === 1) {
        if (!arr[0].isArray()) {
            return arr[0];
        } else {
            flatten(arr[0]);
        }
    }
    
    return arr.map(elem => flatten(elem)); 
}


function flattenTwoLevels(array) {
    array.forEach(elem => elem.map(flatten));
}
