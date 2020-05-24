/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {
    const availableLetters = {};
    for (let c of magazine) {
        if (availableLetters[c] === undefined) {
            availableLetters[c] = 1;
        } else {
            availableLetters[c] += 1;
        }
    }

    for (let c of ransomNote) {
        if (availableLetters[c] !== undefined && availableLetters[c] > 0) {
            availableLetters[c] -= 1;
        } else {
            return false;
        }
    }

    return true;
};
