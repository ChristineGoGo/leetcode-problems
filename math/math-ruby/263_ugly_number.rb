=begin
An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

 

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

=end

=begin
APPROACH: use iteration and while loop making divisions with the
prime numbers: 2, 3, 5
=end

# @param {Integer} n
# @return {Boolean}
def is_ugly(n)
    num = n

    
    while num > 0
        if num == 1
            return true
        end

        if num % 2 == 0
            num = num.to_f / 2
        elsif num % 3 == 0
            num = num.to_f / 3
        elsif num % 5 == 0
            num = num.to_f / 5
        else
            break
        end
    end

    return false
end

puts is_ugly(11)


