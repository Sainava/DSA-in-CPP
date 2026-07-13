// 13 July 2026 

// 1291. Sequential Digits

/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        string digits = "123456789";

        // Length of the sequential number
        for (int len = 2; len <= 9; len++) {

            // Starting position in "123456789"
            for (int start = 0; start + len <= 9; start++) {

                int num = stoi(digits.substr(start, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        // TC:
        // There are only 36 sequential numbers.
        // Each generation takes O(1).
        //
        // Overall: O(1)
        //
        // SC:
        // O(1)
        // (Ignoring the output array.)
        return ans;
    }
};