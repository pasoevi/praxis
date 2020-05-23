/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function (matrix) {
    let result = 0;
    const rowCount = matrix.length;

    if (rowCount < 1) {
        return 0;
    }
    const columnCount = matrix[0].length;
    const maxSubMatrixSize = Math.min(columnCount, rowCount);

    for (
        let subMatrixSize = 1;
        subMatrixSize <= maxSubMatrixSize;
        subMatrixSize++
    ) {
        for (let top = 0; top + subMatrixSize <= rowCount; top++) {
            for (let left = 0; left + subMatrixSize <= columnCount; left++) {
                let allOnes = true;
                for (let row = top; row < top + subMatrixSize; row++) {
                    for (
                        let column = left;
                        column < left + subMatrixSize;
                        column++
                    ) {
                        if (matrix[row][column] !== 1) {
                            allOnes = false;
                        }
                    }
                }
                if (allOnes) {
                    result++;
                }
            }
        }
    }

    return result;
};
