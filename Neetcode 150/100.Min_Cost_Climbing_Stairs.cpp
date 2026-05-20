/*
You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase. After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor.

You may choose to start at the index 0 or the index 1 floor.

Return the minimum cost to reach the top of the staircase, i.e. just past the last index in cost.

Example 1:

Input: cost = [1,2,3]

Output: 2
Explanation: We can start at index = 1 and pay the cost of cost[1] = 2 and take two steps to reach the top. The total cost is 2.

Example 2:

Input: cost = [1,2,1,2,1,1,1]

Output: 4
Explanation: Start at index = 0.

Pay the cost of cost[0] = 1 and take two steps to reach index = 2.
Pay the cost of cost[2] = 1 and take two steps to reach index = 4.
Pay the cost of cost[4] = 1 and take two steps to reach index = 6.
Pay the cost of cost[6] = 1 and take one step to reach the top.
The total cost is 4.
Constraints:

2 <= cost.length <= 100
0 <= cost[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int n , vector<int> &dp , vector<int>& cost){
        // Base case 
        if( n == 1) return dp[1]=cost[1];
        if( n==0) return dp[0] = cost[0];

        // Step 2 : Check if val already computed 
        if( dp[n]!= -1) return dp[n];

        // Step 3 :store val in dp 
        if( n == cost.size()){
            dp[n] = min(func(n-1 , dp , cost) ,func(n-2 ,dp , cost));
        }else{
            dp[n] =min(func(n-1 , dp , cost) ,func(n-2 ,dp , cost)) + cost[n];
        }
        
        return dp[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // cost does not have the last value as no cost to jump from there 

        // vector<int> dp( n + 1 , -1);
        //TC:O(n) and SC:O(n)
        // return func(n,dp , cost ) ;

        // // DP : Method 2 : Bottom up
        // vector<int> dp(n+1 , -1 );
        // dp[0] = cost[0];
        // dp[1]=cost[1];

        // for(int i = 2 ; i <= n ; i++){
        //     if( i == cost.size()){
        //         dp[i] = min(dp[i-1],dp[i-2]);
        //     }else{
        //         dp[i] =min(dp[i-1],dp[i-2]) + cost[i];
        //     }
        // }

        // // Again TC:(n) and SC:O(n)
        // return dp[n];

        // Space optimised

        int prev1 = cost[1] ;
        int prev2 = cost[0] ;

         for(int i = 2 ; i <= n ; i++){
            int curr = 0 ;
            if( i == cost.size()){
                curr = min(prev1,prev2);
            }else{
                curr =min(prev1,prev2) + cost[i];
            }

            prev2 = prev1 ;
            prev1 = curr;
        }

        //TC:O(n) and SC:O(1)
        return prev1;


    }
    
};
