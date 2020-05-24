/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function (s) {
    const frequencies = {};
    for (let c of s) {
        if (frequencies[c] === undefined) {
            frequencies[c] = 1;
        } else {
            frequencies[c] += 1;
        }
    }

    let strArray = s.split("");
    strArray.sort((a, b) => {
        if (frequencies[b] === frequencies[a]) {
            return s.indexOf(a) - s.indexOf(b);
        } else {
            return frequencies[b] - frequencies[a];
        }
    });
    return strArray.join("");
};
