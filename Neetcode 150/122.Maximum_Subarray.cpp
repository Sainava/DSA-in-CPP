/*
iven an array of integers nums, find the subarray with the largest sum and return the sum.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [2,-3,4,-2,2,1,-1,4]

Output: 8
Explanation: The subarray [4,-2,2,1,-1,4] has the largest sum 8.

Example 2:

Input: nums = [-1]

Output: -1
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm 
        int n = nums.size() ; 
        int prefix = 0 ;
        int maxSum = nums[0] ;


        for(int i = 0 ; i < n ; i++){
            prefix += nums[i] ;

            maxSum = max(maxSum , prefix) ; // We do this before 

            if(prefix < 0) prefix = 0 ;

        }

        //TC:O(n) and SC:O(1)
        return maxSum ; 
    }
};
