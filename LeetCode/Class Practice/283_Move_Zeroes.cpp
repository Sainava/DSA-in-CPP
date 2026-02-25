/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Basic Idea -> Take all non zeroes -> push to the beginning 

        int i = 0 ; // To keep track of beginning of array , it wil be at a zero value when i != j
        // j will be non - zeroes 
        for(int j = 0 ; j < nums.size() ; j++){

            if(nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
            }
        }

        //TC:O(n) and SC:O(1)
    }
};