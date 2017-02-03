function sum(arr) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return 0;
    }
    return arr.reduce(function (a, b) { return a + b;});
}

function findEvenIndex(arr)
{
    let evenIndex = -1;
    
    for (var i = 0; i < arr.length; i += 1) {
        if (sum(arr.slice(0, i)) === sum(arr.slice(i))) {
            return i + 1;
        }
    }
    
    return evenIndex;
}

var lst = [1,2,3,4,3,2,1];
var lst2 = [1,100,50,-51,1,1];
var lst3 = [1,2,3,4,5,6];
var lst4 = [20,10,30,10,10,15,35];

console.log(sum(lst));
