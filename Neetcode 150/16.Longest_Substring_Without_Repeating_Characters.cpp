/*
Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3
Explanation: The string "xyz" is the longest without duplicate characters.

Example 2:

Input: s = "xxxx"

Output: 1
Constraints:

0 <= s.length <= 1000
s may consist of printable ASCII characters.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Longest substring so sliding window 

        unordered_map<char,int> mp; // char and its latest index 

        int n = s.size();
        int l = 0 ;
        int r = 0 ;

        int maxLength = 0;

        while( r < n){
            if( mp.find(s[r]) != mp.end() && mp[s[r]]>=l){
                // if mp[s[r]] is not even in the current window , we do not need to do anything  
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;

            maxLength = max( maxLength , r - l + 1);

            r++;
        }

        //TC:O(n) and SC:O(n)
        return maxLength ;
    }
};
