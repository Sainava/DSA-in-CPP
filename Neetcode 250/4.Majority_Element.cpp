/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times in the array. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [5,5,1,1,1,5,5]

Output: 5
Example 2:

Input: nums = [2,2,2]

Output: 2
Constraints:

1 <= nums.length <= 50,000
-1,000,000,000 <= nums[i] <= 1,000,000,000
Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
using namespace std;

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