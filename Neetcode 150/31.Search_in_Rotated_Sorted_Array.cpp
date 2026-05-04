/*
You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Given the rotated sorted array nums and an integer target, return the index of target within nums, or -1 if it is not present.

You may assume all elements in the sorted rotated array nums are unique,

A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:

Input: nums = [3,4,5,6,1,2], target = 1

Output: 4
Example 2:

Input: nums = [3,5,6,0,1,2], target = 4

Output: -1
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-1000 <= target <= 1000
All values of nums are unique.
nums is an ascending array that is possibly rotated.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Unique elements 
        // Keywords "sorted" and "search" so think of binary search 

        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while( start<=end){
            int mid = start + (end - start) / 2;

            // Here think of two things separately
            // First fully sorted [1,2,3,4,5,6] , so here both halves are always sorted
            // In here since both parts are sorted , our approach handles this by checking which part explicitly conatains the answer

            // Second : rotated like [3,4,5,6,1,2] , so here at all times one half will be sorted and other half will not be sorted
            // Halves are seen as [start ,mid] and [mid , end] -> mid appears in both 


            // We will find the sorted half , to eliminate one partion 
            // Because that it is how Binary search works , we eliminate halfs 
            // n -> n/2 -> n/4 and so on 

            if( nums[mid] == target ){
                return mid ;
            }

            // The next condtion is when duplictes are allowed 
            // This handles the only case when duplicates break the solution , if no dulicates , skip this one else if 
            else if ( nums[mid] == nums[start] && nums[mid]==nums[end]){
                start ++;
                end--;
                continue ;
            }

            else if( nums[start] <= nums[mid]){
                // First half is sorted , we check if answer is here 

                if( target >= nums[start] && target<=nums[mid]){
                    // If answer is here , search in here and eliminate right half 
                    end = mid - 1;
                }else{
                    // Answer not here eliminate this half
                    start = mid + 1;
                }
            }
            else{
                // Right half sorted 
                if( target >= nums[mid] && target<=nums[end]){
                    // If answer is here , search in here and eliminate left half 
                    start = mid + 1;
                }else{
                    // Answer not here eliminate this half
                    end = mid - 1;
                }
            }     
        }
        

        //TC:O(logn) and SC:O(1)
        // Not here but if duplcates present can take TC:O(n/2 ) approx 
        return -1 ;
    }
};
