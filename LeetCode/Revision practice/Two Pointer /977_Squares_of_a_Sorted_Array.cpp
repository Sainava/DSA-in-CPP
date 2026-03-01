/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Key Idea - The greatest square will come from the right most ( the most positive ) or the left most (the most negative) number 
        // So we can use two pointer approach here 

        int n = nums.size() ;

        int i  = 0 ; 
        int j = n - 1;
        int pos = n -1 ;

        // We build ans from the back side as we push the most positive element first 
        vector<int> ans(n);

        while( i <= j){
            if(abs(nums[j]) > abs(nums[i])){
                ans[pos] = pow(nums[j],2);
                pos--;
                j--;
            }else{
                ans[pos] = pow(nums[i],2);
                pos--;
                i++;
            }
        }

        //TC :O(n) and SC:O(1)
        return ans ;
    }
};