/*
You are given two integer arrays nums1 and nums2 of size m and n respectively, where each is sorted in ascending order. Return the median value among all elements of the two arrays.

Your solution must run in 
O
(
l
o
g
(
m
+
n
)
)
O(log(m+n)) time.

Example 1:

Input: nums1 = [1,2], nums2 = [3]

Output: 2.0
Explanation: Among [1, 2, 3] the median is 2.

Example 2:

Input: nums1 = [1,3], nums2 = [2,4]

Output: 2.5
Explanation: Among [1, 2, 3, 4] the median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute force merge two sorted array and find median 
        // TC:O(m + n)

        int m = nums1.size();
        int n = nums2.size();
        
        // We want n1 ro be the smaller array for better complexity
        if( n < m ) return findMedianSortedArrays(nums2,nums1);

        int N = m + n ;

        // For symmetry check the number of elements on the left should be
        // Total elements needed on the left side 
        int left = (m + n + 1)/2;

        // Now binary search on the amount of elements we want to selecty from smaller array 
        int low = 0 , high = m ;

        while ( low <= high ){
            int mid1 = (low + high) >> 1; // basically (low+high)/2
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];

            if( mid1 - 1 >=0) l1 = nums1[mid1-1];
            if( mid2 - 1 >=0) l2 = nums2[mid2-1];

            // Now binary search 
            if( l1 <=r2 && l2<=r1){
                if( N % 2 ==1 ) return max(l1,l2); // For odd 
                return  ((double)(max(l1,l2) + min(r1,r2))) / 2.0 ;

            }
            else if( l1 > r2){
                high = mid1 - 1 ;
            }else {
                low  = mid1 + 1 ;
            }
        }


        // TC :O( log ( min(m,n))) and SC:O(1)
        return 0.;


    }
};
