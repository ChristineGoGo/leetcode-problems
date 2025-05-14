=begin
You are given a string s consisting of lowercase English letters, and an integer k. 
Your task is to convert the string into an integer by a special process, and then
 transform it by summing its digits repeatedly k times. More specifically, perform the following steps:

Convert s into an integer by replacing each letter with its position in the alphabet 
(i.e. replace 'a' with 1, 'b' with 2, ..., 'z' with 26).
Transform the integer by replacing it with the sum of its digits.
Repeat the transform operation (step 2) k times in total.
For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1

Output: 36

Explanation:

The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.

Example 2:

Input: s = "leetcode", k = 2

Output: 6

Explanation:

The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.

Example 3:

Input: s = "zbax", k = 2

Output: 8

 

Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.
=end

=begin
APPROACH: create a dictionary to store all the alphabets. Map the given string to their number equivalent.
Perform necessary additions according to k.

=end





# @param {String} s
# @param {Integer} k
# @return {Integer}

def sum_digits(digits)
    n = digits.length
    count = 0

    n.times do |i|
        count += Integer(digits[i])
    end

    return String(count)

end



def get_lucky(s, k)
    alphabet_dictionary = {}
    start_character = 97
    alphabet_number = 1
    n = s.length

    number_equivalent = ""

    result = 0

    26.times do  |i|
        alphabet_dictionary[start_character.chr] = alphabet_number
        alphabet_number += 1
        start_character += 1
    end
    puts alphabet_dictionary["a"]
    n.times { |i|
        number_equivalent += String(alphabet_dictionary[s[i]])
    }

    k.times do |num|
        number_equivalent = sum_digits(number_equivalent)
    end
    
    return Integer(number_equivalent)
end


puts get_lucky("leetcode", 2)





