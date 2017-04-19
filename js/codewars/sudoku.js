function validFragment(fragment) {
    const digits = [1, 2, 3, 4, 5, 6, 7, 8, 9];

    return fragment.length === 9 && digits.every(el => fragment.includes(el));
}

function validSolution(board) {
    // Validate rows
    if (!board.every(row => validFragment(row))) {
        return false;
    }

    // Validate columns
    let i = 0;
    for (i = 0; i < 9; i += 1) {
        column = [];
        board.forEach(function(row) {
            column.push(row[i]);
        });

        if (!validFragment(column)) {
            return false;
        }
    }

    // Validate squares
    for (i = 0; i < 9; i += 3) {
        let j = 0;
        for (j = 0; j < 9; j += 3) {
            let k = 0;
            let square = [];
            for (k = 0; k < 3; k += 1) {
                let elems = board[i + k].slice(j, j + 3);
                // console.log(`Elems = ${elems}`);
                square.push.apply(square, elems);
            }

            // console.log(`i = ${i}, j = ${j}`);
            // console.log(square);
            if (!validFragment(square)) {
                return false;
            }
        }
    }

    return true;
}

console.log(validSolution([
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9]
]));