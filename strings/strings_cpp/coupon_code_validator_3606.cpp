/*
    You are given three arrays of length n that describe the properties of n coupons:
    code, businessLine, and isActive. The ith coupon has:

        - code[i]: a string representing the coupon identifier.
        - businessLine[i]: a string denoting the business category of the coupon.
        - isActive[i]: a boolean indicating whether the coupon is currently active.
        A coupon is considered valid if all of the following conditions hold:
            1. code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
            2. businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
            3. isActive[i] is true.
    Return an array of the codes of all valid coupons, sorted first by their businessLine in the order:
    "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending)
    order within each category.

    Example 1:

    Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

    Output: ["PHARMA5","SAVE20"]

    Explanation:

    First coupon is valid.
    Second coupon has empty code (invalid).
    Third coupon is valid.
    Fourth coupon has special character @ (invalid).

    Example 2:

    Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

    Output: ["ELECTRONICS_50"]

    Explanation:

    First coupon is inactive (invalid).
    Second coupon is valid.
    Third coupon has invalid business line (invalid).

    Constraints:

    n == code.length == businessLine.length == isActive.length
    1 <= n <= 100
    0 <= code[i].length, businessLine[i].length <= 100
    code[i] and businessLine[i] consist of printable ASCII characters.
    isActive[i] is either true or false.
*/
// APPROACH: Create a map to store all the valid coupon codes according
// to their business lines in a vector then ensure that they are sorted lexicographically
// combine them into a vector and return the result
bool isAlphanumeric(string s) {
    int n = s.length(); bool isValid = true;
    if (n == 0) return false;

    for (int i = 0; i < n; i++) {
        char curr = s[i];
        if (isalnum(curr) || curr == '_') {
            continue;
        } else {
            isValid = false;
        }
    }

    return isValid;
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    int n = code.size();
    vector<string> business = {"electronics", "grocery", "pharmacy", "restaurant"};
    map<string, vector<string>> businessMappings;
    vector<string> res;

    for (int i = 0;i < n; i++) {
        string currCode = code[i];
        if (isActive[i] && isAlphanumeric(currCode)) {
            if (businessLine[i] == "electronics") {
                businessMappings["electronics"].push_back(currCode);
            } else if(businessLine[i] == "grocery") {
                businessMappings["grocery"].push_back(currCode);
            } else if(businessLine[i] == "pharmacy") {
                businessMappings["pharmacy"].push_back(currCode);
            } else if (businessLine[i] == "restaurant") {
                businessMappings["restaurant"].push_back(currCode);
            }
        }
    }

    for (string currBusiness: business) {
        sort(businessMappings[currBusiness].begin(),businessMappings[currBusiness].end());
        for (string businessCode: businessMappings[currBusiness]) {
            res.push_back(businessCode);
        }
    }

    return res;

}

