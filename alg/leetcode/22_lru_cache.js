/* function Queue() {
    this.store = [];
}

Queue.prototype.enqueue = function (value) {
    if (this.store === undefined) {
        this.store = [];
    }
    this.store.splice(0, 0, value);
}

Queue.prototype.dequeue = function () {
    if (this.store === undefined) {
        this.store = [];
        return;
    }
    const removedElement = this.store.splice(0, 1);
    return removedElement.length > 0 ? removedElement[0]: undefined;
} */

/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    this.store = new Map();
    this.maxCapacity = capacity;
};

LRUCache.prototype.refresh = function (key, value) {
    if (this.store.has(key)) {
        this.store.delete(key);
        this.store.set(key, value);
    }
}

LRUCache.prototype.getLRUKey = function () {
    return this.store.keys().next().value;
}

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
    const value = this.store.get(key);
    this.refresh(key, value);
    return value !== undefined ? value : -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
    if (this.store.has(key)) {
        this.store.delete(key);
    } else if (this.store.size === this.maxCapacity) {
        this.store.delete(this.getLRUKey());
    }
    this.store.set(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
