// 26 July 2026 

//628. Maximum Product of Three Numbers

/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int largest3 = INT_MIN;

        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;

        for (int num : nums) {

            // Update three largest numbers
            if (num >= largest1) {
                largest3 = largest2;
                largest2 = largest1;
                largest1 = num;
            }
            else if (num >= largest2) {
                largest3 = largest2;
                largest2 = num;
            }
            else if (num > largest3) {
                largest3 = num;
            }

            // Update two smallest numbers
            if (num <= smallest1) {
                smallest2 = smallest1;
                smallest1 = num;
            }
            else if (num < smallest2) {
                smallest2 = num;
            }
        }

        return max(
            largest1 * largest2 * largest3,
            smallest1 * smallest2 * largest1
        );
    }
};