/**
 * Given the head of a singly linked list, return true if it is a palindrome.
 * @param {ListNode} head
 * @return {boolean}
 */


var isPalindrome = function(head) {
    let current = head;
    let arr = new Array();

    while (current !== null) {
        arr.push(current.val);
        current = current.next;
    }
    
    let [start, end] = [0, arr.length - 1];
    while (start < end) {
        if (arr[start] !== arr[end]) return false;
        start++;
        end--;
    }
    return true;
}

function ListNode(val,next) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
}


// // test 1
// const a = new ListNode(1);
// const b = new ListNode(2);
// const c = new ListNode(2);
// const d = new ListNode(1);

// a.next = b;
// b.next = c;
// c.next = d;

// console.log(isPalindrome(a));

// test 2
const a = new ListNode(1);
// const b = new ListNode(2);

// a.next = b;

console.log(isPalindrome(a));


