/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

// Solution 1 : Using Hash Map
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Solution 1 

        unordered_map<int,int> mp ;

        for(int i = 0 ;i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        vector<int> ans ;

        for(auto &p: mp){
            if(p.second == 1){
                ans.push_back(p.first);
            }
        }

        //TC:O(n) and SC:O(n)
        return ans;
    }
};

// Solution 2 : Using Bit Manipulation and BUCKETS
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Using bit manipulation and buckets 

        // First find the xor of the two distinct numbers 
        long xorr = 0 ; // long so that the least integer does not give a problem here 
        for(int i = 0 ; i < nums.size() ; i++ ){
            xorr = xorr ^ nums[i];
        }

        // xorr is essentially ans1 ^ ans2
        // In xorr --> only the bits which are different in the distinct numbers are set to 1 
        // Here find the rightmost set bit 

        int rightMost = (xorr & xorr -1) ^ xorr;
        // xorr & xorr -1 set the rightmost bit to 0 and then ^ xorr gives only that bit as all the other bits are the same 

        //Now based on this separate into two buckets
        // rightMost essentially contains the first bit from the right that is different in the two answers
        // So we separate the numbers based on that 
        // Since the others repeat we cancel them out leaving only the answers

        int bucket1 = 0 ;
        int bucket2 = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            
            // Which bucket contains which number does not matter 
            // That bit is 1 
            if( (nums[i] & rightMost) != 0){
                bucket1 = bucket1 ^ nums[i];
            }
            // That bit is 0 
            else{
                bucket2 = bucket2 ^ nums[i];
            }
        }

        vector<int> ans ;
        ans.push_back( bucket1);
        ans.push_back( bucket2);

        //TC:O(n) and SC:O(1)
        return ans;
    }
};