//24 July 2026

//3514.Number of Unique XOR Triplets II

/*
You are given an integer array nums.

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).

 

Example 1:

Input: nums = [1,3]

Output: 2

Explanation:

The possible XOR triplet values are:

(0, 0, 0) → 1 XOR 1 XOR 1 = 1
(0, 0, 1) → 1 XOR 1 XOR 3 = 3
(0, 1, 1) → 1 XOR 3 XOR 3 = 1
(1, 1, 1) → 3 XOR 3 XOR 3 = 3
The unique XOR values are {1, 3}. Thus, the output is 2.

Example 2:

Input: nums = [6,7,8,9]

Output: 4

Explanation:

The possible XOR triplet values are {6, 7, 8, 9}. Thus, the output is 4.

 

Constraints:

1 <= nums.length <= 1500
1 <= nums[i] <= 1500
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
               const int MAXX = 2048;

        vector<bool> present(MAXX, false);

        // Keep only distinct values
        for (int x : nums)
            present[x] = true;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));

        dp[0][0] = true;

        for (int v = 0; v < MAXX; v++) {

            if (!present[v]) continue;

            for (int cnt = 2; cnt >= 0; cnt--) {

                for (int xr = 0; xr < MAXX; xr++) {

                    if (dp[cnt][xr]) {
                        dp[cnt + 1][xr ^ v] = true;
                    }
                }
            }
        }

        vector<bool> answer(MAXX, false);

        // Every value itself is obtainable:
        // x ^ x ^ x = x
        for (int v = 0; v < MAXX; v++)
            if (present[v])
                answer[v] = true;

        // XOR of three distinct values
        for (int xr = 0; xr < MAXX; xr++)
            if (dp[3][xr])
                answer[xr] = true;

        int cnt = 0;

        for (bool ok : answer)
            if (ok)
                cnt++;

        return cnt;
    }
};