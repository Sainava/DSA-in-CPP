/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void solve (int index , vector<int>& nums , vector<vector<int>> &ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size() ; i++ ){
            swap( nums[index] , nums[i]);
            solve( index + 1 , nums , ans);
            //redo the previous swap so that the next iteration works well 
            swap( nums[index] , nums[i]);
        }

        return ;


    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve( 0 , nums , ans );

        // TC : O( n! x n) 
        // Each lead node is ans and there are n! leaf nodes (since total number of permutations )
        // The depth at each node will be n ( as each index is called from starting)
        // so approx TC:(n! x n )

        // SC:O(n) as max recursion depth extra space 
        // and SC:O(n! x n ) for the answer
        return ans;

    }
};