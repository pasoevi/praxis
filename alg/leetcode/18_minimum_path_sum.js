/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    let solutions = new Array(grid.length);
    for (let i = 0; i < grid.length; i++) {
        solutions[i] = new Array(grid[0].length);
    }

    for (let i = 0; i < solutions.length; i++) {
        for (let j = 0; j < solutions[0].length; j++) {
            solutions[i][j] = grid[i][j];
            if (i > 0 && j > 0) {
                solutions[i][j] += Math.min(
                    solutions[i - 1][j],
                    solutions[i][j - 1],
                );
            } else if (i > 0) {
                solutions[i][j] += solutions[i - 1][j];
            } else if (j > 0) {
                solutions[i][j] += solutions[i][j - 1];
            }
        }
    }

    return solutions[solutions.length - 1][solutions[0].length - 1];
};
