function isPrime(num) {
  for(let i = 2, s = Math.sqrt(num); i <= s; i++)
  if(num % i === 0) return false; 
    return num !== 1;
}

function* primes() {
  let i = 2;
  while(true) {
    if (isPrime(i)) {
      yield i;
    }
    i++;
  }
}

const gen = primes();
let maxPrime = 2000000, sum = 0;

for (let p = 0; p <= maxPrime; p = gen.next().value) {
	sum += p;
}

process.stdout.write(sum.toString())

