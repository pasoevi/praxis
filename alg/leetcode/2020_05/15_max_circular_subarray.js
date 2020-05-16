/**
 * @param {number[]} A
 * @return {number}
 */
var maxSubarraySumCircular = function (A) {
    const allNegative = A.filter((x) => x < 0).length === A.length;

    if (allNegative) {
        let largest = A[0];
        for (let i = 1; i < A.length; i++) {
            if (A[i] > largest) {
                largest = A[i];
            }
        }
        return largest;
    }

    const maxInTheMiddle = maxSubArraySum(A);

    let masSplitAcross = 0;
    for (let i = 0; i < A.length; i++) {
        masSplitAcross += A[i];
        A[i] = -A[i];
    }

    masSplitAcross += maxSubArraySum(A);

    return Math.max(maxInTheMiddle, masSplitAcross);
};

function maxSubArraySum(A) {
    let maxSubArraySumSoFar;
    let maxSubArrayEndingHere;

    for (let i = 0; i < A.length; i++) {
        if (maxSubArrayEndingHere === undefined) {
            maxSubArrayEndingHere = A[i];
        } else {
            maxSubArrayEndingHere += A[i];
        }

        if (maxSubArrayEndingHere < 0) {
            maxSubArrayEndingHere = 0;
        }
        if (
            maxSubArraySumSoFar === undefined ||
            maxSubArrayEndingHere > maxSubArraySumSoFar
        ) {
            maxSubArraySumSoFar = maxSubArrayEndingHere;
        }
    }
    return maxSubArraySumSoFar;
}
