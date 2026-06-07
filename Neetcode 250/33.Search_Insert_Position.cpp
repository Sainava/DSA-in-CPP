/*
You are given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,2,4,6,8], target = 5

Output: 4
Example 2:

Input: nums = [-1,0,2,4,6,8], target = 10

Output: 6
Constraints:

1 <= nums.length <= 10,000.
-10,000 < nums[i], target < 10,000
nums contains distinct values sorted in ascending order.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0 ;
        int end = n - 1; 
        int mid = start + (end - start)/ 2;

        while( start <= end){

            if(nums[mid] == target){
                return mid ;
            }
            else if ( nums[mid] < target){
                start = mid + 1 ; 
            }
            else{
                end = mid - 1; 
            }

           mid = start + (end - start)/ 2;
        }

        //TC:O(logn) and SC:(1)
        return mid ; 
    }
};