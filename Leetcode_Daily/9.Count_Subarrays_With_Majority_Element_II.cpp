// 26 June 2026
//3739. Count Subarrays With Majority Element II

/*
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

 

Example 1:

Input: nums = [1,2,2,3], target = 2

Output: 5

Explanation:

Valid subarrays with target = 2 as the majority element:

nums[1..1] = [2]
nums[2..2] = [2]
nums[1..2] = [2,2]
nums[0..2] = [1,2,2]
nums[1..3] = [2,2,3]
So there are 5 such subarrays.

Example 2:

Input: nums = [1,1,1,1], target = 1

Output: 10

Explanation:

​​​​​​​All 10 subarrays have 1 as the majority element.

Example 3:

Input: nums = [1,2,3], target = 4

Output: 0

Explanation:

target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

 

Constraints:

1 <= nums.length <= 10​​​​​​​5
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class FenwickTree {
    public:
        vector<int> bit;
        int n;

        FenwickTree(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        // Add delta at index idx (1-based)
        void update(int idx, int delta) {
            while (idx <= n) {
                bit[idx] += delta;
                idx += idx & (-idx);
            }
        }

        // Returns sum from 1..idx
        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Same transformation as before
        for (int &x : nums)
            x = (x == target ? 1 : -1);

        // Same prefix sums as before
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        //---------------------------------------------------------
        // NEW PART: Coordinate Compression
        //---------------------------------------------------------

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        FenwickTree bit(vals.size());

        long long ans = 0;

        for (int x : prefix) {

            // compressed index (1-based)
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums STRICTLY smaller than x
            ans += bit.query(idx - 1);

            // Insert current prefix sum
            bit.update(idx, 1);
        }

        // TC:
        // 1. Transform array (+1 / -1)              -> O(n)
        // 2. Build prefix sum                       -> O(n)
        // 3. Coordinate compression (sort + unique)-> O(n log n)
        // 4. For each prefix sum:
        //      - Binary search (lower_bound)        -> O(log n)
        //      - Fenwick query                      -> O(log n)
        //      - Fenwick update                     -> O(log n)
        //    Total for all prefix sums              -> O(n log n)
        //
        // Overall TC: O(n log n)
        //
        // SC:
        // prefix array      -> O(n)
        // compressed values -> O(n)
        // Fenwick Tree      -> O(n)
        //
        // Overall SC: O(n)
        return ans;
    }
};