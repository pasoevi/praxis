/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit1 = function(prices) {
    let profit = 0;
    let i = 0;
    while (i < prices.length) {
        let max = prices[i];
        let maxIndex = i;
        for (let j = i+1; j < prices.length; j++) {
            if (prices[j] > max) {
                max = prices[j];
                maxIndex = j;
            }
        }
        profit += max - prices[i];
        i = maxIndex;
        if (maxIndex > i) {
            i = maxIndex - 1;
        } else {
            i++;
        }
    }
    return profit;
};

/* console.log(`Actual: ${maxProfit([7, 1, 5, 3, 6, 4])}, Expected: 7`);
console.log(`Actual: ${maxProfit([1, 2, 3, 4, 5])}, Expected: 4`);
console.log(`Actual: ${maxProfit([7, 6, 4, 3, 1])}, Expected: 0`);
 */


 var maxProfit = function (prices) {
     let profit = 0;
     let i = 0;
     for (let i = 1; i < prices.length; i++) {
         if (prices[i] > prices[i-1]) {
             profit += prices[i] - prices[i-1];
         }
     }
     return profit;
 };


console.log(`Actual: ${maxProfit([7, 1, 5, 3, 6, 4])}, Expected: 7`);
console.log(`Actual: ${maxProfit([1, 2, 3, 4, 5])}, Expected: 4`);
console.log(`Actual: ${maxProfit([7, 6, 4, 3, 1])}, Expected: 0`);