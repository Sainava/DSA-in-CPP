/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 

Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // Longest subarray that is mountain -- THINK OF SLIDING WINDOW 

        int up = 0 ; // Tracks the increasing subarray 
        int down = 0 ; // Tracks the decreasing subarray 
        int maxLength = 0 ;

        for(int i = 1 ; i < arr.size() ; i++){

            // If increasing starts after decreasing we need to reset the window 
            // And if equal elements see - reset the window 
            if (down > 0 && arr[i] > arr[i-1] || arr[i]==arr[i-1]){
                up = 0 ;
                down = 0;
            }

            // Check for increasing
            if( arr[i] > arr[i-1]){
                up++;
            }
            else if(arr[i] < arr[i-1]){
                down++;
            }

            if(up > 0 && down > 0){
                maxLength = max(maxLength , up + down + 1);
            }
            
        }

        //TC:O(n) and SC:O(1)
        return maxLength ;
    }
};