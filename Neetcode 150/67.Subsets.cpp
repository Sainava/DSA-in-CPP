/*
Given an array nums of unique integers, return all possible subsets of nums.

The solution set must not contain duplicate subsets. You may return the solution in any order.

Example 1:

Input: nums = [1,2,3]

Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [7]

Output: [[],[7]]
Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums ,vector<vector<int>> &ans ,vector<int> &temp , int index ){
        if( index >= nums.size()){
            ans.push_back(temp);
            return ;
        }

        // Move forward without taking this element 
        solve(nums,ans,temp,index+1);
        // Add this element to temp and move forward 
        temp.push_back(nums[index]);
        solve(nums,ans,temp,index+1);
        temp.pop_back(); // backtracking 

        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // At each element I either take it or leave it 
        int index = 0 ;
        vector<vector<int>> ans ;
        vector<int> temp ;

        solve(nums,ans,temp,index);

        //TC:(n*2^n) as for each index , function is called twice so O(2^n) and copying temp to ans takes O(n)
        // SC:O(n) maximum depth 
        return ans;

    }
};
