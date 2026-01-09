/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // subarray - contiguous part of array 
        int n = nums.size() ;

        // // Brute Force 
        // int maxSum= INT_MIN;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         // The outer 2 loops give every possible subarray 

        //         int sum = 0 ; 
        //         for(int k = i ; k <= j ; k++ ){
        //             // This loops finds the sum of subarray 
        //             sum+=nums[k];
                    
        //         }

        //         maxSum = max(maxSum, sum );
        //     }
        // }

        // //TC : O(n^3)
        // return maxSum ;

        // // Better Solution
        // int maxSum= INT_MIN;
        // for(int i = 0 ; i < n ; i++){
        //     int sum = 0 ;
        //     for(int j = i ; j < n ; j++){
        //         // The outer 2 loops give every possible subarray 
        //         sum += nums[j];
        //         maxSum = max(maxSum, sum );      
        //     }
        // }

        // //TC : O(n^2)
        // return maxSum ;

        //Optimised - Kadane's Algorithm 

        int maxSum = INT_MIN;
        int sum = 0 ;

        for(int i = 0 ; i < n ; i++){
            
            // Step 1 - Add current element to sum 
            sum += nums[i];

            // Step 2 - Update max if possible 
            maxSum = max(maxSum , sum);

            // Step 3 - If sum is negative - do not carry forward 
            if(sum < 0){
                sum = 0 ;
            }
        }

        //TC : O(n) and SC:O(1)
        return maxSum ;
    }
};