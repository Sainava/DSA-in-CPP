/*
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in 
O
(
n
)
O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]
Example 2:

Input: nums = [-1,0,1,2,3]

Output: [0,-6,0,0,0]
Constraints:

2 <= nums.length <= 1000
-20 <= nums[i] <= 20

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // int n = nums.size();

        // //TC:O(n) and SC:O(n)
        // vector<int> left(n , 0);
        // vector<int> right(n , 0) ;

        // left[0]= 1;


        // for(int i = 1 ; i < n ; i++){
        //     left[i] = ( left[i-1] * nums[i-1]);
        // }

        // right[n-1] = 1;

        // for(int i = n - 2 ; i >=0 ; i--){
        //     right[i] = right[i+1] * nums[i+1];
        // }

        // vector<int> ans ;

        // for(int i = 0 ; i < n ; i++){
        //     ans.push_back(left[i] * right[i]);
        // }

        // //TC:O(3n) and SC:O(3n)
        // return ans;

        // A bit optimised 

         int n = nums.size();

        //TC:O(n) and SC:O(n)
        vector<int> ans; // we will use this as extra space and final space

        int prefix = 1;

        for(int i = 0 ; i < n ; i++){
            ans.push_back(prefix);
            prefix = prefix * nums[i];
        }

        int suffix = 1;

        for(int i = n-1 ; i >=0 ; i--){
            prefix = ans[i];
            ans[i] = prefix * suffix ;

            suffix = suffix*nums[i];
        }

        //TC:O(2n) and SC:O(1) extra space , O(n) for the answer
        return ans ;

    }
};
