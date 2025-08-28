=begin
Given an integer num, repeatedly add all its digits until the result has only one digit, 
and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 2^ 31 - 1
 
=end
=begin
APPROACH: keep finding the remainder of number when divided by 10
add that to the sum. 
=end

# @param {Integer} num
# @return {Integer}
def add_digits(num)
    count = 0
    while num > 9
        current = num
        while current != 0
            count += current % 10
            current /= 10
        end
        num = count
        count = 0
    end
    return num
    
end

puts add_digits(0)




