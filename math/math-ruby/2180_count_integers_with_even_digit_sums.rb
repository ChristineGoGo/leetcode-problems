=begin
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.

 

Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    
Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
 

Constraints:

1 <= num <= 1000

=end
=begin
APPROACH: Loop num number of times. At each iteration convert the number into a string and find the sum.
If the sum is even, add it to the total of even sum digits, otherwise continue with the loop.
=end

#@param {Integer} num
#@return {Integer}
def count_even(num)
    total = 0
    evens = 0
    current = String(num)
    tracker = num

    num.times do
        current = String(tracker)
        n = current.length
        total = 0
        n.times do |i|
            total += Integer(current[i])
        end
        if total % 2 == 0
            evens += 1
        end
        tracker -= 1
    
    end
    return evens
end


puts count_even(4)
