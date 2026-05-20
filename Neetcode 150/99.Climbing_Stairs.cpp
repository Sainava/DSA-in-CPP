/*
You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either 1 or 2 steps at a time.

Return the number of distinct ways to climb to the top of the staircase.

Example 1:

Input: n = 2

Output: 2
Explanation:

1 + 1 = 2
2 = 2
Example 2:

Input: n = 3

Output: 3
Explanation:

1 + 1 + 1 = 3
1 + 2 = 3
2 + 1 = 3
Constraints:

1 <= n <= 45
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int n , vector<int> &dp){
        // Base case 
        if( n <=1) return 1;

        // Step 2 : Check if val already computed 
        if( dp[n]!= -1) return dp[n];

        // Step 3 :store val in dp 

        dp[n] = func(n-1 , dp) + func(n-2 ,dp);

        return dp[n];

    }
    int climbStairs(int n) {
        //The way to reach the nth step is equal to the ways to reach n-1 plus no of ways to reach n-2 steps 


        // // DP method 1 : Top down 
        // // Step 1 :Initialise dp , steps from 0 to n so n+1 elements 

        // vector<int> dp(n+1 , -1 );

        // //TC:O(2^n) as each calls two functions that can be called multiple times for recursion 
        // // But after dp , it is TC:O(n) as each function called only once 
        // //SC:O(n) as size of dp and maximum recursion depth
        // return func(n , dp);

        // // DP : Method 2 : Bottom up
        // vector<int> dp(n+1 , -1 );
        // dp[0] = dp[1] = 1 ;

        // for(int i = 2 ; i <= n ; i++){
        //     dp[i] = dp[i-1] + dp[i-2];  
        // }

        // // Again TC:(n) and SC:O(n)
        // return dp[n];

        // Space optimised

        int prev1 = 1 ;
        int prev2 = 1 ;

         for(int i = 2 ; i <= n ; i++){
             int curr = prev1 + prev2;
             prev2 = prev1;
             prev1 = curr ;
        }

        //TC:O(n) and SC:O(1)
        return prev1;

    }
};
