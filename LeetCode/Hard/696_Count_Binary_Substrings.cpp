/*
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev_len = 0;
        int curr_len = 1;
        int ans = 0;
        
        for (int i = 1; i < s.length(); i++) {
            // If the current character matches the previous one, extend the current group
            if (s[i] == s[i - 1]) {
                curr_len++;
            } 
            // If the character changes, the group ends
            else {
                ans += min(prev_len, curr_len);
                prev_len = curr_len;
                curr_len = 1; // Reset for the new character group
            }
        }
        
        // Don't forget to add the combinations from the very last pair of groups
        ans += min(prev_len, curr_len);
        
        return ans;
    }
};