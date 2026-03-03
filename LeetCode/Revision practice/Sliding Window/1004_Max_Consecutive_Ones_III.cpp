/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Max Consecutive ( Subarray ) with <condition> -- THINK OF SLIDING WINDOW

        // THINK OF THIS LIKE MAX SUBARRAY WITH AT MOST TWO ZEROES 

        // // Brute force -- FIND ALL SUBARRAYS WITH ATMOST 2 ZEROES 


        // int maxLength = 0 ;

        // for(int i = 0 ; i < nums.size() ; i++){
        //     int zeroCount = 0 ;
        //     for(int j = i ; j < nums.size() ; j++){
        //         int num = nums[j];

        //         if(nums[j] == 0){
        //             zeroCount++ ;
        //         }

        //         if ( zeroCount <= k){
        //             maxLength = max(maxLength, j - i + 1);
        //         }else {
        //             break ;
        //         }

        //     }
        // }

        // //TC:O(n^2) and SC:O(1)
        // return maxLength ;

        // Optimised - SLIDING WINDOW 

        int l = 0 ;
        int r = 0 ;

        int maxLength= 0 ;
        int zeroCount = 0 ;

        // while ( r < nums.size()){
        //     // For the new window - Calculate no of zeroes 
        //     if(nums[r] == 0) zeroCount++ ;

        //     // Make the window valid if not 
        //     while ( zeroCount > k ){
        //         if(nums[l] == 0){
        //             zeroCount--;
        //         }
        //         l++;
        //     }

        
        //     maxLength = max(maxLength , r - l + 1);
        //     r = r + 1;

        // }

        //     //TC:O(n + n) and SC:O(1)
        // return maxLength;

        // More optimised

        while ( r < nums.size()){
            // For the new window - Calculate no of zeroes 
            if(nums[r] == 0) zeroCount++ ;

            // Make the window valid if not 
            if( zeroCount > k ){
                if(nums[l] == 0){
                    zeroCount--;
                }
                l++;
            } // Only move by 1 

            // Now check if window is valid -- Since we already have a max Length we do not need to check for length less than that 
            if( zeroCount<= k) maxLength = max(maxLength , r - l + 1) ;
            r = r + 1;

        }

        //TC:O(n) and SC:O(1)
        return maxLength;
        

    }
};