/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/
#include <iostream>
#include <vector>
using namespace std;

//Solution 1: Two pointer approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Intuition - Take all zeroes move to the beginning 

        int i = 0 ; 

        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] != 0){
                swap(nums[i] , nums[j]);
                i++;
            }
        }

        //TC:O(n) and SC:O(1)
        return ;
    }
};


// Better : / Less swaps but still not the minimum , becuase the swap can take 3 operations each time ( remember swap using temp variable )
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Intuition - Take all zeroes move to the beginning 

        int i = 0 ; 

        // Less swaps but still not the minimum , becuase the swap can take 3 operations each time ( remember swap using temp varibale )
        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] != 0){
                // To ensure less swaps
                if(i != j){
                    swap(nums[i] , nums[j]);  
                }
                i++;

            }
        }

        //TC:O(n) and SC:O(1)
        return ;
    }
};

// Best - No swaps at all , just assign the non zero elements to the correct position and then fill the rest with zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Intuition - Take all zeroes move to the beginning 

        int i = 0 ; 

        //Most optimal - DO not do swaps 
        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] != 0){
                // To ensure least operation swaps
                if(i != j){
                    nums[i] = nums[j];
                }
                i++;

            }
        }

        // Now since we did not swap , the values to the right of i may still have the non - zero values that we already copied to its required postion 

        while(i < nums.size()){
            nums[i]=0;
            i++;
        }

        //TC:O(n) and SC:O(1) but minimum operations 
        return ;
    }
};