/*
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

Constraints:

1 <= s.length <= 5 * 105
s[i] is either '0' or '1'.
1 <= k <= 20
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int targetCount = 1 << k; // 2^k possible combinations
        
        // Early optimization: the string must be at least this long
        // to contain 2^k distinct substrings of length k.
        if (n < targetCount + k - 1) {
            return false;
        }

        // Boolean array to track which integers (binary codes) we've seen
        vector<bool> seen(targetCount, false);
        int hash = 0;
        int all_ones = targetCount - 1; // Mask to keep only k bits
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Shift left, mask off the leading bit, and add the new bit
            hash = ((hash << 1) & all_ones) | (s[i] - '0');
            
            // Once we have processed at least k characters (a full window)
            if (i >= k - 1) {
                if (!seen[hash]) {
                    seen[hash] = true;
                    count++;
                    
                    // If we found all possible codes, we can stop early
                    if (count == targetCount) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};