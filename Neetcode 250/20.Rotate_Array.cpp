/*
You are given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7,8], k = 4

Output: [5,6,7,8,1,2,3,4]
Explanation:
rotate 1 steps to the right: [8,1,2,3,4,5,6,7]
rotate 2 steps to the right: [7,8,1,2,3,4,5,6]
rotate 3 steps to the right: [6,7,8,1,2,3,4,5]
rotate 4 steps to the right: [5,6,7,8,1,2,3,4]

Example 2:

Input: nums = [1000,2,4,-3], k = 2

Output: [4,-3,1000,2]
Explanation:
rotate 1 steps to the right: [-3,1000,2,4]
rotate 2 steps to the right: [4,-3,1000,2]

Constraints:

1 <= nums.length <= 100,000
-(2^31) <= nums[i] <= ((2^31)-1)
0 <= k <= 100,000
Follow up: Could you do it in-place with O(1) extra space?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ; 

        k = k % n ;
        // Rotate to the right so kth element from end moving left will be the first element 

        reverse(nums.begin() , nums.end()) ;

        reverse(nums.begin(), nums.begin() + k ); // Remember it is [begin() , end() ) , i.e begin index is included but end index is excluded 

        reverse(nums.begin() + k, nums.end() );

        //TC:O(n) and SC:(1)
    }
};