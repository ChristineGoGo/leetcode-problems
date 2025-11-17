/*
    You are given a string s of lowercase English letters and an 
    array widths denoting how many pixels wide each lowercase English 
    letter is. Specifically, widths[0] is the width of 'a', widths[1] 
    is the width of 'b', and so on.

    You are trying to write s across several lines, where each line
    is no longer than 100 pixels. Starting at the beginning of s, write 
    as many letters on the first line such that the total width does not
    exceed 100 pixels. Then, from where you stopped in s, continue writing
    as many letters as you can on the second line. Continue this process
    until you have written all of s.

    Return an array result of length 2 where:

    result[0] is the total number of lines.
    result[1] is the width of the last line in pixels.
    

    Example 1:

    Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
    Output: [3,60]
    Explanation: You can write s as follows:
    abcdefghij  // 100 pixels wide
    klmnopqrst  // 100 pixels wide
    uvwxyz      // 60 pixels wide
    There are a total of 3 lines, and the last line is 60 pixels wide.
    Example 2:

    Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
    Output: [2,4]
    Explanation: You can write s as follows:
    bbbcccdddaa  // 98 pixels wide
    a            // 4 pixels wide
    There are a total of 2 lines, and the last line is 4 pixels wide.
    

    Constraints:

    widths.length == 26
    2 <= widths[i] <= 10
    1 <= s.length <= 1000
    s contains only lowercase English letters.
*/
#include <iostream>
#include <map>

using namespace std;

// APPROACH: Use a hashmap to track the lowercase alphabet letters then
// count the pixels for each letter
vector<int> numberOfLines(vector<int>& widths, string s) {
    map<char, int> alphabetPixelMap;
    map<int, int> lineCountPixels;

    // populate each letter in the alphabet with its pixel
    for (int i = 97; i <= 123; i++) {
        char curr = i + '0';
        alphabetPixelMap[i] = widths[i - 97];
    }

    int currLineCount = 1;
    int pixelTotal = 0;
    // populate each line in the final result
    for (char letter: s) {
        pixelTotal += alphabetPixelMap[letter];
        // cout << "current pixels: " <<  pixelTotal << "\n";

        if (pixelTotal > 100) {
            // cout << "pixels greater than 100 ";
            pixelTotal -= alphabetPixelMap[letter];
            // cout << "current pixels: " << pixelTotal << "\n";
            lineCountPixels[currLineCount] = pixelTotal;
            currLineCount++;
            pixelTotal = alphabetPixelMap[letter];
            lineCountPixels[currLineCount] = pixelTotal;
        } else {
            lineCountPixels[currLineCount] = pixelTotal;
        }
    }

    return {currLineCount, lineCountPixels[currLineCount]}; 
}