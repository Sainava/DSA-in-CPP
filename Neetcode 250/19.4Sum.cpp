/*
You are given an integer array nums of size n, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Note: [1,0,3,2] and [3,0,1,2] are considered as same quadruplets.

Example 1:

Input: nums = [3,2,3,-3,1,0], target = 3

Output: [[-3,0,3,3],[-3,1,2,3]]
Example 2:

Input: nums = [1,-1,1,-1,1,-1], target = 2

Output: [[-1,1,1,1]]
Constraints:

1 <= nums.length <= 200
-1,000,000,000 <= nums[i] <= 1,000,000,000
-1,000,000,000 <= target <= 1,000,000,000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size() ; 

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans ; 

        // Remember indices i , j , k and l must be distinct 

        for(int i = 0 ; i < n - 3  ; i ++){
            if( i > 0 && nums[i] == nums[i-1]) continue ;

            for(int j = i + 1 ; j < n - 2 ; j++){
                if ( j > i + 1 && nums[j]==nums[j-1]) continue ;

                int k = j + 1;
                int l = n - 1 ; 

                while ( k < l){
                    long long  sum = (long long)nums[i] + nums[j] + nums[k] + nums[l] ;

                    if ( sum == target ){
                        ans.push_back({nums[i] , nums[j] , nums[k++] , nums[l--]});

                        while( k < l && nums[k] == nums[k-1]) k++;
                        while( k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if ( sum > target) l--;
                    else k++;
                }
            }
        }

        //TC:O(n^3) and SC:O(1)
        return ans ;

    }   
};