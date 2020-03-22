function solution(number) {
    function sumMultiples (n) {
        console.log(`Calculating ${n}`);
        if (n === null || n === 0 || n < 3) {
            return 0;
        }

        if (n % 3 === 0 || n % 5 === 0) {
            console.log(`Adding ${n}`);
            return n + solution(n);
        } else {
            return solution(n);
        }
    }
    
    return sumMultiples(number - 1);
}


console.log(solution(3));
console.log(solution(10));
