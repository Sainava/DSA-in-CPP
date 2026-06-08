/*
You are given an array of length n which was originally sorted in non-decreasing order (not necessarily with distinct values). It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Given the rotated sorted array nums and an integer target, return true if target is in nums, or false if it is not present.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [3,4,4,5,6,1,2,2], target = 1

Output: true
Example 2:

Input: nums = [3,5,6,0,0,1,2], target = 4

Output: false
Constraints:

1 <= nums.length <= 5000
-10,000 <= target, nums[i] <= 10,000
nums is guaranteed to be rotated at some pivot.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(); 

        int start = 0 ; 
        int end = n - 1 ; 

        while(start <= end){
            int mid = start + (end - start)/2 ; 

            if( nums[mid] == target){
                return true ; 
            }

            else if ( nums[start]== nums[mid] && nums[mid]== nums[end]){
                // Handles the case where duplicate elements cause problem
                start++;
                end--;
                continue ;
            }
            
            else if( nums[start] <= nums[mid]){
                // Sorted half 

                if( nums[start] <= target && target<= nums[mid] ){
                    end = mid  - 1;
                }else{
                    start = mid + 1 ;
                }
            }
            else{
                if( nums[mid] <= target && target<= nums[end] ){
                    start = mid  + 1;
                }else{
                    end = mid - 1 ;
                }
            }


        }

        //TC:O(logn) and SC:O(1)
        return false ; 


    }
};