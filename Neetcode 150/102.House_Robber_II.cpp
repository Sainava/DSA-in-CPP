/*
You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a circle, i.e. the first house and the last house are neighbors.

You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.

Example 1:

Input: nums = [3,4,3]

Output: 4
Explanation: You cannot rob nums[0] + nums[2] = 6 because nums[0] and nums[2] are adjacent houses. The maximum you can rob is nums[1] = 4.

Example 2:

Input: nums = [2,9,8,3,6]

Output: 15
Explanation: You cannot rob nums[0] + nums[2] + nums[4] = 16 because nums[0] and nums[4] are adjacent houses. The maximum you can rob is nums[1] + nums[4] = 15.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 200
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
        if( nums.size() == 1) return nums[0];

        // The circular makes it so that there is one problematic pair 
        // i.e ( first , last )
        // So we break this into two  
        // Ans 1 : from index 0 to n-2 , first may be included . but last is forbidden 
        // Ans 2 : from index 1 to n-1 , last may be included . but first is forbidden 
        // Then final ans = max ( ans1 , ans2 )

        int n = nums.size();

        // // Top Down
        // vector<int> dp1(n , -1);
        // //TC:O(n) and SC:O(2n) for dp and recursion stack 
        // int ans1 =  solve(0 , nums , n-1  ,dp1) ;
        // vector<int> dp2(n , -1); //As dp1 values only cater to first case 
        // int ans2 =  solve(1 , nums , n  ,dp2) ;

        // //TC:O(2n) and SC:O(4n)
        // return max(ans1,ans2);

        // // Bottom up 
        // vector<int> dp1(n+1 , -1); 
        // dp1[n-1] = dp1[n] = 0 ;

        // for(int i = n-2 ; i >=0 ; i--){
        //     dp1[i] = max(nums[i]+ dp1[i+2] , dp1[i+1]);
        // }

        // vector<int> dp2(n+2 , -1); 
        // dp2[n] = dp2[n+1] = 0 ;

        // for(int i = n-1 ; i >=1 ; i--){
        //     dp2[i] = max(nums[i]+ dp2[i+2] , dp2[i+1]);
        // }

        // //TC:O(2n) and SC:O(2n)
        // return max(dp1[0] , dp2[1]);


        //Space optimised 
        int next1 = 0 ;  // index + 1 
        int next2 = 0 ; // index + 2

        for(int i = n-2 ; i >=0 ; i--){
            int curr = max(nums[i]+ next2 ,next1);
            next2 = next1;
            next1 = curr;
        }

        int ans1 = next1;

        next1 = next2 = 0 ; 

        for(int i = n-1 ; i >=1 ; i--){
            int curr = max(nums[i]+ next2 ,next1);
            next2 = next1;
            next1 = curr;
        }

        int ans2 = next1;

         //TC:O(2n) and SC:O(1)
        return max(ans1,ans2);


    }
};
