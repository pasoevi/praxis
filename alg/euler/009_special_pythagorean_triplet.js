let a, b, c;

for (c = 3; c < (1000 - 3) / 2; c++) {
    for (b = 1; b < c; b++) {
        for (a = 1; a < b; a++) {
            if (a + b + c === 1000 && a * a + b * b === c * c) {
                console.log(`a = ${a}, b = ${b}, c = ${c} abc = ${a * b * c}`);
            }
        }
    }
}
