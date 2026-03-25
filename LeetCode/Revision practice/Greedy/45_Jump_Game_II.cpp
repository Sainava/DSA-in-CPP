/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

class Solution {
public:
    int func( int index , int jumps ,vector<int>& nums){
        // Base Case 
        if(index >=nums.size() - 1){
            return jumps;
        }

        int mini = INT_MAX;

        for(int i = 1 ; i <= nums[index] ; i++){
            mini = min( mini , func(index + i , jumps + 1 , nums));
        }

        return mini ;
    }

    int jump(vector<int>& nums) {
        // // Solution 1 : Recursion 

        // //TC:O(n^n) approx exponential 
        // //SC:O(n) recursion stack 
        // return func(0 ,0 ,nums);

        //Solution 2 : Greedy 
        // Check ranges instead of mutilple calls

        int n = nums.size();
        int l = 0 ;
        int r = 0 ;
        int jumps = 0 ;
        
        while( r < n - 1){
            int farthest = r ;

            for(int i = l ; i <= r ; i++ ){
                farthest = max( farthest , i + nums[i]);
            }

            l = r + 1;
            r = farthest ;
            jumps ++  ;
        }

        // TC:O(n) - As eventhough it looks like 2 loops , the loop of l to r is unique each time the outer loop runs 
        //SC:O(1)
        return jumps;
         
    }
};