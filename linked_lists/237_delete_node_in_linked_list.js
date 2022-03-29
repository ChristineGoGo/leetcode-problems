/**
 * 
 * Write a function to delete a node in a singly-linked list.
 * You will not be given access to the head of the list, 
 * instead you will be given access to the node to be deleted directly.
 * It is guaranteed that the node to be deleted is not a tail node in the list.
 * 
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
 var deleteNode = function(node) {
    node.val = node.next.val;
    node.next = node.next.next;
};

var printNodes = function(node) {
    let curr = node;
    let result = [];
    while (curr) {
        result.push((curr.val));
        curr = curr.next;
    }
    return result;
}


a = new ListNode('4');
b = new ListNode('5');
c = new ListNode('1');
d = new ListNode('9');
e = new ListNode('7');
f = new ListNode('6');
g = new ListNode('7');

a.next = b;
b.next = c;
c.next = d;
d.next = e;
e.next = f;
f.next = g;

deleteNode(e);
console.log(printNodes(a));
