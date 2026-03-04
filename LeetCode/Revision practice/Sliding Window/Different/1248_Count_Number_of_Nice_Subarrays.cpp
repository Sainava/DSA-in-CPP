/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }

        int l = 0 ;
        int r = 0 ;
        int count = 0 ;
        int sum = 0 ;

        while( r < nums.size()){
            sum += nums[r] % 2; // THis converts odd to 1 and even to 0

            while( sum > k){
                sum -= nums[l] % 2;
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count ;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Count Subarray with <condition>

        // Prerequisite - Binary Subarrays With Sum
        // Here just consider odd numbers as '1' and even numbers as '0'
        // This way you are essentially finding sum = k in subarray containing 1 and 0

        // Func counts no of subarrays with less than or equal to k odd numbers 
        int ans = func( nums , k) - func(nums , k -1 );

        //TC:O(2(2n)) and SC:O(1)
        return ans ;
    }
};