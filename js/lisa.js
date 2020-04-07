// Add a log method to Array
function log(...args) {
    console.log(`Log: ${args.join(",")}`);
}

Array.prototype.log = function () {
    log(this);
};

const arr = [1, 2, 3, 4, 5];
arr.log();

// What is this here

const foo = () => {
    console.log(this);
}

function bar() {
    console.log(this);
}

const baz = function () {
    console.log(this);
}

// Function inside an object
const obj = {
    x: 5,
    objMethod: function () {
        console.log(this);
        console.log(this.x);
    },
    bar: bar
}

console.log("------------ FOO --------------")
foo();
console.log("------------ BAR --------------")
// bar();
console.log("------------ BAZ --------------")
// baz();
console.log("------------ OBJECT METHOD --------------")
obj.objMethod();
obj.bar();

/* Wednesday */

let yogurt = "Greek";
joke = new Promise(resolve, reject) {
  setTimeout(function () {
    reslove(4);
  })
}

// Http requrest example
const httpRequest = new XMLHttpRequest();
httpRequest.responseType = "json";
httpRequest.onload = function() {

  if (httpRequest.readyState === XMLHttpRequest.DONE) {
      if (httpRequest.status === 200) {
        const result = httpRequest.response;
        alert(result.name);
      }
    }
}
const url = "https://the-one-api.herokuapp.com/v1/book/5cf58077b53e011a64671583"
httpRequest.open("GET", url, true);
httpRequest.send();


// Http requrest example using a Promise
const url = "https://the-one-api.herokuapp.com/v1/book/5cf58077b53e011a64671583";
const bookPromise = fetch(url);
// somewhere else:
bookPromise.then(response => response.json()).then(data => {
  alert(data.name)
})


// Given a non-empty array of integers, every element appears twice except
// for one. Find that single one.

array = [0, 2, 4, 6, 8, 6, 4, 2, 0 ];
array = [0, 0, 2, 2, 4, 4, 6, 6, 8];

function findTheOne() {
	for (number of array) {
		const check = number;
		let checkTwo = 0;
		for (compare of array) {
			if (compare == check) {
				checkTwo++;
			}
		}
		if (checkTwo == 1) {
			return number;
		}
	}
}

findTheOne();
// Linear growth:
// 2 -> 2
// 4 -> 4
// 5 -> 5

// Exponential growth:
// 2 -> pow(2, 2) = 4
// 4 -> pow(2, 4) = 32
// 5 -> pow(2, 5) = 64
// 6 -> pow(2, 6) = 128
// 7 -> pow(2, 6) = 256
// 8 -> pow(2, 6) = 512

// Quadratic:
// 2 -> 2 * 2 = 4
// 4 -> 4 * 4 = 16
// 5 -> 5 * 5 = 25
// 6 -> 6 * 6 = 32
// 7 -> 7 * 7 = 49
//


// Factorial
4! = 1 * 2 * 3 * 4 
