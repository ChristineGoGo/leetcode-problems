/**
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 */

// Create a list node
// function ListNode(val,next) {
//     this.val = (val===undefined ? 0 : val);
//     this.next = (next===undefined ? null : next); 
// }

// create a ListNode class
class ListNode {
    val;
    next;

    constructor(val, next) {
        this.val = (val===undefined ? 0 : val);
        this.next = (next===undefined ? 0 : next);
    }
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 var middleNode = function(head) {
    let arr = [head];
    console.log(arr);
};

// test 1 [1,2,3,4,5]
let a = new ListNode(1);
let b = new ListNode(2);
let c = new ListNode(3);
let d = new ListNode(4);
let e = new ListNode(5);

console.log(a);