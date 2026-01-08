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

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// SOlution 1 - Top - Down DP -- Results in TLE for one test case  ( because of addition space of n+m from recursion stack )
class Solution {
public:
    int solve(string text1, string text2 , int i , int j , vector<vector<int>> &dp){
        // Base condition 
        if( i >= text1.size() || j>=text2.size() ) {
            return 0 ;
        }

        // Check if answer exist 
        if(dp[i][j]!= -1 ){
            return dp[i][j];
        }

        int ans = 0 ; 

        // Matched Case 
        if(text1[i] == text2[j]){
            ans =  1 + solve(text1,text2,i+1,j+1 ,dp);
        }
        // Mismatched Case
        else{
            ans = max( solve(text1,text2,i+1,j ,dp) , solve(text1,text2,i,j+1 ,dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    
    }


    int longestCommonSubsequence(string text1, string text2) {
        //Step 1 : Form the DP
        vector<vector<int>> dp( text1.length() , vector<int> (text2.length() , -1)) ;
        //DP ( i , j ) == Maximum common subsequence starting from i of text1 and j of text2

        // TC : O(n x m) 
        // SC: O(n x m) = DP + O(n + m ) Recursion stack = O( n x m)
        return solve(text1,text2,0,0 , dp); // 0 , 0 index of first and second string respectively 
        
    }
};


//Solution 2 - Bottom - Up DP  - NO TLE 
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        //Step 1 : Form the DP
        vector<vector<int>> dp( text1.length() + 1 , vector<int> (text2.length() +1 , 0)) ;
        //DP ( i , j ) == Maximum common subsequence starting from i of text1 and j of text2
        // Initialising with dp solves the base case - The base case being i>= n and j>=m
        // Top Down - we go from 0 to n and 0 to m 
        // So Bottom up - we go from n to 0 and m to 0
        // Basically bottom up dp must have the answers that recursively call gives in dp top down 

        for( int i = text1.length() -1 ; i >= 0 ; i--){
            for( int j = text2.length() - 1 ; j>=0 ; j--){
                
                int ans = 0 ; 

                // Matched Case 
                if(text1[i] == text2[j]){
                    ans =  1 + dp[i+1][j+1];
                }
                // Mismatched Case
                else{
                    ans = max( dp[i+1][j] , dp[i][j+1]);
                }

                dp[i][j] = ans;
            }
        }

        // TC : O(n x m)
        //SC:O(n x m )
        return dp[0][0];

        
    }
};