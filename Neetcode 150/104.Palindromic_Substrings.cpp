/*
Given a string s, return the number of substrings within s that are palindromes.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: s = "abc"

Output: 3
Explanation: "a", "b", "c".

Example 2:

Input: s = "aaa"

Output: 6
Explanation: "a", "a", "a", "aa", "aa", "aaa". Note that different substrings are counted as different palindromes even if the string contents are the same.

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // dp solution , for all substrings check if they are substrings 
        // But we save the extra check for palindrome of O(n) by using dp 

        int n = s.size();
        
        vector<vector<bool>> dp (n , vector<bool>(n,false));
        // dp[i][j] = true means s[i] to s[j] is a palindrome

        // make all one length substring true as they are palindromes

        // Outer loop -> creates all possible lengths that are possible 
        for(int len = 1 ; len <= n ;len++){
            // Inner loop generate all possible substrings of that length 

            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;
                // dp condition 
                if(s[i] == s[j] && (len<=2 || dp[i+1][j-1])){
                    // then it a palindrome 
                    dp[i][j] = true ; 
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dp[i][j] == true ) cnt++;
            }
        }
        
        //So another thing is dp is a triangular matrix  since at no point j is smaller than i , so the symmetric case does not occur and no duplicate counts 
        //upper triangular  because valid substring intervals satisfy: i≤j
        //j<i would mean: negative-length substring which is meaningless.
        //TC:O(n^2) and SC:O(n^2)
        return cnt ; 

    }
};
