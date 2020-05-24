/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function (s1, s2) {
    if (s1.length === 0) {
        return true;
    }

    if (s2.length === 0) {
        return false;
    }

    const s1Frequencies = {};
    const s2Frequencies = {};

    for (let c of "abcdefghijklmnopqrstuvwxyz") {
        s1Frequencies[c] = 0;
        s2Frequencies[c] = 0;
    }

    for (let c of s1) {
        s1Frequencies[c]++;
    }

    for (let i = 0; i < s2.length; i++) {
        if (i >= s1.length) {
            s2Frequencies[s2[i - s1.length]] -= 1;
        }
        s2Frequencies[s2[i]] += 1;
        if (JSON.stringify(s1Frequencies) === JSON.stringify(s2Frequencies)) {
            return true;
        }
    }

    return false;
};
