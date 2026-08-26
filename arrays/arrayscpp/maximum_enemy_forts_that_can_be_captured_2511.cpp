/*
    You are given a 0-indexed integer array forts of length n
    representing the positions of several forts. forts[i] can be -1, 0, or 1 where:

        - -1 represents there is no fort at the ith position.
        - 0 indicates there is an enemy fort at the ith position.
        - 1 indicates the fort at the ith the position is under your command.

    Now you have decided to move your army from one of your forts at position i to an empty position j such that:
        0 <= i, j <= n - 1

    The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
    While moving the army, all the enemy forts that come in the way are captured.

    Return the maximum number of enemy forts that can be captured. 
    In case it is impossible to move your army, or you do not have any fort under your command, return 0.

    Example 1:
        Input: forts = [1,0,0,-1,0,0,0,0,1]
        Output: 4
        Explanation:
        - Moving the army from position 0 to position 3 captures 2 enemy forts, at 1 and 2.
        - Moving the army from position 8 to position 3 captures 4 enemy forts.
        Since 4 is the maximum number of enemy forts that can be captured, we return 4.

    Example 2:

        Input: forts = [0,0,1,-1]
        Output: 0
        Explanation: Since no enemy fort can be captured, 0 is returned.

    Constraints:

        1 <= forts.length <= 1000
        -1 <= forts[i] <= 1

*/

//APPROACH: Create variable to store the maximum enemy forts
// Set variable to 0
// Loop for each index in forts if the number at index is -1:
//      - loop back until we find a 1
//          - the enemies concured is start index - end index
//          - determine if it is maximum enemy fort
//      - loop forward until we find a 1
//          - the enemies concured is end index - start index
//          - determine if it is maximum enemy fort
// Return maximum enemy forts
int captureForts(vector<int>& forts) {
    int n = forts.size();
    int maxForts = 0; int currFort = 0;

    for (int i = 0; i < n; i++) {
        if (forts[i] == -1) {
            int j = i - 1;
            currFort = 0;

            while(j >= 0) {
                // cout << "moving back \n";
                // cout << "fort is: " << forts[j] << "\n";

                if (forts[j] == 1) {
                    maxForts = max(currFort, maxForts);
                    break;
                } else if (forts[j] == 0) {
                    currFort++;
                } else {
                    break;
                }
                j--;
            }
            int k = i + 1;
            currFort = 0;
            while (k < n) {
                // cout << "moving forward \n";
                // cout << "fort is: " << forts[k] << "\n";
                if(forts[k] == 1) {
                    maxForts = max(currFort, maxForts);
                    break;
                } else if (forts[k] == 0) {
                    currFort++;
                } else {
                    break;
                }
                k++;
            }
        }
    }

    return maxForts;
}

