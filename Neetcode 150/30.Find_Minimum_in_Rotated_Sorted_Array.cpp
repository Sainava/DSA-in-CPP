/*
You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Notice that rotating the array 4 times moves the last four elements of the array to the beginning. Rotating the array 6 times produces the original array.

Assuming all elements in the rotated sorted array nums are unique, return the minimum element of this array.

A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:

Input: nums = [3,4,5,6,1,2]

Output: 1
Example 2:

Input: nums = [4,5,0,1,2,3]

Output: 0
Example 3:

Input: nums = [4,5,6,7]

Output: 4
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int start = 0 ;
        int end = n - 1;
        int mini = INT_MAX;
        
        while( start <= end){
            int mid = start + ( end - start) / 2;

            // See search in a rotated sorted array for better understanding
            // Again identify which is sorted half

            // We can say the answer will be in the unsorted half or it will be the minimum element of the sorted half


            // The fully sorted array is handled beacuse we are always storing the minimum answer of each half 
            // The folllwing is an optimisation , it works without this if loop as well
            // THis handles the fully sorted and also anytime later if we pass the rotation point and both start and end are in the same roatetd half

            if( nums[start] <= nums[end]){
                // If already sorted that is nums[start] <= nums[mid] <= nums[end] no need do binary search further
                mini = min(mini , nums[start]);
                break;
            }

            // Again if duplicates do this , not needed here 
            else if ( nums[mid] == nums[start] && nums[mid]==nums[end]){
                start ++;
                end--;
                continue ;
            }
            

            if( nums[start] <= nums[mid]){
                //left half is sorted
                // Its minimum can be answer so save and then search in the right half
                mini = min(mini , nums[start]);
                start = mid+1;
            }else{
                // Right half is sorted 
                mini = min(mini , nums[mid]);
                end = mid  - 1;
            }
            
        }
        
        // TC :O(logn) and SC:O(1)
        // Not here but if duplcates present can take TC:O(n/2 ) approx 
                //** The no of times array has been rotated is just index of the minimum(called pivot) element
        return mini ;
    }
};
