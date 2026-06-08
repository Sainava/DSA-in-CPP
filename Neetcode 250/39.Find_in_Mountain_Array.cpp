/*
(This problem is an interactive problem.)

An array arr is called a mountain array if and only if:

arr.length >= 3
There exists some index i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
You are given a mountain array mountainArr and an integer target, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
You can only make at most 100 calls to the function get(). Submissions making more than 100 calls will be judged as Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example 1:

Input: mountainArr = [2,4,5,2,1], target = 2

Output: 0
Example 2:

Input: mountainArr = [1,2,3,4,2,1], target = 6

Output: -1
Constraints:

3 <= mountainArr.length() <= 10,000
0 <= target, mountainArr.get(index) <= 1,000,000,000
*/

#include <iostream>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
   public:
     int get(int index);
     int length(){ };
 };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Find the peak element 
        // Then binary search on left half and right half 

        int n = mountainArr.length() ; 
        int peak = - 1; 

        int start = 0 ;
        int end = n - 1 ; 

        //TC:O(logn)
        while(start < end){
            int mid = start + (end - start) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
            else
                end = mid;
        }

        peak = start;

        // Now do binary search on left half and then right half 

        start = 0 ;
        end = peak ; 

        //TC:O(logn)
        while(start  <= end){
            int mid = start + (end - start) / 2 ; 

            int element = mountainArr.get(mid) ; 

            if(element == target){
                return mid ; 
            }
            else if (element < target){
                start = mid + 1 ; 
            }
            else{   
                end = mid - 1;
            }
        }

        start = peak + 1 ; 
        end = n - 1;

        //TC:O(logn)
        while(start  <= end){
            int mid = start + (end - start) / 2 ; 

            int element = mountainArr.get(mid) ; 

            if(element == target){
                return mid ; 
            }
            else if (element < target){
                end = mid - 1 ; 
            }
            else{   
                start = mid + 1;
            }
        }

        //TC:O(3logn) and SC:O(1)
        // For n ≤ 10000:
        // 3 * log₂(10000) ≈ 42 get is called which is below 100
        return -1 ; 
    }
};