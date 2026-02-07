/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.
*/

#include <iostream> 
#include <string>   
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int count_b = 0;
        int min_deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                // If we see 'b', we just count it. 
                // It might be deleted later if an 'a' appears, or kept if it's part of the suffix.
                count_b++;
            } else {
                // c is 'a'
                // We have a conflict: ...b...a
                // Option 1: Delete this 'a' (min_deletions + 1)
                // Option 2: Keep this 'a' and delete all previous 'b's (count_b)
                min_deletions = min(min_deletions + 1, count_b);
            }
        }
        
        return min_deletions;
    }
};