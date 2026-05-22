/*
You are given an array of positive integers nums.

Return true if you can partition the array into two subsets, subset1 and subset2 where sum(subset1) == sum(subset2). Otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]

Output: true
Explanation: The array can be partitioned as [1, 4] and [2, 3].

Example 2:

Input: nums = [1,2,3,4,5]

Output: false
Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 50
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool funcTopDown(int index , int target , int n ,vector<int> &arr ,vector<vector<int>> &dp){
        if( target == 0 ) return true ; 
        if(index == n || target < 0) return false ;

        if(dp[index][target]!= -1) return dp[index][target];
        
        // Either take or dont take 
        bool noTake = funcTopDown(index+1 , target ,n,arr ,dp );

        // Take 
        bool take  =funcTopDown(index + 1 , target - arr[index] , n , arr ,dp);

        return dp[index][target]= noTake || take ; 
    }
    bool canPartition(vector<int>& nums) {
        // So we need to partition the nums array into two subarrays 
        // This is the key part , not explicitly mentioned in question 
        // Partition means  mutually exclusive subsets but overall covers all elements 

        // So we need two subsets whose sum = Sum of Entire Array(S) / 2;
        int n = nums.size() ; 
        int sum = 0 ; 
        for (int num : nums){
            sum+= num;
        }

        if(sum %2 != 0 ){
            // Odd not possible so 
            return false ; 
        }

        // If even we have 
        int k = sum / 2; //target
        // Now if one subset equals sum / 2 then the remaining elements obviously equal sum/2 
        // As two subsets that cover the entire array 

        // So essentially question is find if a subarray whose sum is sum / 2;

        // // Top Down 
        // vector<vector<int>> dp(n , vector<int>(k+1, -1));
        // // dp[i][j] tells if it is possible to reach target j by taking or not taking i 
        // //TC:O(n*k) and SC:O(n*k)
        // return funcTopDown(0 , k, n , nums , dp);


        // // Bottom Up
        // vector<vector<int>> dp(n+1 , vector<int>(k+1, 0)) ;
        // // Entire dp[n][any number] = 0 
        // for(int i = 0 ; i <= n ; i++){
        //     dp[i][0] = 1 ; 
        // }

        // // Now traverse in reverse order 

        // for(int index = n-1 ; index >=0 ; index--){
        //     for(int target = 0 ; target <= k ; target++){
        //         // Either take or dont take 
        //         bool noTake = dp[index+1][target];

        //         bool take = false ; 
        //         // Take 
        //         if( target - nums[index] >=0 ){
        //             take = dp[index+1][target - nums[index]];
        //         }

        //     dp[index][target]= noTake || take ; 
        //     }
        // }
        // // //TC:O(n*k) and SC:O(n*k)
        // return dp[0][k];

        // Space optimised 
        vector<int> curr(k+1);
        vector<int> next(k+1);

        next[0] = 1;

        for(int index = n-1 ; index >=0 ; index--){
            for(int target = 0 ; target <= k ; target++){
                // Either take or dont take 
                bool noTake = next[target];

                bool take = false ; 
                // Take 
                if( target - nums[index] >=0 ){
                    take = next[target - nums[index]];
                }

            curr[target]= noTake || take ; 
            }
            next = curr;
        }
        // //TC:O(n*k) and SC:O(k)
        return curr[k];
    }
};
