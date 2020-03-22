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