/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:

Input: nums = [0,1,1]

Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]

Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        //TC:O(nlogn)
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans ;

        //TC:O(n^2)
        for(int i = 0 ; i < n ; i++){
             
            if( i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n - 1;

            while( j < k){
               int sum = nums[i] + nums[j] + nums[k];

               if( sum == 0){
                ans.push_back( { nums[i] , nums[j] , nums[k] } );

                j++;
                k--;

                while ( j < k && nums[j]==nums[j-1]) j++;
                while ( j < k && nums[k]==nums[k+1]) k--;

               }

               else if ( sum < 0 ) j++;
               else k--;     

            }
        }

        //TC:O(n^2 + nlogn) and SC:O(logn) for sorting
        return ans;
    }
};
