/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // // Brute Force -- Store k elements first and then just place them at the end 
        // // Rotate the rest appropriately 
        // int n = nums.size();

        // k = k % n ; 

        // //TC:O(n-(n-k)) = TC:O(k)
        // vector<int> temp(nums.begin() + (n-k) , nums.end());

        // //TC:(n - k)
        // // Shift the other elements 
        // for(int i = n - 1 ; i >=k ; i--){
        //     nums[i] = nums[i - k];
        // }

        // // Now place the elements in temp at the beginning
        // //TC:O(k)
        // for(int i = 0 ; i < k ; i++){
        //     nums[i] = temp[i];
        // }

        // //TC:O(k + n - k + k) = TC:O(n + k)
        // //SC:O(k)
        // return  ;


        //Optimal 

        int n = nums.size();
        k = k % n ; 

        //TC:O(n)
        reverse(nums.begin() , nums.end());

        //TC:O(k)
        reverse(nums.begin() , nums.begin() + k);

        //TC:O(n-k)
        reverse(nums.begin() + k , nums.end());

        //TC:O(n+k+n-k) = TC:O(2n) and SC:O(1)
        return ;



    }
};