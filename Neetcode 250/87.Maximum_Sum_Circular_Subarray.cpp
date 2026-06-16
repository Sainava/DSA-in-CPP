/*
You are given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:

Input: nums = [-2,4,-5,4,-5,9,4]

Output: 15
Explanation: Subarray [-2,4,9,4] has maximum sum 15.

Example 2:

Input: nums = [2,3,-4]

Output: 5
Constraints:

n == nums.length
1 <= n <= 3 * 10,000
-30,000 <= nums[i] <= 30,000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // ------------------------------------------------------------
        // ALGORITHM
        // ------------------------------------------------------------
        //
        // 1. Find maximum subarray sum using Kadane.
        // 2. Find minimum subarray sum using Kadane.
        // 3. Compute total array sum.
        // 4. If all elements are negative:
        //        return maxSubarray.
        // 5. Else:
        //        return max(maxSubarray,
        //                   totalSum - minSubarray);

        int prefixMax = 0 ; 
        int maxSubarray = nums[0] ;

        int prefixMin = 0 ; 
        int minSubarray = nums[0] ;

        int total = 0 ; 

        for(int i = 0 ; i < nums.size() ; i++){
            total += nums[i] ; 

            // For maxSubarray 
            prefixMax += nums[i] ; 
            maxSubarray = max( maxSubarray , prefixMax);
            if ( prefixMax < 0) prefixMax = 0 ; 

            // For minSubarray 
            prefixMin += nums[i] ;
            minSubarray = min( minSubarray ,prefixMin );
            if( prefixMin > 0 ) prefixMin = 0 ;
        }

        // Edge case -> If all elements are negative then totalSum == minSubarray as we will take all elements as then
        // max( maxSubarray , total - minSubarray); = 0 as total - minSubarray = 0 but this is an invalid answer as we do not have a subarray that does that 
        // So in that case the maxSubarray is the answer 

        if( maxSubarray < 0) return maxSubarray ; // The greatest negative number 

        //TC:O(n) and SC:O(1)
        return max( maxSubarray , total - minSubarray);

// IMPORTANT OBSERVATION:
//
// We already know how to find the maximum subarray sum
// in a normal (non-circular) array using Kadane's Algorithm.
//
// However, in a circular array, the maximum subarray can be
// of TWO types:
//
// ------------------------------------------------------------
// CASE 1 : Non-Wrapping Subarray
// ------------------------------------------------------------
//
// Example:
//
// nums = [a, b, c, d, e]
//
// Maximum subarray could simply be:
//
// [b, c, d]
//
// This is exactly the normal Kadane answer.
//
// ------------------------------------------------------------
// CASE 2 : Wrapping Subarray
// ------------------------------------------------------------
//
// Example:
//
// nums = [a, b, c, d, e, f, g]
//
// A circular subarray may look like:
//
// [e, f, g, a, b]
//
// Notice something important:
//
// This wrapped subarray contains EVERY element
// except the middle segment:
//
// [c, d]
//
// Therefore:
//
// Wrapped Sum
// = Total Sum - Sum([c, d])
//
// To maximize the wrapped sum,
// we should remove the MINIMUM-SUM subarray.
//
// Hence:
//
// Maximum Wrapped Sum
// = Total Sum - Minimum Subarray Sum
//
// ------------------------------------------------------------
// EXAMPLE
// ------------------------------------------------------------
//
// nums = [5, -3, 5]
//
// Total Sum = 7
//
// Maximum Subarray (Kadane) = 7
//
// Minimum Subarray = [-3]
//
// Wrapped Answer:
//
// Total Sum - Minimum Subarray Sum
// = 7 - (-3)
// = 10
//
// This corresponds to taking:
//
// [5] + [5]
//
// around the circular boundary.
//
// ------------------------------------------------------------
// FINAL ANSWER
// ------------------------------------------------------------
//
// maxSubarray = Kadane Maximum Subarray Sum
//
// minSubarray = Kadane Minimum Subarray Sum
//
// totalSum = Sum of all elements
//
// wrappedAnswer = totalSum - minSubarray
//
// answer = max(maxSubarray, wrappedAnswer)
//
// ------------------------------------------------------------
// EDGE CASE : ALL NUMBERS NEGATIVE
// ------------------------------------------------------------
//
// Example:
//
// nums = [-3, -2, -3]
//
// maxSubarray = -2
//
// minSubarray = -8
//
// totalSum = -8
//
// wrappedAnswer
// = totalSum - minSubarray
// = -8 - (-8)
// = 0
//
// But 0 means we took NO elements,
// which is not allowed because the subarray
// must be non-empty.
//
// Therefore:
//
// if(maxSubarray < 0)
//     return maxSubarray;
//
// ------------------------------------------------------------
// ALGORITHM
// ------------------------------------------------------------
//
// 1. Find maximum subarray sum using Kadane.
// 2. Find minimum subarray sum using Kadane.
// 3. Compute total array sum.
// 4. If all elements are negative:
//        return maxSubarray.
// 5. Else:
//        return max(maxSubarray,
//                   totalSum - minSubarray);
//
// Time Complexity : O(n)
// Space Complexity: O(1)
    }
};