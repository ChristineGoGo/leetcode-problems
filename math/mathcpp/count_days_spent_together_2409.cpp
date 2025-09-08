/*

Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob.
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), 
while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). 
Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year.
Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

*/


#include <iostream>
#include <string>

using namespace std;
    // APPROACH: convert to days and then find the interlap
    // look at all 365 days
int fDays(string s) {
    vector<int> dm = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m = (s[1] - '0') + ((s[0] - '0') * 10) - 1;
    int d = (s[4] - '0') + ((s[3] - '0') * 10);

    while (m > 0) {
        d += dm[m];
        m--;
    }
    
    return d;
}
int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int total = 0;
    int aa = fDays(arriveAlice);
    int al = fDays(leaveAlice);
    int ab = fDays(arriveBob);
    int lb = fDays(leaveBob);

    for (int i = 0; i < 365; i++) {
        if (i >= aa &&  i >= ab && i <= al & i <= lb) {
            total++;
        }
    }
    return total;


}

int main() {
    string s = "12-08";

    cout << fDays(s);
}


