/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // // Brute Force 
        // // Find all subarrays and save valid ones 

        // int count = 0 ;

        // for(int i = 0 ; i < nums.size() ; i++){
        //     int sum = 0 ;
        //     for(int j = i ; j < nums.size() ; j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }

        // //TC:O(n^2) and SC(1)
        // return count ;

        // Better - USE prefix sum  -- > Change the code that this used to find the longest subarry with sum k 

        int count = 0 ;

        int prefixSum = 0 ;
        unordered_map<int,int> mp; // Stores how many prefixSum - k are present 

        for(int i = 0 ; i < nums.size() ; i++){
            prefixSum += nums[i];

            if( prefixSum == k){
                count++;
            }

            int required = prefixSum - k ;

            if(mp.find(required) != mp.end()){
                count += mp[required];
            }

            mp[prefixSum]++;
        }

        //TC:O(n) and SC:O(n)
        return count ;
    }
};