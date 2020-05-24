/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function (matrix) {
    let dp = matrix;

    let rowCount = matrix.length;
    if (rowCount === 0) {
        return 0;
    }
    let columnCount = matrix[0].length;

    for (let row = 1; row < rowCount; row++) {
        for (let column = 1; column < columnCount; column++) {
            dp[row][column] *=
                Math.min(
                    dp[row - 1][column],
                    dp[row][column - 1],
                    dp[row - 1][column - 1],
                ) + 1;
        }
    }

    let result = 0;
    for (let row = 0; row < rowCount; row++) {
        for (let column = 0; column < columnCount; column++) {
            result += dp[row][column];
        }
    }

    return result;
};
