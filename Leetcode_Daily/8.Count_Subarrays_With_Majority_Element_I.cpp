// 25 June 2026

//3737. Count Subarrays With Majority Element I

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

1 <= nums.length <= 1000
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // Now we do not need to find the majority element for each subarray 
        // We just need to find "Is target the majority element here"

        // Now say size of a subarray is L 
        // Target will the majority element here if count(target) > L / 2
        // count(target) + count(others) = L => cnt(target) > ( cnt(target) + cnt(others) )/2 
        // cnt(target) > cnt(others) => cnt(target) - cnt(others) > 0 -> That is the condition 

        //Whenever you see "count A minus count B" over subarrays, what classic technique should come to mind?

        // Now lets think of transformation 
        // Key Transformation:
        //
        // Replace every occurrence of target with +1
        // Replace every other element with -1
        //
        // Example:
        // nums   = [1, 2, 2, 3], target = 2
        // becomes
        //         [-1, +1, +1, -1]
        //
        // Consider the subarray [2, 2, 3]:
        // It becomes [+1, +1, -1]
        // Sum = +1 +1 -1 = 1
        //
        // Notice that:
        //
        // Sum = (#target) - (#other)
        //
        // Here,
        // #target = 2
        // #other  = 1
        // Sum = 2 - 1 = 1
        //
        // Since target is a majority iff
        // #target > #other
        //
        // the condition becomes simply:
        //
        // Sum > 0
        //
        // Therefore, the problem reduces to:
        // Count the number of subarrays whose transformed sum is positive.

        // That way we do not need to use hashmaps and can save space 
        int n = nums.size() ; 
        for(int i =0 ; i < nums.size() ; i++){
            if( nums[i] == target) nums[i] = 1 ;
            else nums[i] = -1 ; 
        }

        // Next find the prefixSum Sum 

        vector<int>prefixSum(n + 1 , 0) ; // the first index sum is 0 
        // IMPORTANT : prefix[i] means the sum of the first i elements, not up to index i
        for(int i = 1 ; i <= n ; i++){
            prefixSum[i] = nums[i-1] + prefixSum[i - 1] ;
        }

        // Now consider a subarray from l to r -> [l , r] 
        // Sum of elements in that subarray is prefixSum[r] - prefixSum[l-1] 
        // For the condition we defined prefixSum[r] - prefixSum[l-1]  > 0 as sum of subarray should be positive 

        // BUT HERE 
        // Since prefixSum[i] stores the sum of the first i elements,
        // the sum of subarray [l, r] is:
        //
        // prefixSum[r + 1] - prefixSum[l]
        
        // Since positive can be anything , we cannot directly take the idea from no of subarrays with sum = k and apply it here 

        // The pattern to remember

        // Whenever you derive:
        // prefix[j] - prefix[i] = K -> Think HashMap (exact value).

        // Whenever you derive:
        // prefix[j] - prefix[i] > K
        // or
        // prefix[i] < prefix[j]

        // Think counting over a range. For small n, nested loops are fine. For large n, you need a data structure like a Fenwick Tree(watch striver video ), Segment Tree, or an ordered set to answer range-count queries efficiently.

        // IMPORTANT : prefix[i] means the sum of the first i elements, not up to index i
        int cnt = 0 ; 
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < j; i++) {
                if (prefixSum[j] > prefixSum[i]) {
                    cnt++;
                }
            }
        }

        //TC:O(n^2) and SC:O(n) , constraints n = 1000 so n^2 solution works 
        return cnt ; 
    }
};