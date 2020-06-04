/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function (word1, word2) {
    return minDistanceDP(word1, word2, word1.length, word2.length);
};

function minDistanceDP(word1, word2, m, n) {
    console.log(`m: ${m}, n: ${n}`);
    if (m === 0) {
        return n;
    }

    if (n === 0) {
        return m;
    }

    if (word1[m - 1] === word2[n - 1]) {
        return minDistanceDP(word1, word2, m - 1, n - 1);
    }

    return (
        1 +
        Math.min(
            minDistanceDP(word1, word2, m, n - 1),
            minDistanceDP(word1, word2, m - 1, n),
            minDistanceDP(word1, word2, m - 1, n - 1),
        )
    );
}

console.log(minDistance("dinitrophenylhydrazine", "benzalphenylhydrazone"));