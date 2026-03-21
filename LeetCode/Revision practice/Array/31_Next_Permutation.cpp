/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Brute Force - Find all permutations ( TC:O(n! x n))
        // Then linear search to fond the next permutation ( TC:O(n!))
        // Very high TC so we directly move to the optimal solution 

        int  n = nums.size() ; 

        // We can break this down into steps 
        
        // Step 1 : Find the break point 
        int index = -1 ; // index of the breakpoint 
        for(int i = n - 2 ; i>=0 ; i--){
            
            if ( nums[i] < nums[i+1]){
                index = i ;
                break;
            }
        }

        // Check if it is the last permutation : If yes return the first permutation 
        if(index == -1 ){
            reverse(nums.begin() , nums.end());
            return ;
        }


        // Step 2 : Swap the break point with the element that is just greater than it 

        for(int i = n -1 ; i >= index ; i--){
            if(nums[i] > nums[index]){
                swap(nums[i] , nums[index]);
                break;
            }
        }
        
        // Step 3
        // Now at position index , the next bigger elment is present which is what we wanted for the next permutation 
        // To the left of index , the array is sorted is descending order 
        // If we reverse it , we get the next permutation 

        reverse(nums.begin() + index + 1, nums.end());

        //TC:O(3n) as each step is approx TC:O(n)
        // and SC:O(1)
        return ;
    }
};