/*
You are given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [2,-1,1,2], k = 2

Output: 4
Explanation: [2], [2,-1,1], [-1,1,2], [2] are the subarrays whose sum is equals to k.

Example 2:

Input: nums = [4,4,4,4,4,4], k = 4

Output: 6
Constraints:

1 <= nums.length <= 20,000
-1,000 <= nums[i] <= 1,000
-10,000,000 <= k <= 10,000,000
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum ; // sum , frequency of that sum 

        int n = nums.size() ;
        int r = 0 ;

        int cnt = 0 ;
        int currSum = 0 ;

        //TC:O(n)
        while( r < n){
            currSum += nums[r];

            if(currSum == k){
                cnt++ ;
            }

            // Now check if we can get our desired sum ;
            int required = currSum - k ;

            if(prefixSum[required]!= 0) cnt += prefixSum[required] ;

            prefixSum[currSum]++ ;
            r++;

        }

        //TC:O(n) and SC:O(n)
        return cnt ; 
    }
};