/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
 
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;
class Solution {
public:
    
    int func(vector<int>& nums, int goal){
        if(goal < 0 ){
            return 0 ;
        }

        int l = 0 ;
        int r = 0 ;
        int count = 0 ;
        int sum = 0 ;

        while ( r < nums.size()){
            sum += nums[r];

            while( sum > goal){
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count ;


    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Similar to count number of subarrays wiith sum k
        // Since that question had array which contained positive , negative and zeroes -> The most optimised solution used prefixSum
        // Here only 1 and 0 , so we can use sliding window and 2 pointers 

        // But here since zero is present , increasing l and r will make us miss solutions so we use different approach

        // func finds out number of subarrays where the sum is less than or equal to goal 
        int ans = func(nums , goal ) - func(nums , goal - 1);

        // func complexity is TC:O(2n) and SC:(1) and we call it two times 
        // Overall time complexity : TC:O(2(2n)) and SC:O(1)
        return ans;
    }
};