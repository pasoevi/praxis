let divisors = [7, 8, 11, 12, 13, 14, 15, 16]
console.log(divisors.length);
let n = 0;

const maxNum = divisors.reduce(function (product, value) {
  return product * value;
}, 1);

function divisibleBy(number, factor) {
  if (number % factor === 0){ 
    return true;
  }
  return false;
}

function* numGen() {
  let n = 1;
  while (true) {
    if (divisibleBy(n, 20) && divisibleBy(n, 19) && divisibleBy(n, 18) && divisibleBy(n, 17)) {
      yield n;      
    }
    n++;
  }
}

let gen = numGen();
let smallestNum = -1;
n = gen.next().value;

while (smallestNum < 0) {
  // Check if n is divisible by all numbers in 'divisors'
  const goodDivisors = divisors.filter(div => n % div === 0);
  // console.log(`Good divisors: ${goodDivisors.length}/${divisors.length}`);
  if (goodDivisors.length > divisors.length - 2) {
    console.log(`Divisible by: ${goodDivisors}`);
  }

  if (goodDivisors.length === divisors.length) {
    smallestNum = n;
  }
  n = gen.next().value;
}

console.log(smallestNum);