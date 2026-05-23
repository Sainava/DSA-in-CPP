/*
Given two strings text1 and text2, return the length of the longest common subsequence between the two strings if one exists, otherwise return 0.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the relative order of the remaining characters.

For example, "cat" is a subsequence of "crabt".
A common subsequence of two strings is a subsequence that exists in both strings.

Example 1:

Input: text1 = "cat", text2 = "crabt" 

Output: 3 
Explanation: The longest common subsequence is "cat" which has a length of 3.

Example 2:

Input: text1 = "abcd", text2 = "abcd"

Output: 4
Example 3:

Input: text1 = "abcd", text2 = "efgh"

Output: 0
Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int funcTopDown(int i ,int j , int m , int n ,string text1 ,string text2 ,vector<vector<int>> &dp ){
        if( i < 0 || j < 0 ) return 0 ;

        if( dp[i][j] != -1 ) return dp[i][j] ;

        // if matching 
        if( text1[i] == text2[j]){
            dp[i][j] = 1 + funcTopDown(i-1 , j-1 , m,n , text1 , text2 , dp);
        }else{
            // Not matching 
            dp[i][j] = 0 + max(funcTopDown(i-1 , j ,m,n , text1 , text2 , dp) , funcTopDown(i , j-1 ,m,n , text1 , text2 , dp));
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() ;
        int n = text2.size() ;

        // // Top Down 
        // vector<vector<int>> dp(m, vector<int> (n , -1 )) ;
        // //dp[i][j] = is the longest common subsequence for string1[0 to i] and string2[0 to j]

        // //TC:O(m*n) and SC:O(m*n)
        // return funcTopDown(m-1 , n-1 , m ,n , text1 , text2 , dp);

        // //Bottom Up
        // vector<vector<int>> dp(m+1, vector<int> (n+1 , 0 ));
        // // Row 0 and Col 0 are just helpers 
        // // The string index need to be shifted by one

        // for(int i = 1 ; i <= m ; i++){
        //     for(int j = 1; j<= n ; j++){

        //         // if matching 
        //         if( text1[i -1 ] == text2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1] ;
        //         }else{
        //             // Not matching 
        //             dp[i][j] = 0 + max( dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // //TC:O(m*n) and SC:O(m*n)
        // return dp[m][n] ; 

        // Space Optimised 
        vector<int> prevRow(n+1 , 0 );
        vector<int> currRow(n+1 , 0 );

        for(int i = 1 ; i <= m ; i++){
            for(int j = 1; j<= n ; j++){

                // if matching 
                if( text1[i -1 ] == text2[j-1]){
                    currRow[j] = 1 + prevRow[j-1] ;
                }else{
                    // Not matching 
                    currRow[j] = 0 + max( prevRow[j], currRow[j-1]);
                }
            }

            prevRow = currRow ;
        }

        //TC:O(m*n) and SC:O(n)
        return currRow[n];

    }
};
