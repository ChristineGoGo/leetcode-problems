=begin
Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. 
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), 
while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). 
    Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year.
 Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

 

Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. 
They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
=end

=begin
APPROACH: Figure out who arrives last and then figure out who leaves first
the result is the difference between the two, create a list to store the number of days in each month of the year
=end

# @param {String} arrive_alice
# @param {String} leave_alice
# @param {String} arrive_bob
# @param {String} leave_bob
# @return {Integer}
def count_days_together(arrive_alice, leave_alice, arrive_bob, leave_bob)
    possible_days_together = false
    month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days_together = 0
    arrive_last = 0
    leave_first = 0

    # who arrives first
    alice_arrival_month = arrive_alice[0,2]
    bob_arrival_month = arrive_bob[0, 2]
    #check that Alice's arrival is before or same as Bob's
    if alice_arrival_month <= bob_arrival_month && alice_arrival_day <= bob_arrival_day
        possible_days_together == true
    end

    #calculate the number of days spent together
     days_together += (month_days[alice_arrival_month] - month_days[bob_arrival_month])
     days_together += (alice_arrival_day - bob_arrival_day)

    # return the total days spent together
    return days_together
    
end




