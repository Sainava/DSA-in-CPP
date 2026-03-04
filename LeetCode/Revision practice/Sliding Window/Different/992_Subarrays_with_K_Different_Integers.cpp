/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0){
            return 0 ;
        }

        int l = 0 ;
        int r = 0 ;
        int count = 0 ;
        unordered_map<int,int> mp ; // <element , its frequency>

        while(r < nums.size()){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Count subarray with <condition> --THINK OF SLIDING WINDOW 


        // // Brute Force
        // int count = 0 ;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     unordered_map<int, int > mp; // <element , its count>
        //     for(int j = i ; j < nums.size() ; j++){
        //         mp[nums[j]]++;

        //         if(mp.size()==k){
        //              count++;
        //         }else if (mp.size() > k){
        //             break;
        //         }
        //     }
        // }

        // //TC:O(n^2) and SC:O(k)
        // return count ;

        // Better soultion 
        // Count the number of subarrays with less than or equal to k integers

        int ans = func(nums,k) - func( nums , k-1);

        //TC:O(2(2n)) and SC:(n) worst case 
        return ans ;
    }
};