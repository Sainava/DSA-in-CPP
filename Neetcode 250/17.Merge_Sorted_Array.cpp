/*
You are given two integer arrays nums1 and nums2, both sorted in non-decreasing order, along with two integers m and n, where:

m is the number of valid elements in nums1,
n is the number of elements in nums2.
The array nums1 has a total length of (m+n), with the first m elements containing the values to be merged, and the last n elements set to 0 as placeholders.

Your task is to merge the two arrays such that the final merged array is also sorted in non-decreasing order and stored entirely within nums1.
You must modify nums1 in-place and do not return anything from the function.

Example 1:

Input: nums1 = [10,20,20,40,0,0], m = 4, nums2 = [1,2], n = 2

Output: [1,2,10,20,20,40]
Example 2:

Input: nums1 = [0,0], m = 0, nums2 = [1,2], n = 2

Output: [1,2]
Constraints:

0 <= m, n <= 200
1 <= (m + n) <= 200
nums1.length == (m + n)
nums2.length == n
-1,000,000,000 <= nums1[i], nums2[i] <= 1,000,000,000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1 ;

        int k = m + n - 1 ;

        // i -> last valid element in nums1
        // j -> last element in nums2
        // k -> position where next largest element goes

        //TC:O(m+n)
        while ( j >= 0){
            if( i >= 0 && nums1[i] >= nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
// Why do we use:
//
// while(j >= 0)
//
// instead of:
//
// while(i >= 0 && j >= 0)
//
// --------------------------------------------------------------------
// Key Observation:
//
// Remaining elements in nums1 are already in their correct positions.
// Remaining elements in nums2 MUST still be copied.
//
// Therefore we only need to keep running until nums2 is exhausted.
//
// --------------------------------------------------------------------
// Example 1 : i gets exhausted first
//
// nums1 = [4,5,6,0,0,0]
// nums2 = [1,2,3]
//
// i = 2 (6)
// j = 2 (3)
// k = 5
//
// Compare 6 and 3 -> place 6
// Compare 5 and 3 -> place 5
// Compare 4 and 3 -> place 4
//
// Now:
//
// i = -1
// j = 2
//
// Current array:
//
// [4,5,6,4,5,6]
//
// We still have:
//
// nums2 = [1,2,3]
//
// left to place.
//
// If we used:
//
// while(i >= 0 && j >= 0)
//
// the loop would stop here and the answer would be wrong.
//
// Therefore we must continue copying nums2.
//
// --------------------------------------------------------------------
// Example 2 : j gets exhausted first
//
// nums1 = [1,2,3,0,0,0]
// nums2 = [4,5,6]
//
// Compare 3 and 6 -> place 6
// Compare 3 and 5 -> place 5
// Compare 3 and 4 -> place 4
//
// Now:
//
// i = 2
// j = -1
//
// Array becomes:
//
// [1,2,3,4,5,6]
//
// Notice:
//
// 1,2,3
//
// were never moved.
//
// They are already exactly where they should be.
//
// No further work is required.
//
// --------------------------------------------------------------------
// Example 3 : General Case
//
// nums1 = [1,3,5,0,0,0]
// nums2 = [2,4,6]
//
// Compare 5 and 6 -> place 6
// Compare 5 and 4 -> place 5
// Compare 3 and 4 -> place 4
// Compare 3 and 2 -> place 3
// Compare 1 and 2 -> place 2
//
// j becomes -1
//
// Final array:
//
// [1,2,3,4,5,6]
//
// Again, any remaining nums1 elements are already in place.
//
// --------------------------------------------------------------------
// Therefore:
//
// Remaining nums1 elements:
//     Already in correct positions.
//
// Remaining nums2 elements:
//     Must be copied.
//
// This is why:
//
// while(j >= 0)
//
// is sufficient and avoids needing an extra loop.
    }
};