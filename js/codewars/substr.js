function inArray(array1,array2){
    return array1.filter(function (substr) {
        return array2.filter(function (str) {
            return str.includes(substr);
        }).length > 0;
    }).sort();
}


function inArray(array1,array2){
    return array1.filter(substr => array2.filter(str => str.includes(substr)).length > 0).sort();
}
