/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/
#include<iostream>
#include<vector>
using namespace std ;


class Solution {
public:
    int func(int idx1 , int idx2 ,string &text1, string &text2){
        // Base Case 
        if(idx1 < 0 || idx2 < 0){
            return 0 ;
        }

        // Case 1 : Match 

        if(text1[idx1] == text2[idx2]){
            return 1 + func(idx1 - 1 , idx2 - 1 , text1 , text2);
        }

        // Case 2 : Not Matching

        return 0 + max( func(idx1 -1 , idx2 , text1 , text2) , func(idx1 , idx2 -1 , text1 , text2) );
    }

    int topDown(int idx1 , int idx2 ,string &text1, string &text2 , vector<vector<int>> &dp){
        // Base Case 
        if(idx1 < 0 || idx2 < 0){
            return 0 ;
        }

        if (dp[idx1][idx2]!= -1) return dp[idx1][idx2];

        // Case 1 : Match 

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] =  1 + topDown(idx1 - 1 , idx2 - 1 , text1 , text2 , dp);
        }

        // Case 2 : Not Matching

        return dp[idx1][idx2] = 0 + max( topDown(idx1 -1 , idx2 , text1 , text2 , dp) , topDown(idx1 , idx2 -1 , text1 , text2 ,dp) );
    }


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() ;
        int n = text2.size() ;

        // //We are exploring all possible subsequence(power set) for both 
        // // SO TC:( 2^m x 2^n)
        // return func(m-1 , n-1 , text1, text2);


        // // Add memoization 
        // vector<vector<int>> dp( m , vector<int> (n , -1)) ; // simce 2 changing params here , idx1 and idx2

        // // TC :O( m x n ) and SC:O( m x n ) for dp + SC:O( m + n) for auxiallry stack space in recursion 
        // return topDown( m-1 , n -1 , text1 , text2 , dp);

        // //Tabulation 
        // vector<vector<int>> dp( m + 1 , vector<int> (n + 1 , 0)) ;

        // // Step 1 , make the base case the same as memoization , this is we we did m + 1 and n +1 , so we cab treat the index zeroes as negative equivalent here 

        // for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        // for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;


        // // Step 2 ; we calculate in the reverse fashion as compared to memoization 
        // for(int i = 1 ; i <= m ; i++){
        //     for(int j = 1 ; j <= n ; j++){
        //         // Case 1 : Match 

        //         if(text1[i-1] == text2[j-1]){
        //             dp[i][j] =  1 + dp[i-1][j-1];
        //         }
        //         else {
        //         // Case 2 : Not Matching
        //         dp[i][j] = 0 + max( dp[i-1][j] , dp[i][j-1] );
        //         }
                
        //     }
        // }
        // //TC:O(n x m) and S:O(n x m)
        // return dp[m][n];


        // Space optimised 

        
        vector<int> prev(n+1 , 0) , curr( n + 1 , 0) ;

        // Step 2 ; we calculate in the reverse fashion as compared to memoization 
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                // Case 1 : Match 

                if(text1[i-1] == text2[j-1]){
                    curr[j] =  1 + prev[j-1];
                }
                else {
                // Case 2 : Not Matching
                curr[j] = 0 + max( prev[j] , curr[j-1] );
                }
                
            }

            prev = curr;
        }
        //TC:O(n x m) and S:O(n)
        return prev[n];

    }
};