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
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        // vector<int> cnt; // This keeps track of groups 

        // cnt.push_back(1);

        // //TC:O(n)
        // for(int i = 1 ; i < n ; i++){
        //     if(s[i] == s[i-1]){
        //         cnt.back()++;
        //     }else{
        //         cnt.push_back(1);
        //     }
        // }

        // int subs = 0 ;
        // //TC:O(n)
        // for(int i = 0 ; i < cnt.size() -1 ; i++){
        //     subs += min(cnt[i] , cnt[i+1]);
        // }

        // //TC:O(2n) and SC:O(n) 
        // return subs;

        // Space optimised 

        int curr = 1 ; 
        int prev = 0 ;
        int ans = 0 ;

        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                ans += min(curr,prev);
                prev = curr ;
                curr = 1;
            }
        }

        // The last pair
        ans += min(curr,prev);

        //TC:O(n) and SC:(1)
        return ans;
    }
};