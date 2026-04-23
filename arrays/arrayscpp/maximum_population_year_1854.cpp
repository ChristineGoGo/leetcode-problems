/*

    You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

    The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if
    x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

    Return the earliest year with the maximum population.



    Example 1:

    Input: logs = [[1993,1999],[2000,2010]]
    Output: 1993
    Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

    Example 2:

    Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
    Output: 1960
    Explanation:
    The maximum population is 2, and it had happened in years 1960 and 1970.
    The earlier year between them is 1960.


    Constraints:

    1 <= logs.length <= 100
    1950 <= birthi < deathi <= 2050

*/
//Create map to store the years 1950 to 2050 and to record
// the population count of each year. Loop for each person populating the
// years that they were alive on the map.
// Keep track of the maximum population with a variable
// return the minimum year of maximum population
int maximumPopulation(vector<vector<int>>& logs) {
    map<int, int> populationByYear;
    int n = logs.size(); int maxPop = 0;

    for (int i = 1950; i <= 2050; i++) {
        populationByYear[i] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = logs[i][0]; j < logs[i][1]; j++) {
            populationByYear[j]++;
            maxPop = max(maxPop, populationByYear[j]);
        }
    }

    for (int i = 1950; i < 2050; i++) {
        if (populationByYear[i] == maxPop) return i;
    }
    return 1950;
}

