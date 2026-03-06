/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std ;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Constant window size - k --> SO THINK OF SLIDING WINDOW 

        // int i = 0 ;
        // int j = 0 ;
        
        // unordered_map<int,int> mp; // frequency map;

        // while( j < nums.size()){
        //     if(abs(j - i ) >k){
        //         mp[nums[i]]--;
        //         if(mp[nums[i]] == 0){
        //             mp.erase(nums[i]);
        //         }
        //         i++;
        //     }

        //     if(mp.find(nums[j]) != mp.end()){
        //         return true ;
        //     }

        //     mp[nums[j]]++;
        //     j++;
        // }

        // //TC:O(n) and SC:O(k)
        // return false ;

        // Slightly better to use set since we do not need frequency only existence 
        unordered_set<int> window ;

        for(int i = 0 ; i < nums.size() ; i++){
            // .count returns 1 i element is present , 0 if not 
            if(window.count(nums[i])){
                return true ;
            }

            window.insert(nums[i]);

            if(window.size() > k){
                window.erase(nums[i-k]);
            }
        }

        //TC:O(n) and SC:O(k)
        return false ;
    }
};