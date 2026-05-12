/*
You are given an array nums of integers, which may contain duplicates. Return all possible subsets.

The solution must not contain duplicate subsets. You may return the solution in any order.

Example 1:

Input: nums = [1,2,1]

Output: [[],[1],[1,2],[1,1],[1,2,1],[2]]
Example 2:

Input: nums = [7,7]

Output: [[],[7], [7,7]]
Constraints:

1 <= nums.length <= 11
-20 <= nums[i] <= 20
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums ,vector<vector<int>> &ans ,vector<int> &temp ,int index ){
        if(index >= nums.size()){
            ans.push_back(temp);
            return ;
        }

        ans.push_back(temp);

        for(int i = index ; i < nums.size() ; i++){
            if(i > index && nums[i]==nums[i-1]) continue ;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans ;
        vector<int> temp  ;
        int index  = 0 ; 
        solve(nums,ans,temp,index) ;

        //TC:O(2^n*n) and SC:O(n)
        return ans ;
    }
};
