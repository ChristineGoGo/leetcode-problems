#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int totalA = 0;
    int totalB = 0;
    set<int> bobSet; 
    vector<int> res;

    for (int num: aliceSizes) {
        totalA += num;
    }

    for (int num: bobSizes) {
        totalB += num;
        bobSet.insert(num);
    }

    for (int num: bobSet) {
        for (int num1: aliceSizes) {
            int totalAlice = totalA + num - num1;
            int totalBob = totalB - num + num1;

            if (totalAlice == totalBob) {
                res.push_back(num1);
                res.push_back(num);
                return res;
            }
        }
    }
    
    return res;
}