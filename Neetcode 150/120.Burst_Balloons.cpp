/*
You are given an array of integers nums of size n. The ith element represents a balloon with an integer value of nums[i]. You must burst all of the balloons.

If you burst the ith balloon, you will receive nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then assume the out of bounds value is 1.

Return the maximum number of coins you can receive by bursting all of the balloons.

Example 1:

Input: nums = [4,2,3,7]

Output: 143

Explanation:
nums = [4,2,3,7] --> [4,3,7] --> [4,7] --> [7] --> []
coins =  4*2*3    +   4*3*7   +  1*4*7  + 1*7*1 = 143
Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ; 

        nums.push_back(1) ;
        nums.insert(nums.begin() , 1);

        vector<vector<int>> dp(n+2, vector<int>( n+2 , 0));
        // Base case handled in initialisation of 0
        // In recursion i goes from 1 to n  so here i goes from n to 1
        // In recursion j goes from n to 1  so here j goes from 1 to n

        for(int i = n ; i >= 1 ; i--){
            for(int j = 1 ; j <= n ; j++){
                if(i > j ) continue ;  // Remember from top down to bottom up the base case does not change 

                int maxi = INT_MIN ;
                for(int ind = i ; ind <= j ; ind++){
                    int cost = nums[i-1] * nums[ind] * nums[j+1] +
                        dp[i][ind - 1] + dp[ind + 1][ j ] ;

                    maxi = max(maxi , cost);
                }

                dp[i][j] = maxi ;
            }
        } 
        //TC:O(n*n) and SC:O(n*n) for DP
        return dp[1][n] ;
        
    }
};
