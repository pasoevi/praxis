/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function (J, S) {
    return S.split("").filter((x) => J.includes(x)).length;
};
