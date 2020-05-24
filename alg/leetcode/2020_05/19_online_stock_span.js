var StockSpanner = function () {
    this.prices = [];
    this.maxPricesAtPoint = [];
};

/**
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function (price) {
    let span = 1;
    let lastPrice = this.prices[this.prices.length - 1];
    let i = this.prices.length - 1;
    while (i >= 0 && this.prices[i] <= price) {
        span++;
        i--;
    }
    this.prices.push(price);
    return span;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
