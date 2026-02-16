/*

    Reverse bits of a given 32 bits signed integer.



    Example 1:

    Input: n = 43261596

    Output: 964176192

    Explanation:

    Integer	Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000


    Example 2:

    Input: n = 2147483644

    Output: 1073741822

    Explanation:

    Integer	Binary
    2147483644	01111111111111111111111111111100
    1073741822	00111111111111111111111111111110


    Constraints:

    0 <= n <= 231 - 2
    n is even.


    Follow up: If this function is called many times, how would you optimize it?

*/
// APPROACH : Somehow turn n into binary w/o reversing
// Convert the binary back to integer and return
int reverseBits(int n) {
    int num = n; string tBin = "";

    while (num > 0) {
        tBin += to_string(num % 2);
        num /= 2;
    }
    
    if (tBin.size() < 32) {
        int l = 32 - tBin.size();
        while (l > 0) {
            tBin += "0";
            l--;
        }
    }


    int totDec = 0; long b = 1; string currS = "";
    for (int i = tBin.size() - 1; i >= 0; i-- ) {
        currS +=  tBin[i];
        int fromString = stoi(currS);
        totDec +=  (fromString * b);
        b *= 2;
        currS = "";
    }

    return totDec;
    
}








