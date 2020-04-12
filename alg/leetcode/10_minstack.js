/**
 * initialize your data structure here.
 */
var MinStack = function () {
    this.values = [];
    this.minIndexAtIndex = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
    if (this.minIndexAtIndex.length === 0) {
        this.minIndexAtIndex.push(0);
    } else {
        const currentMinIndex = this.minIndexAtIndex[this.values.length - 1];
        const currentMinValue = this.values[currentMinIndex];
        if (x < currentMinValue) {
            this.minIndexAtIndex.push(this.values.length);
        } else {
            this.minIndexAtIndex.push(
                this.minIndexAtIndex[this.values.length - 1],
            );
        }
    }
    this.values.push(x);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    this.minIndexAtIndex.pop();
    return this.values.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    return this.values[this.values.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    return this.values[this.minIndexAtIndex[this.values.length - 1]];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
