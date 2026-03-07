/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

#include<iostream>
#include<vector>
using namespace std ;

//Solution 1 : Using Hash Map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 4 solution 
        
        // 1 solution

        unordered_map<int,int> mp ;

        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }

        for(auto &p:mp){
            if(p.second==1){
                return p.first;
            }
        }

        // TC:O(n) and SC:O(n/3 + 1) 
        return -1;
    }
};

//SOLUTION 2 : Using Bit Manipulation
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        // 4 solution 

        // solution 2
        int ans = 0;
        for(int bitIndex = 0 ; bitIndex < 32 ; bitIndex++){

            // For each bit , check if set number is multiple of 3 --> if not that this means it is a set bit in out required answer 
            int count = 0;

            // Now check this bit for all the elements 

            for(int i = 0 ; i < nums.size() ; i++){

                if( (nums[i]>> bitIndex ) & 1){
                    count ++;
                }
            }

            if(count %3 != 0){
                // Set that bit to 1 
                ans = ans | (1<< bitIndex);
            }
        }

        //TC :O(n*32) and SC:(1)
        return ans;
    }
};

// Solution 3 : Sort and check every 3rd element
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        // 4 solution 

        // Solution 3 

        sort(nums.begin() , nums.end());

        for(int i = 1 ; i < nums.size() ; i = i+3){ // TC:O(n/3)

            if( nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }

        // TC : O(nlogn + n/3) and SC:O(1)
        return nums[nums.size() -1 ];
    }
};

// Solution 4 : Using bit manipulation and keeping track of bits seen once and twice
class Solution4 {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0 ;
        int twos = 0 ;

        for(int i = 0 ; i< nums.size() ; i++){
            
            // Toggle bits in ones and remove bits already counted twice
            ones =( ones ^ nums[i] ) & ~twos;

            // Add to twos if  not present in ones 
            twos = ( twos ^ nums[i] ) & ~ones;
        }

        //“ones stores bits seen once, twos stores bits seen twice, and when a bit appears the third time it gets cleared from both.”

        //TC:O(n)  and SC:O(1)
        return ones ;
    }
};

