/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function (coordinates) {
    if (coordinates.length === 2) {
        return true;
    }

    const firstCrossProduct = crossProduct(coordinates[0], coordinates[1]);
    let isStraightLine = true;
    for (let i = 2; i < coordinates.length; i++) {
        if (
            crossProduct(coordinates[i - 1], coordinates[i]) !==
            firstCrossProduct
        ) {
            isStraightLine = false;
        }
    }

    return isStraightLine;
};

function crossProduct(a, b) {
    return (b[1] - a[1]) / (b[0] - a[0]);
}
