/*
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

 

Example 1:

Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Example 2:

Input: s = "10"
Output: "10"
 

Constraints:

1 <= s.length <= 50
s[i] is either '0' or '1'.
s is a special binary string.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int left = 0;
        vector<string> substrings;
        
        // 1. Split the string into primitive special substrings
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                count--;
            }
            
            // When count hits 0, we've found a complete primitive substring
            if (count == 0) {
                // 2. Peel the outer '1' and '0'
                // The inner string starts at left + 1 and has length (i - left - 1)
                string inner = s.substr(left + 1, i - left - 1);
                
                // 3. Recursively maximize the inner string, then wrap it back in '1' and '0'
                string maximized_primitive = "1" + makeLargestSpecial(inner) + "0";
                substrings.push_back(maximized_primitive);
                
                // Move the left pointer to the start of the next potential primitive string
                left = i + 1;
            }
        }
        
        // 4. Sort all maximized primitive substrings in descending order
        sort(substrings.begin(), substrings.end(), greater<string>());
        
        // 5. Concatenate and return
        string result = "";
        for (const string& sub : substrings) {
            result += sub;
        }
        
        return result;
    }
};