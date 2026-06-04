/*
You are given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: target = 10, nums = [2,1,5,1,5,3]

Output: 3
Explanation: The subarray [5,1,5] has the minimal length under the problem constraint.

Example 2:

Input: target = 5, nums = [1,2,1]

Output: 0
Constraints:

1 <= nums.length <= 100,000
1 <= nums[i] <= 10,000
1 <= target <= 1,000,000,000
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/
#include <iostream>     
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Since all numbers are positive:
        //
        // Expanding the window increases the sum.
        // Shrinking the window decreases the sum.
        //
        // Therefore we can use a sliding window.

        int n = nums.size() ; 
        int l  = 0 ;
        int r = 0 ; 
        int minLength = INT_MAX ;
        int sum = 0 ; 
        while( r < n){
            sum += nums[r] ;

            while( sum >= target){
                minLength = min(minLength , r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }
        if( minLength == INT_MAX ) return 0 ; // No possible answer 

        // Every element traversed at max twice 
        // TC:O(2n) and SC:O(1)
        return minLength ;
    }
};