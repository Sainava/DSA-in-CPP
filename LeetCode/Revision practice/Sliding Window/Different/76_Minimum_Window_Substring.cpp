/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?


*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    string minWindow(string s, string t) {
        //Minimum substring with <condition>  -- THINK OF SLIDING WINDOW 

        // // Brute force 
        // int minLength = INT_MAX;
        // int startIndex = -1;
        

        // for(int i = 0 ; i < s.size() ; i++){ // To get all possible starting index 
        //     vector<int> hash(256);
        //     for(char &c:t){
        //         hash[c]++;
        //     }
        //     int count = 0 ;
        //     for(int j = i ; j< s.size() ; j++){
        //         if(hash[s[j]]>0){// Pre-inserted 
        //             count ++;
        //             hash[s[j]]--;
        //         }

        //         if(count == t.size()){
        //             // is length smaller than what we got previously 
        //             if((j-i + 1) < minLength){
        //                 minLength = (j - i + 1);
        //                 startIndex = i;
        //                 break;
        //             }
        //         }

        //     }
        // }

        // if(startIndex == -1)
        //     return "";

        // //TC:O(n^2) and SC:O(1) or SC:O(256)
        // return s.substr(startIndex, minLength);

        // Optimised solution 

        int l = 0 ;
        int r = 0 ;
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0 ;

        vector<int> hash(256);
        int m = t.size();

        //TC:O(m)
        for(char &c:t){
            hash[c]++;
        }

        //TC:(n)
        while ( r < s.size()){ // TO get all possible start Indices 

            hash[s[r]]--;

            // If preinserted , it means count > 0 
            if(hash[s[r]] >= 0){
                count++;

            }

            // Shrink while possible solution 
            while (count == m){ // Overall across all outer loop can run till O(n)
                if( (r - l + 1) < minLength){
                    minLength = r - l + 1;
                    startIndex = l;
                }
                hash[s[l]]++;           
                if(hash[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        if(startIndex == -1)
            return "";

        // TC :O(2n + m) and SC:O(256)
        return s.substr(startIndex, minLength);



    }
};