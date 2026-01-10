/*
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
 

Constraints:

1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std ;

class Solution {
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

         // dp[i][j] = max dot product using nums1[i..n] and nums2[j..m]
        //INT_MIN makes sure atleast one solution(or pair) is always chosen as the final answer may be negative 
        vector<vector<int>> dp( n + 1 , vector<int> (m + 1 , INT_MIN ));

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ;j--){
            
            int product = nums1[i] * nums2[j];

            // Option 1 - > Take the product (the previous product might be negative so we need to see if we take it forward or start fresh --> Like kadane algo)
            
            // To avoid overflow condition as cannot add negative to INT_MIN
            int take=product;
            if(dp[i+1][j+1] != INT_MIN){
                take = max(product , product + dp[i+1][j+1]);
            }
            

            // Option 2 : Skip nums[i]
            int skip1 = dp[i + 1][j];

            //Option 3 : Skip nums[j]
            int skip2 = dp[i][j + 1];

            dp[i][j] = max({ take , skip1 ,skip2});

            }
        }
        
        //TC :(n x m) and SC : O(n x m)
        return dp[0][0];

    }
};