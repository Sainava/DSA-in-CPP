/*
You are given an integer array nums of length n.

A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

nums[l...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...r] is strictly increasing.
Return the maximum sum of any trionic subarray in nums.

 

Example 1:

Input: nums = [0,-2,-1,-3,0,2,-1]

Output: -4

Explanation:

Pick l = 1, p = 2, q = 3, r = 5:

nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
Example 2:

Input: nums = [1,4,2,7]

Output: 14

Explanation:

Pick l = 0, p = 1, q = 2, r = 3:

nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
Sum = 1 + 4 + 2 + 7 = 14.
 

Constraints:

4 <= n = nums.length <= 105
-109 <= nums[i] <= 109
It is guaranteed that at least one trionic subarray exists.
 

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        // Although constraints say n >= 4, safety check is good practice.
        if (n < 4) return 0; 

        // Initialize DP arrays with a very small number representing -Infinity
        // U1: Max sum of strict increasing subarray ending at i
        // D:  Max sum of Up-Down sequence ending at i
        // U2: Max sum of Up-Down-Up sequence ending at i
        vector<long long> U1(n, -1e18);
        vector<long long> D(n, -1e18);
        vector<long long> U2(n, -1e18);

        long long global_max = -1e18;

        // Base case for U1 at index 0
        U1[0] = nums[0];

        for (int i = 1; i < n; i++) {
            // -------------------------------------------------
            // 1. Update U1 (First Ascent)
            // -------------------------------------------------
            if (nums[i] > nums[i-1]) {
                // Either extend the previous ascent or start a new one here
                U1[i] = max((long long)nums[i], U1[i-1] + nums[i]);
            } else {
                // Must start a new ascent here
                U1[i] = nums[i];
            }

            // -------------------------------------------------
            // 2. Update D (Descent)
            // -------------------------------------------------
            if (nums[i] < nums[i-1]) {
                // Option A: Extend an existing Down leg
                if (D[i-1] > -1e17) {
                    D[i] = max(D[i], D[i-1] + nums[i]);
                }
                
                // Option B: Transition from Up to Down (Peak was at i-1)
                // A valid Peak at i-1 requires the ascent ending there to be length >= 2.
                // This implies nums[i-1] > nums[i-2].
                if (i >= 2 && nums[i-1] > nums[i-2]) {
                    // Check if valid ascent existed ending at i-2
                    if (U1[i-2] > -1e17) {
                        // Sum = (Best Up ending at i-2) + Peak(i-1) + Current(i)
                        D[i] = max(D[i], U1[i-2] + nums[i-1] + nums[i]);
                    }
                }
            }

            // -------------------------------------------------
            // 3. Update U2 (Second Ascent)
            // -------------------------------------------------
            if (nums[i] > nums[i-1]) {
                // Option A: Extend an existing Final Up leg
                if (U2[i-1] > -1e17) {
                    U2[i] = max(U2[i], U2[i-1] + nums[i]);
                }
                
                // Option B: Transition from Down to Up (Valley was at i-1)
                // We can switch to the final ascent if we had a valid Down leg ending at i-1.
                if (D[i-1] > -1e17) {
                    U2[i] = max(U2[i], D[i-1] + nums[i]);
                }
            }

            // Update the global maximum result if we have a valid Trionic sum
            if (U2[i] > global_max) {
                global_max = U2[i];
            }
        }

        return global_max;
    }
};