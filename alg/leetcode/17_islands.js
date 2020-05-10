function findAllNeighbors(row, col, grid) {
    const neighbors = [];
    const rowLimit = grid.length;
    if (rowLimit <= 0) {
        return neighbors;
    }
    for (let x = Math.max(0, row - 1); x <= Math.min(row + 1, rowLimit); x++) {
        const columnLimit = grid[0].length;
        for (
            let y = Math.max(0, col - 1);
            y <= Math.min(col + 1, columnLimit);
            y++
        ) {
            if ((x != row || y != col) && grid[x][y] === "1") {
                neighbors.push([x, y]);
            }
        }
    }
    return neighbors;
}

function findNeighbors(row, col, grid) {
    const neighbors = [];
    const left = Math.max(0, col - 1);
    const right = Math.min(col + 1, grid[0].length - 1);
    const top = Math.max(0, row - 1);
    const bottom = Math.min(row + 1, grid.length - 1);

    if (left !== col && grid[row][left] === "1") {
        neighbors.push([row, left]);
    }
    if (right !== col && grid[row][right] === "1") {
        neighbors.push([row, right]);
    }
    if (top !== row && grid[top][col] === "1") {
        neighbors.push([top, col]);
    }
    if (bottom !== row && grid[bottom][col] === "1") {
        neighbors.push([bottom, col]);
    }

    return neighbors;
}

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
    const board = [];
    for (let row of grid) {
        const line = [];
        for (let col of row) {
            line.push(col);
        }
        board.push(row);
    }

    let islandCount = 0;
    for (let row = 0; row < board.length; row++) {
        for (let col = 0; col < board[row].length; col++) {
            if (board[row][col] === "1") {
                const neighbors = findNeighbors(row, col, board);
                let i = 0;
                while (i < neighbors.length) {
                    const [r, c] = neighbors[i];
                    if (board[r][c] === "1") {
                        const newNeighbors = findNeighbors(r, c, board);
                        board[r][c] = "0";
                        neighbors.push(...newNeighbors);
                    }
                    i++;
                }
                board[row][col] = "0";
                islandCount++;
            }
        }
    }

    return islandCount;
};
