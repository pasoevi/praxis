const isPrime = num => {
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

for (let i = 1; i <= 10001; i++) {
  console.log(gen.next().value);
}

