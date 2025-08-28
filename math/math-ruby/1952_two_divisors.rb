=begin
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

 

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.
=end

=begin
APPROACH: All numbers have 1 and itself as a divisor. Set total divisors to 2. Loop
from 2 - n / 2 (since n / 2) is the largest divisor. If the divisors found is greater
than 1 return false since the number has more than three divisors. Otherwise, return true.
=end

# @param {Integer} n
# @return {Boolean}

def is_three(n)
    start = 1
    stop = n.to_f / 2
    total_divisors = 0
    num = n

    while start <= stop
        if num.to_f % start  == 0
            total_divisors += 1
        end
        if total_divisors > 3
            return false
        end
        start += 1
    end
    return total_divisors + 1 == 3 ?  true : false
end

puts is_three(6)

