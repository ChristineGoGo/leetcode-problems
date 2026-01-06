/*

    Write a program to count the number of days between two dates.

    The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.



    Example 1:

    Input: date1 = "2019-06-29", date2 = "2019-06-30"
    Output: 1
    Example 2:

    Input: date1 = "2020-01-15", date2 = "2019-12-31"
    Output: 15


    Constraints:

    The given dates are valid dates between the years 1971 and 2100.

*/


#include <iostream>

using namespace std;

int isLeapYear(int y) {
    if (y % 100 == 0 && y % 400 == 0) {
        return 1;
    } else if (y % 100 != 0 && y % 4 == 0) {
        return 1;
    }
    return 0;
}

int standardizeDate(string date1) {
    // days in months
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // base year
    int baseYear = 1900, baseMonth = 1, baseDay = 0;

    // total days
    int total = 0;

    // given date
    int originalYear = stoi(date1.substr(0, 4));
    int originalMonth = stoi(date1.substr(5,2));
    int originalDay = stoi(date1.substr(8,2));

    // add up all the years including extra days for leap year
    for (int i = baseYear; i < originalYear; i++) {
        total +=  isLeapYear(i) + 365;
    }

    // add up all the months
    for (int i = baseMonth; i < originalMonth; i++) {
        total += months[i - 1];
        if (i == 2) total = isLeapYear(originalYear) == 1 ? ++total : total;
    }

    // add up the days
    total += originalDay;

    return total;


}
int daysBetweenDates(string date1, string date2) {

    return abs(standardizeDate(date1) - standardizeDate(date2));

}

