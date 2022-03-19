/* 
  Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds 
  (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

  All messages will come in chronological order. Several messages may arrive at the same timestamp.

  Implement the Logger class:

  Logger() Initializes the logger object.
  bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
*/

var Logger = function(){
    this.logger = new Object();
}
/** 
* @param {number} timestamp 
* @param {string} message
* @return {boolean}
*/

Logger.prototype.shouldPrintMessage = function(timestamp, message) {
  // Case 1: we have never seen the message before
  if (!(message in this.logger)) {
    this.logger[message] = timestamp;
    console.log(this.logger[message]);
    return true;
  }
  // Case 2: we have seen the message before
  // make sure previous timestamp + 10 is greater than the current
  if (timestamp >= this.logger[message] + 10) {
    this.logger[message] = timestamp
    return true;
  }
  return false
};
