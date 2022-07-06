/**
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 * Implement the MovingAverage class:
 *      - MovingAverage(int size) Initializes the object with the size of the window size.
 *      - double next(int val) Returns the moving average of the last size values of the stream.
 * @param {number} size
 */

var MovingAverage = function(size) {
    this.size = size;
    this.arr = [];
};


/**
 * @param {number} val
 * @return {number}
 */

MovingAverage.prototype.next = function(val) {
    let arr = this.arr;
    let size = this.size;

    arr.push(val);
    let n = arr.length;
    let running_sum = 0;
    let i = n <= size ? 0 : n - size;

    for (i; i < n; i++) {
        running_sum += arr[i];
    }


    return n <= size ? running_sum / n : running_sum / size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */
