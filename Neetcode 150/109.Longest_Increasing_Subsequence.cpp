/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the relative order of the remaining characters.

For example, "cat" is a subsequence of "crabt".
Example 1:

Input: nums = [9,1,4,2,3,3,7]

Output: 4
Explanation: The longest increasing subsequence is [1,2,3,7], which has a length of 4.

Example 2:

Input: nums = [0,3,1,3,2,3]

Output: 4
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;


// Solution with O(n^2) time and O(n^2) space
class Solution {
public:
    int func(int index ,int prevIndex , vector<int>& nums , int n){
        // Base case 
        if(index == n ){
            // The length of LIS starting at index n(out of bounds) is ofcourse 0
            return 0 ;
        }

        // Either take or not take

        // Not take  -> index +1 and preIndex does not change and no change in length of subsequence
        int len =0 + func(index+1 , prevIndex , nums , n);

        // Take 
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            int take = 1 + func(index+1 , index , nums ,n);
            len = max(len , take);
        }

        return len ; 
        
    }

    int funcTopDown(int index ,int prevIndex , vector<int>& nums , int n ,vector<vector<int>> &dp){
        // Base case 
        if(index == n ){
            // The length of LIS starting at index n(out of bounds) is ofcourse 0
            return 0 ;
        }

        if(dp[index][prevIndex+1]!= -1) return dp[index][prevIndex+1] ;
        // Either take or not take

        // Not take  -> index +1 and preIndex does not change and no change in length of subsequence
        int len =0 + funcTopDown(index+1 , prevIndex , nums , n , dp);

        // Take 
        if((prevIndex) == -1 || nums[index] > nums[prevIndex]){
            int take = 1 + funcTopDown(index+1 , index , nums ,n ,dp);
            len = max(len , take);
        }

        return dp[index][prevIndex+1] = len ; 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int index = 0 ; 
        int prevIndex = -1 ; 

        //Recursion 
        //return func(index , prevIndex , nums , n ); // Gives the length of longest increasing subsequence starting at index with previous element = nums[prevIndex]

        vector<vector<int>> dp(n , vector<int> (n+1 , -1));
        //dp[index][prevIndex] ==  Gives the length of longest increasing subsequence starting at index with previous element = nums[prevIndex]
        // we did prevIndex = n+1 as we shifter -1 to 0 , 0 to 1 and so on , as -1 cannot be index in array
        //TC:O(n^2) and SC:O(n^2)
        return funcTopDown(index , prevIndex  , nums , n ,dp);
    }
};
