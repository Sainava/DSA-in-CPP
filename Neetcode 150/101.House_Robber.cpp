/*
You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.

You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.

Example 1:

Input: nums = [1,1,3,3]

Output: 4
Explanation: nums[0] + nums[2] = 1 + 3 = 4.

Example 2:

Input: nums = [2,9,8,3,6]

Output: 16
Explanation: nums[0] + nums[2] + nums[4] = 2 + 8 + 6 = 16.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int index ,vector<int>& nums ,int n ,vector<int> &dp){
        if( index >=n) return 0 ;

        if(dp[index]!= -1) return dp[index];

        // Two options 
        // 1: steal from the house 
        // 2. Do not steal from the house 
        dp[index] =  max(nums[index] + solve(index + 2 , nums, n , dp) , solve(index + 1 , nums , n ,dp)) ;
        return dp[index];


        
    }
    int rob(vector<int>& nums) {
        // There are two options , either the robber steals from the house or does not steal from the house , 
        // If he steals to steal , he has to skip the next house 
        // Id he does not steal he can visit the next house 
        int n = nums.size();

        // // Top Down
        // vector<int> dp(n , -1);
        // int index = 0 ;
        // //TC:O(n) and SC:O(2n) for dp and recursion stack 
        // return solve(index , nums , n  ,dp) ;

        // // Bottom up 
        // vector<int> dp(n+2 , -1); // as n-1 may call n and n+1 so n+1 is the max we can call
        // dp[n] = dp[n+1] = 0 ;


        // for(int i = n-1 ; i >=0 ; i--){
        //     dp[i] = max(nums[i]+ dp[i+2] , dp[i+1]);
        // }

        // //TC:O(n) and SC:O(n)
        // return dp[0];

        //Space optimised 
        int next1 = 0 ;  // index + 1 
        int next2 = 0 ; // index + 2

        for(int i = n-1 ; i >=0 ; i--){
            int curr = max(nums[i]+ next2 ,next1);
            next2 = next1;
            next1 = curr;
        }

        //TC:O(n) and SC:O(1)
        return next1;

    }
};
