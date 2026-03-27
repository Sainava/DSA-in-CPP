/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include<iostream>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Longest substring with <condition> so think of sliding window 

        unordered_map<char,int> mp ; //char and its latest index to check if it is in the window or not

        int l = 0 ;
        int r = 0 ;
        int n = s.size() ;

        int maxLength = 0 ;

        while ( r < n ){

            // See if the latest character is valid

            // That is seen for the first time or its previous appearance is not in the window 
            if( mp.find(s[r]) == mp.end() || mp[s[r]] < l){
                maxLength = max( maxLength , r - l + 1);
                mp[s[r]] = r ; // Add or update the index 
            }
            // else make the window valid again -- This will be executed if the element is already in the window and is seen before 
            else{
                l = mp[s[r]] + 1 ; // srink the window to one step ahead of the element's last appearance
                mp[s[r]] = r ;
            }

            r++;
            
        }

        // TC :O(n) and SC:(n)
        return maxLength ;
    }

    
};