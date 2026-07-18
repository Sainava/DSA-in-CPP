// 18 July 2026 

// 1979. Find Greatest Common Divisor of Array

/*
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
 

Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size() ;
        int smallest = INT_MAX ;
        int largest = INT_MIN ; 

        for(int i = 0 ; i < n ; i++){
            smallest = min ( smallest , nums[i]);
            largest = max(largest , nums[i]);
        }

        // TC: O(n)
        // - One pass to find the minimum and maximum.
        // - gcd() takes O(log(min(a, b))), which is negligible compared to O(n).
        //
        // Overall TC: O(n)
        //
        // SC: O(1)
        return gcd(smallest , largest) ;
    }
};