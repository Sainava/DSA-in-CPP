/*
You are given an array of distinct integers nums, sorted in ascending order, and an integer target.

Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.

Your solution must run in 
O
(
l
o
g
n
)
O(logn) time.

Example 1:

Input: nums = [-1,0,2,4,6,8], target = 4

Output: 3
Example 2:

Input: nums = [-1,0,2,4,6,8], target = 3

Output: -1
Constraints:

1 <= nums.length <= 10000.
-10000 < nums[i], target < 10000
All the integers in nums are unique.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0 ;
        int end = n - 1 ;
        int mid = start + ( end - start )/2;

        while ( start <= end){
            if(nums[mid] == target ){
                return mid;
            }else if ( nums[mid]< target ){
                start = mid + 1;
            }else{
                end = mid - 1;
            }

            mid = start + (end - start )/2;
        }

        //TC :O(logn) and SC:O(1)
        return -1;
    }
};
