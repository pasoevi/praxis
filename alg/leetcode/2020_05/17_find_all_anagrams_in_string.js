/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
    let result = [];

    if (s.length === 0) {
        return result;
    }

    const patternCharFrequencies = {};
    for (let c of "abcdefghijklmnopqrstuvwxyz") {
        patternCharFrequencies[c] = 0;
    }
    for (let c of p) {
        patternCharFrequencies[c] += 1;
    }

    let low = 0;
    let high = 0;
    let charsToPop = p.length;

    while (high < s.length) {
        if (patternCharFrequencies[s[high++]]-- > 0) {
            charsToPop--;
        }

        if (charsToPop === 0) {
            result.push(low);
        }
        if (
            high - low === p.length &&
            patternCharFrequencies[s[low++]]++ >= 0
        ) {
            charsToPop++;
        }
    }

    return result;
};
