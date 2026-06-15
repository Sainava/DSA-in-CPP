/*
You are given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [3,1,2], target = 4

Output: 7
Explanation: The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Example 2:

Input: nums = [1], target = 3

Output: 1
Constraints:

1 <= nums.length <= 200
1 <= nums[i], target <= 1000
All the elements of nums are unique.
Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

*/
#include <iostream>
#include <vector>
using namespace std;

// Top - Down 
class Solution {
public:
    int solve(int rem , vector<int>& nums , vector<int> &dp){
        if(rem == 0 ) return 1 ; 

        if(dp[rem]!= -1 ) return dp[rem] ; 

        int cnt = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            if( rem - nums[i] >= 0 ){
                cnt += solve( rem - nums[i] , nums , dp);
            }
        }

        return dp[rem] = cnt ; 
    }

    int combinationSum4(vector<int>& nums, int target) {
        //How many sequences can form the remaining sum?

        // Combination Sum IV is NOT an index-based or take/not-take DP.

        // It is a: dp[remaining_sum] problem 
        // BECAUSE  order matters.
        // FOR SUM = 3 both (1 + 2 ) and (2 + 1) are valid choices -> so the same indices can be taken in different 
        
        //Top-Down
        vector<int> dp(target + 1 , -1);
        //TC:O(n*target) and SC:O(target)
        return solve(target , nums , dp) ; 
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1 , 0);

        dp[0] = 1; 

        for(int rem = 1 ; rem <= target ; rem++){
            
            int cnt = 0 ; 
            for(int i = 0 ; i < nums.size() ; i++){
                if( rem - nums[i] >= 0 ){
                    cnt += dp[rem - nums[i]];
                }
            }

            dp[rem] = cnt ; 
        }

        //TC:O(n*target) and SC:O(target)
        return dp[target] ;

        // FOLLOW UP ANSWER 
        // If negative numbers are allowed, the number of valid
        // combinations may become infinite.
        //
        // Example:
        // nums = {1, -1}, target = 1
        //
        // We can form:
        //
        // 1
        // 1 + (-1) + 1
        // 1 + (-1) + 1 + (-1) + 1
        // ...
        //
        // infinitely many sequences.
        //
        // Therefore the original DP no longer works because
        // the state space is not finite.
        //
        // To allow negative numbers, we must impose an
        // additional restriction, such as limiting the
        // maximum number of elements that can be used.
        //
        // Then the DP state becomes:
        //
        // dp[remaining_sum][remaining_length]
        //
        // and the number of states becomes finite again.
    }
};