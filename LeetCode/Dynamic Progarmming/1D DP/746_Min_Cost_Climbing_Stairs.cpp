/*  
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int solve(vector<int>& cost,int n,vector<int> &dp){
        //Base case:
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        //Step 2 : Check if value already Calculated
        if(dp[n]!=-1){
            return dp[n];
        }

        //Step 3 : Same value at dp[n] and return
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        //Top Down DP- Recursion + Memoization
        //TC:O(n)
        //SC:O(n)

        int n=cost.size();

        //Step 1 --> Create the dp array
        vector<int> dp(n+1,-1);

        int minCost=min(solve(cost,n-1,dp),solve(cost,n-2,dp));

        return minCost;

    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //Tabulation
        //TC : O(n)
        //SC:O(n)

        int n=cost.size();

        //Step 1 --> Create the dp array
        vector<int> dp(n+1,-1);

        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            dp[i]= min(dp[i-1],dp[i-2]) +cost[i];
        }

        dp[n]=min(dp[n-1],dp[n-2]);

        return dp[n];

    }
};

class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //Space Optimisation
        //TC : O(n)
        //SC:O(1)

        int n=cost.size();

        //Step 1 --> Create the dp array

        int prev1=cost[0];
        int prev2=cost[1];

        for(int i=2;i<n;i++){
            int curr=min(prev1,prev2) +cost[i];
            prev1=prev2;
            prev2=curr;
        }

        return min(prev1,prev2);

    }
};