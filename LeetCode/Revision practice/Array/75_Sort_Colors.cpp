/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1 : Brute and Better 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Soln 1 - Sort 
        // TC:O(nlogn) and SC:O(n)
        sort(nums.begin() , nums.end());
        return ;

        //Better 
        int count0=0;
        int count1=0;
        int count2=0;

        //TC:(n)
        for(int num:nums){
            if(num==0){
                count0++;
            }else if(num==1){
                count1++;
            }else{
                count2++;
            }
        }

        int index= 0 ;
        while(count0>0){
            nums[index++]=0;
        }
        while(count1>0){
            nums[index++]=1;
        }
        while(count2>0){
            nums[index++]=2;
        }
        //The above three loops have TC:O(n)

        // TC:O(2n)  and SC:O(1)
        return ;
    }
};

//Best Solution : Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Three pointer approach 

        int low = 0 ;
        int mid = 0 ;
        int high = nums.size() - 1;

        // KEY IDEA 
        // from 0 to (low - 1) -> Array contains 0
        // from low to (mid - 1) -> Array contains 1
        // from mid to high -> Array can contain anything in 0,1 or 2 in unsorted condition 
        // from high to n-1 -> Array contains 2

        // We start from mid= 0 to high = n-1 as entire array is unsorted (condition matching)
        // We keep on minimising this 

        while(mid <= high){
            // think at each step the above condtions it'll all make sense 
            if(nums[mid] == 0 ){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }

            else if ( nums[mid] == 1 ){
                mid++;
            }

            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }

        //TC:O(n)  as at every step we are sorting one element , so total n steps to sort n elements
        //and SC:(1)
        return ;
    }
};