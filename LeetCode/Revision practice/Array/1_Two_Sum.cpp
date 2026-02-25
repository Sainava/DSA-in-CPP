/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Three Ways 

        // // Brute Force  - NOT OPTIMAL 
        // // Double loop 

        // for( int i = 0 ; i < nums.size() ; i++){
        //     for (int j = 0 ; j < nums.size() ; j++){
        //         if(nums[i] + nums[j] == target && i!=j ){
        //             return {i,j};
        //         }
        //     }
        // }

        // //TC:O(n^2)
        // return {};

        // // Sort and two pointer  -- > This would fail because you need indices and after sorting , indices changes

        // int i = 0 ;
        // int j = nums.size() - 1;

        // sort(nums.begin() , nums.end());

        // while(i<j){
        //     if( nums[i] + nums[j] == target ){
        //         return {i,j};
        //     }
        //     else if (nums[i] + nums[j] < target ){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }

        // return {};

        // Hasp Map 
        unordered_map<int , int > mp ; // store value and its index 

        for (int i = 0 ; i < nums.size() ; i++){

            int complement  = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {mp[complement] , i };
            }

            // Else add to map 

            mp[nums[i]] = i ;

            }

            //TC and SC:O(n)
            return {};
    }
};