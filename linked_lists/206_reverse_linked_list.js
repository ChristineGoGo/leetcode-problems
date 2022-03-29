// create a singly linked list
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val);
    this.next = (next===undefined ? null : next);
}

/**
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * @param {ListNode} head
 * @return {ListNode}
*/
let reverseList = function(head) {
    let prev_node = null;
    let curr_node = head;

    while (curr_node != null) {
        next_node = curr_node.next;
        curr_node.next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}
/**
 * Return the contents of a linked list in an array
 * @param {ListNode} head
 * @return {Array}
*/
let printList = function (head) {
    let curr_node = head;
    let linkedList = [];

    while (curr_node) {
        linkedList.push(curr_node.val);
        curr_node = curr_node.next;
    }
    return linkedList;
}

// //Test 1
// let a = new ListNode(1);
// let b = new ListNode(2);
// let c = new ListNode(3);
// let d = new ListNode(4);
// let e = new ListNode(5);

// a.next = b;
// b.next = c;
// c.next = d;
// d.next = e;

// // Test 2
// let a = new ListNode(1);
// let b = new ListNode(2);

// a.next = b;

// Test 3
// head = empty

let result = reverseList();
console.log(printList(result));
