=begin
Given a 0-indexed string word and a character ch, reverse the segment of 
word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). 
If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts
 at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
=end


=begin
APPROACH: loop through the given string until you find the given character. Note the
index of the character(index). Reverse the substring from 0 - index. Return the reversed
substring(0 - index) until the end of the string(index + 1 to n) n is the length of the 
given string
=end


# @param {String} word
# @param {Character} ch
# @return {String}
def reverse_word(word)
    n = word.length
    l = 0
    r = n - 1

    while l <= r
        temp = word[l]
        word[l] = word[r]
        word[r] = temp
        l += 1
        r -= 1
    end

    return word
end
def reverse_prefix(word, ch)
    index = 0
    current_index = 0
    n = word.length

    n.times do |i|
        if word[i].eql?(ch)
            index = current_index
            break
        end
        current_index += 1
    end
    return index == 0 ? word : reverse_word(word[0, index + 1]) + word[index + 1, n]
end

puts reverse_prefix("abcd", "z")

