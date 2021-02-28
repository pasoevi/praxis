function fibMemoized(n, memo) {
  memo = memo || {};

  if (n === 0 || n === 1) {
    return n;
  }

  if (memo[n] !== undefined) {
    return memo[n];
  }// autocrlf = true

  memo[n] = fibMemoized(n-2, memo) + fibMemoized(n-1, memo);
  return memo[n];
}
const n = 10;
console.log(`Fib for ${n} is ${fibMemoized(n)}`);
