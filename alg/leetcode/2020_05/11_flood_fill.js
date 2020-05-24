/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function (image, sr, sc, newColor) {
    const targetColor = image[sr][sc];
    if (targetColor === newColor) {
        return image;
    }

    image[sr][sc] = newColor;

    if (sr + 1 < image.length && image[sr + 1][sc] === targetColor) {
        floodFill(image, sr + 1, sc, newColor);
    }
    if (sr - 1 >= 0 && image[sr - 1][sc] === targetColor) {
        floodFill(image, sr - 1, sc, newColor);
    }

    if (sc + 1 < image[0].length && image[sr][sc + 1] === targetColor) {
        floodFill(image, sr, sc + 1, newColor);
    }

    if (sc - 1 >= 0 && image[sr][sc - 1] === targetColor) {
        floodFill(image, sr, sc - 1, newColor);
    }

    return image;
};
