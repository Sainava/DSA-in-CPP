/*
You are given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer. For example, 1, 4, 9, 16, 25... are perfect squares.

Example 1:

Input: n = 13

Output: 2
Explanation: 13 = 4 + 9.

Example 2:

Input: n = 6

Output: 3
Explanation: 6 = 4 + 1 + 1.

Constraints:

1 <= n <= 10,000
*/
#include <iostream>
#include <vector>
using namespace std;

//Solution using Top - Down 
class Solution {
public:
    int solve(int n ,vector<int> &dp){
        if( n == 0) return 0 ; // 0 requires 0 to make a perfect square 

        if( dp[n]!= -1) return dp[n] ;

        int cnt = INT_MAX ;

        for(int i = 1 ; i*i <= n ; i++){
            //Lets take this and try 
            cnt = min( cnt  , 1 + solve(n - i*i , dp));
        }

        return dp[n] = cnt ;  // 1*1 <= n so we do not need to check if cnt is still INT_MAX
    }

    int numSquares(int n) {
        //What is the minimum number of perfect squares needed to make n?

        // Minimum number of items needed to form a target
        // think:
        // Coin Change (minimum coins)
        vector<int> dp(n+1 , -1) ;


        // Time Complexity: O(n * sqrt(n))
        // Each state 0..n is solved once.
        // For each state we try all perfect squares <= state.
        //
        // Space Complexity: O(n)
        // DP array + recursion stack.
        return solve(n , dp);
    }
};

// Solution using Bottom - Up
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1 , 0) ;

        for(int i = 1 ; i<= n ; i++){
            int cnt = INT_MAX ;

            for(int j = 1 ; j*j <= i ; j++){
                //Lets take this and try 
                cnt = min( cnt  , 1 + dp[i - j*j]);
            }

            dp[i] = cnt ; 
        }

        // Time Complexity: O(n * sqrt(n))
        // Outer loop: n states
        // Inner loop: at most sqrt(i) choices
        //
        // Space Complexity: O(n)
        return dp[n];
    }
};