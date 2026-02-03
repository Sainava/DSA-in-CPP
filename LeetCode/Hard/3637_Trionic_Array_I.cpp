/*
You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.

 

Example 1:

Input: nums = [1,3,5,4,2,6]

Output: true

Explanation:

Pick p = 2, q = 4:

nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
nums[4...5] = [2, 6] is strictly increasing (2 < 6).
Example 2:

Input: nums = [2,1,3]

Output: false

Explanation:

There is no way to pick p and q to form the required three segments.

 

Constraints:

3 <= n <= 100
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // Constraints say 0 < p < q < n - 1. 
        // This requires at least 4 elements (indices 0, 1, 2, 3 minimum).
        if (n < 4) return false;

        int i = 0;

        // 1. Walk UP to find peak 'p'
        while (i < n - 1 && nums[i] < nums[i+1]) {
            i++;
        }
        int p = i;

        // Peak p must be valid: 
        // p > 0 (must have increased) 
        // p < n - 1 (cannot be at the very end, need space for dec and inc)
        if (p == 0 || p == n - 1) return false;

        // 2. Walk DOWN to find valley 'q'
        while (i < n - 1 && nums[i] > nums[i+1]) {
            i++;
        }
        int q = i;

        // Valley q must be valid:
        // q > p (must have decreased)
        // q < n - 1 (cannot be at the very end, need space for final inc)
        if (q == p || q == n - 1) return false;

        // 3. Walk UP to the end
        while (i < n - 1 && nums[i] < nums[i+1]) {
            i++;
        }

        // If we reached the exact end of the array, it is Trionic
        return i == n - 1;
    }
};