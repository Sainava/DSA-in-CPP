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
#include<vector>
using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Longest Subarray ( Substring ) with <condition> -- THINK OF SLIDING WINDOW 

        // // Brute Force -- Generate all substrings and check the longest length 
        // int maxLength= 0 ;


        // for(int i = 0 ; i < s.size() ; i++){
        //     // There are 255 total characters that are possible 
            
        //     vector<int> count(255,0);

        //     for(int j = i ; j < s.size() ; j++){
        //         int index = s[j] ; // This directly gets converted , no need to do anything 

        //         if(count[index] == 0){// Non-repeating 
        //             count[index]++;
        //             maxLength = max(maxLength , j - i + 1);
        //         } else{ // Repeating , do not check further for this 'i'
        //             break ;
        //         }
        //     }      
        // }

        // //TC:O(n^2) and SC:O(n)
        // return maxLength;

        // Optimised Sliding window approach 

        int l = 0 ;
        int r = 0 ;

        int maxLength=0 ;

        unordered_map<char , int > mp ; // < character , its index >


        while( r < s.size() ){
            // Step 1 : Create the window 

            // Check if character already seen 

            // IF not already seen or not in the window 
            if ( mp.find(s[r]) == mp.end() || mp[s[r]] < l ){
                maxLength = max(maxLength , r - l + 1 );
                mp[s[r]] = r;
            }else{// Move window forward so that it does not contain that element 

                l = mp[s[r]] + 1;
                mp[s[r]] = r ; // Update that index of repeated character to the one in the window 
            }

            r = r + 1; // Next window 
        }

        //TC :O(n) and SC:O(n)
        return maxLength;

    }
};