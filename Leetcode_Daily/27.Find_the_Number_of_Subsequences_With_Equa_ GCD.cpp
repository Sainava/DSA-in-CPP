// 14 July 2026

// 3336. Find the Number of Subsequences With Equal GCD

/*
You are given an integer array nums.

Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:

The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
Return the total number of such pairs.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 10

Explanation:

The subsequence pairs which have the GCD of their elements equal to 1 are:

([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
Example 2:

Input: nums = [10,20,30]

Output: 2

Explanation:

The subsequence pairs which have the GCD of their elements equal to 10 are:

([10, 20, 30], [10, 20, 30])
([10, 20, 30], [10, 20, 30])
Example 3:

Input: nums = [1,1,1,1]

Output: 50

 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 200
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        int n = nums.size();

        int MAX = 0;
        for (int x : nums)
            MAX = max(MAX, x);

        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {

            vector<vector<int>> ndp = dp;

            for (int g1 = 0; g1 <= MAX; g1++) {

                for (int g2 = 0; g2 <= MAX; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;

                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    int ng2 = (g2 == 0 ? x : gcd(g2, x));

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + dp[g1][g2]) % MOD;

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {

            ans += dp[g][g];
            ans %= MOD;
        }

        // TC:
        // O(n × MAX² × log(MAX))
        //
        // MAX = 200
        //
        // Overall ≈ 8 × 10^6 operations
        //
        // SC:
        // O(MAX²)
        return ans;
    }
};