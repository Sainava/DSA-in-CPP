/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 3

Output: 2
Explanation:
T_3 = 0 + 1 + 1 = 2

Example 2:

Input: n = 21

Output: 121415
Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fab( int n , vector<int> &dp){
        if( n == 0 ) return 0 ; 
        if ( n == 1 || n==2) return 1 ; 

        if( dp[n] != -1 ) return dp[n] ; 

        return dp[n] = fab(n-1 ,dp) + fab(n-2 ,dp) + fab(n-3 ,dp) ; 
    }
    int tribonacci(int n) {
        
        // //Top - Down 
        // vector<int> dp(n+1 , -1);
        // //TC:O(n) and SC:O(n)
        // return fab(n , dp);

        // // Bottom up 
        // vector<int> dp(n+1 , 0);

        // dp[0] = 0 ; 
        // dp[1] = dp[2] = 1 ; 

        // for(int i = 3 ; i <= n ; i++){
        //     dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        // }
        // //TC:O(n) and SC:O(n)
        // return dp[n];

        // Space optimised 

        int prev1 = 0 ; 
        int prev2 = 1 ;
        int prev3 = 1 ; 

        for(int i = 3 ; i <= n ; i++){
            int curr = prev1 + prev2 + prev3;

            prev1 = prev2 ; 
            prev2 = prev3 ; 
            prev3 = curr ; 
        }
        //TC:O(n) and SC:O(1)
        return (n==0) ? 0 :prev3 ; 
    }
};