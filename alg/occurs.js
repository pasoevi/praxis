/*
Write a function that takes two arrays. For every element in the second array,
return the number of times this element occurs in the first array
*/

array1 = ['Mara', 'Tom', 'Martin', 'Donald', 'Tom'];
array2 = ['Martin', 'Tom', 'Steven'];

function compare(array1, array2) {
	array2.forEach(function(item) {
    // How many times do we have "item" in array1
		const numberOfTimes = array1.filter(function (x) { return x === item}).length;
    console.log(numberOfTimes);
	});
};

compare(array1, array2);

// FIRST: PROBLEM

// clear the screen for testing
document.body.innerHTML = '';
document.body.style.background="white";

var nums = [1,2,3];

// Let's loop over the numbers in our array
for (var i = 0; i < nums.length; i++) {

    // This is the number we're on...
    var num = nums[i];

    // We're creating a DOM element for the number
    var elem = document.createElement('div');
    elem.textContent = num;

    // ... and when we click, alert the value of `num`
    elem.addEventListener('click', function() {
        alert(num);
    });

    // finally, let's add this element to the document
    document.body.appendChild(elem);
};

// SECOND: SOLUTION

// clear the screen for testing
document.body.innerHTML = '';

var nums = [1,2,3];

// Let's loop over the numbers in our array
for (var i = 0; i < nums.length; i++) {

    // This is the number we're on...
    var num = nums[i];

    // We're creating a DOM element for the number
    var elem = document.createElement('div');
    elem.textContent = num;

    // ... and when we click, alert the value of `num`
    elem.addEventListener('click', (function(numCopy) {
        return function() {
            alert(numCopy);
        };
    })(num));

    document.body.appendChild(elem);
};

// Third: SOLUTION

// clear the screen for testing
document.body.innerHTML = '';

const nums = [1,2,3];

// Let's loop over the numbers in our array
for (let i = 0; i < nums.length; i++) {

    // This is the number we're on...
    let num = nums[i];

    // We're creating a DOM element for the number
    let elem = document.createElement('div');
    elem.textContent = num;

    // ... and when we click, alert the value of `num`
    elem.addEventListener('click', () => alert(num));
    document.body.appendChild(elem);
};

/* Arrays

Given: [1, 2, 3, 4]
Return [1, 4, 9, 16]
*/


/*
Given [4, -5, 1, 9, 10, -23]
Return [4, 1, 9, 10]
*/

let result;

function takeAwayNegative(array) {
	result = array.filter(function(number) {
		return number >= 0;
	});

	return result;
}

console.log(result);

takeAwayNegative(array);

let array = [4, -5, 1, 9, 10, -23];

function calculateSquares(array) {
	let arrayCopy = []; // here
	/*array.forEach(function (element) {
		arrayCopy.push(element * element);
		//console.log(arrayCopy);
	}); */
	// for (i= 0; i< array.length; i++) {
	// 	arrayCopy.push(array[i] * array[i]);
	// }
	let i = 0;
	while (i < array.length) {
		arrayCopy.push(array[i] * array[i]);
		i++;
	}
	return arrayCopy;
}

console.log(calculateSquares(array));

/* Uncaught TypeError: Cannot set property '0' of undefined
    at repl:4:20
    at Array.forEach (<anonymous>)
    at calculateSquares (repl:2:15)

		*/


console.log(calculateSquares([1, 2, 3, 4, 5, 6]))

console.log("Hello")


///

L1 MOVE_BYTE (R2), (R1)
		ADD #1, R1
		ADD #1, R2
		BRANCH_IF_NOT_EQUAL L1
}
		POP R2
		POP R1
		RETURN_FROM_SUBROUTINE

///
