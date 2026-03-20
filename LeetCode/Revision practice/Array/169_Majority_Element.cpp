/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : Brute and Better 
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // //Brute 
        // for(int i = 0 ; i < n ; i++){
        //     int count = 0 ;

        //     for(int j = 0 ;j < n ; j++){
        //         if(nums[j] == nums[i]){
        //             count++;
        //             if(count > (n/2)){
        //                 return nums[i];
        //             }
        //         }
        //     }
        // }

        //TC:O(n^2) and SC:(1)
        // return -1 ;

        // Better - Use hash map 
        unordered_map<int,int> mp ;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > (n/2)){
                return nums[i];
            }
        }

        //TC:O(n) and SC:O(n)
        return -1;
    }
};

//Solution 2 : Boyer-Moore Voting Algorithm 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Algorithm 
        int n = nums.size();
        int element = nums[0];
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            }
            else if(nums[i] == element){
                count++;
            }else{
                count--;
            }
        }

        // Only check if the problem states that the array might not have a majority element
        // Check if it is correct ans 
        int finalCount = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==element){
                finalCount++;
                if(finalCount > (n/2)){
                    return element;
                }
            }
        }

        //TC:O(2n) or TC:O(n) when majority element always exists
        //SC:O(1)
        return -1;
    }
};