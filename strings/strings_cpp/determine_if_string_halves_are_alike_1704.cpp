/*

    You are given a string s of even length. Split this string into
    two halves of equal lengths, and let a be the first half and b be the second half.

    Two strings are alike if they have the same number of vowels
     ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s
     contains uppercase and lowercase letters.

    Return true if a and b are alike. Otherwise, return false.


    Example 1:

    Input: s = "book"
    Output: true
    Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
    Therefore, they are alike.
    Example 2:

    Input: s = "textbook"
    Output: false
    Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
    Therefore, they are not alike.
    Notice that the vowel o is counted twice.


    Constraints:

    2 <= s.length <= 1000
    s.length is even.
    s consists of uppercase and lowercase letters.

*/

// APPROACH: Create two hashmaps to store the vowels
// for the first part of the string and the second part.
// populate the hashmaps with the vowels that are to be stored
// / in a vector.
// loop from 0 - n /2 (n being the length of s)
//  - each time a vowel is encountered add to total vowels
//  - perform the same for the second part
// return if the vowels count is the same

bool halvesAreAlike(string s) {
    map<char, int> ma;
    map<char, int> mb;

    vector<char> vowels = {'a', 'e', 'i','o','u', 'A', 'E', 'I', 'O', 'U'};

    for (char vowel: vowels) {
        ma[vowel] = 10;
        mb[vowel] = 10;
    }

    int ca = 0, cb = 0, n = s.length();

    for (int i = 0; i < n; i++) {
        if (i < (n / 2)) {
            if ( ma[s[i]] > 0){
                // ma[s[i]]++;
                ca++;
            }
        } else {
            if ( mb[s[i]]){
                // mb[s[i]]++;
                cb++;
            }
        }
    }

    return ca == cb;

}





