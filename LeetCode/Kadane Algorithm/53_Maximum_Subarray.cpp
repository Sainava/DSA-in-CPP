/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // subarray - contiguous part of array 
        int n = nums.size() ;

        // // Brute Force 
        // int maxSum= INT_MIN;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         // The outer 2 loops give every possible subarray 

        //         int sum = 0 ; 
        //         for(int k = i ; k <= j ; k++ ){
        //             // This loops finds the sum of subarray 
        //             sum+=nums[k];
                    
        //         }

        //         maxSum = max(maxSum, sum );
        //     }
        // }

        // //TC : O(n^3)
        // return maxSum ;

        // // Better Solution
        // int maxSum= INT_MIN;
        // for(int i = 0 ; i < n ; i++){
        //     int sum = 0 ;
        //     for(int j = i ; j < n ; j++){
        //         // The outer 2 loops give every possible subarray 
        //         sum += nums[j];
        //         maxSum = max(maxSum, sum );      
        //     }
        // }

        // //TC : O(n^2)
        // return maxSum ;

        //Optimised - Kadane's Algorithm 

        int maxSum = INT_MIN;
        int sum = 0 ;

        for(int i = 0 ; i < n ; i++){
            
            // Step 1 - Add current element to sum 
            sum += nums[i];

            // Step 2 - Update max if possible 
            maxSum = max(maxSum , sum);

            // Step 3 - If sum is negative - do not carry forward 
            if(sum < 0){
                sum = 0 ;
            }
        }

        //TC : O(n) and SC:O(1)
        return maxSum ;
    }
};

//Solution 2 - Divide and Conquer Approach 
class Solution {
public:
    struct Node{
        // For a segment [l.....r]
        int sum ; // Sum of entire section
        int prefix ; // maximum sum starting from l
        int suffix ; //maximum sum edning at r
        int best ; // maximum subarray sum from this segment 
    };

    // Merge logic 
    // totalSum = left.totalSum + right.totalSum
    // prefixMax = max(left.prefixMax, left.totalSum + right.prefixMax)
    // suffixMax = max(right.suffixMax, right.totalSum + left.suffixMax)
    // maxSub = max({left.maxSub, right.maxSub, left.suffixMax + right.prefixMax})
    
    Node merge(Node left, Node right){
        Node res;

        res.sum=left.sum + right.sum; // Total sum of left and right 

        res.prefix = max(left.prefix , left.sum + right.prefix); // Must start with left so ->Two choices:
        // Entirely inside left → left.prefix
        // Left entire + right prefix → left.sum + right.prefix Left full plus starting of right 

        res.suffix = max(right.suffix , right.sum + left.suffix); // Must end with right  so -> Two choices:
        // Entirely inside right → right.suffix
        // Right entire + left suffix → right.sum + left.suffix

        res.best= max({left.best, right.best, left.suffix + right.prefix});
        // Three possibilities:
        // Fully in left → left.best
        // Fully in right → right.best
        //Crossing mid → left.suffix + right.prefix

        return res;
    }

    Node build(int l , int r ,vector<int>& nums ){
        if(l==r){
            // Only one element in segment 
            return {nums[l], nums[l], nums[l], nums[l]};
        }

        int mid = l + (r - l)/2;
        Node left = build(l , mid , nums);
        Node right = build (mid + 1, r , nums) ;

        return merge(left , right) ;
    }

    int maxSubArray(vector<int>& nums) {
        // Using Divide and Conquer
        // Think of it like merge sort , first we divide(build) and then we merge 

        // TC:O(n) -- > build is divide and conquer with recursive function : TC = 2T(n/2) + O(1) (as merge is constant funtion unlike merge sort which is n ) 
        // SO TC:O(n) using master theorem 
        // and SC:O(logn) due to recursive stack 
        return build(0, nums.size() - 1, nums).best;
    }
};