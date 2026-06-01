/*
You are given an array nums consisting of n elements where each element is an integer representing a color:

0 represents red
1 represents white
2 represents blue
Your task is to sort the array in-place such that elements of the same color are grouped together and arranged in the order: red (0), white (1), and then blue (2).

You must not use any built-in sorting functions to solve this problem.

Example 1:

Input: nums = [1,0,1,2]

Output: [0,1,1,2]
Example 2:

Input: nums = [2,1,0]

Output: [0,1,2]
Constraints:

1 <= nums.length <= 300.
0 <= nums[i] <= 2.
Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Three pointer approach 

        int low = 0 ;
        int mid = 0 ;
        int high = nums.size() - 1;

        // KEY IDEA 
        // from 0 to (low - 1) -> Array contains 0
        // from low to (mid - 1) -> Array contains 1
        // from mid to high -> Array can contain anything in 0,1 or 2 in unsorted condition 
        // from high + 1 to n-1 -> Array contains 2

        // We start from mid= 0 to high = n-1 as entire array is unsorted (condition matching)
        // We keep on minimising this 

        while(mid<=high){
            if( nums[mid] == 0 ){
                swap(nums[mid] , nums[low]);
                low++;
                mid++;
            }
            else if( nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }

        // TC:O(n) and SC:O(1)
    }
};