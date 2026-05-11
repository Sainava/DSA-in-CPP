/*
Given an array nums of unique integers, return all the possible permutations. You may return the answer in any order.

Example 1:

Input: nums = [1,2,3]

Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [7]

Output: [[7]]
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,int index){
        if( index >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = index ; i < nums.size() ; i++){
            swap(nums[i] , nums[index]);
            solve(nums,ans,index+1);
            swap(nums[i] , nums[index]); // backtrack 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        int index = 0 ;
        solve(nums , ans , index ) ;

        // TC:O(n! * n )
        // As index 0 has n choices , 1 had n-1 choices , 2 has n-2 choices 
        // so n*(n-1)*(n-2) and so on 
        // SO n!
        // And n to copy to ans
        // SC:O(n)
        return ans ;
    }
};
