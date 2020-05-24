/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
    return parseInt(
        num
            .toString(2)
            .replace(/^0+/, "")
            .split("")
            .map((x) => (x === "1" ? "0" : "1"))
            .join(""),
        2,
    );
};
