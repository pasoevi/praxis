let s = 1000, a, b, c;

for (a = 3; a < a <= (s - 3) / 3; a++) {
    for (b = a + 1; b < s - a - 1; b++) {
        c = s - b - a;
        if (c * c === a * a + b * b) {
           console.log(`a = ${a}, b = ${b}, c = ${c} abc = ${a * b * c}`);
            process.exit()
        }
    }
}
