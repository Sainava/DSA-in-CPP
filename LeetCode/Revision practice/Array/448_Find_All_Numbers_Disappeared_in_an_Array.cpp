/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

 

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans ;

        // // Brute force -- Frequency array 
        // int n = nums.size();
        // vector<int> freq(n+1 ,0);

        // for(int num:nums){
        //     freq[num]++;
        // }

        // for( int i = 1 ; i <= n  ;i++){
        //     if(freq[i] == 0 ){
        //         ans.push_back(i);
        //     }
        // }

        // //TC : O(n) and SC:O(n)
        // return ans;

        // Optimised solution 
        // USE MASKING 
        // SINCE SIZE OF ARRAY IS N AND NUMBERS ARE FROM 1 TO N . That means some will be repeated and some will be missing 
        // But what is important is that we can create a mapping 
        // Map number to index= number -1 
        //like if 3 appears we mark index 2 as negative (indicating this has appeared)

        int n= nums.size();

        for(int i =0 ; i < n ; i++){

            int index = abs(nums[i]) - 1 ;
            
            if(nums[index] > 0){
                // Check to see so that we dont re-flip the sign
                nums[index] = -nums[index] ; // We negate the number already in index , not the number i
            }
        }

        for( int i = 0 ; i < n ;i++){
            if(nums[i] > 0){
                ans.push_back( i + 1);
            }
        }

        //TC :O(n) and SC:O(1)
        return ans ;
        
    }
};