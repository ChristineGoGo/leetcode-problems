/*
    Given the binary representation of a number,
    convert the number into its decimal format:

    Example 1:
        Input : "101"
        Output : 5
    
    Example 2:
        Input : "11"
        Output : 3

*/

#include <iostream>

using namespace std;

int toDecimal(string bin) {
    int dec = 0;

    for (int i = 0; i < bin.length(); i++) {
        int curr = bin[i] - '0';
        dec *= 2;
        dec += curr;
    }

    return dec;

}

int main() {
    vector<vector<int>> s = {{9,0}, {8, 0} };
    cout << s[0][0];
    cout << toDecimal("1000");
    return 0;
}


