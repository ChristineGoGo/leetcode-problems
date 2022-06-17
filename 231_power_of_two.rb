# Given an integer n, return true if it is a power of two. Otherwise, return false.

# An integer n is a power of two, if there exists an integer x such that n == 2x.
# -------------- APPROACH 1 NAIVE -------------------------------------------------
# def is_power_of_two(n)
#     if n > 0
#         (0..(n**0.5).ceil).each  do |num|
#             return true if (2 ** num) == n
#         end
#     end
#     return false
# end

# -------------- APPROACH 2 CREATIVE  -------------------------------------------------

def is_power_of_two(n)
    return n <= 0 ? false : (2**63 % n == 0)
end

# test 1 : n = 36 expected : false
puts is_power_of_two(36)
# test 2 : n = 11 expected : false
puts is_power_of_two(11)
# test 3 : n = 1 expected : true
puts is_power_of_two(1)
# test 4 : n = 2 expected : true
puts is_power_of_two(2)
# test 5 : n = -90 expected : false
puts is_power_of_two(-90)
