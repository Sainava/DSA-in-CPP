/*
You are given an integer array coins representing coins of different denominations (e.g. 1 dollar, 5 dollars, etc) and an integer amount representing a target amount of money.

Return the fewest number of coins that you need to make up the exact target amount. If it is impossible to make up the amount, return -1.

You may assume that you have an unlimited number of each coin.

Example 1:

Input: coins = [1,5,10], amount = 12

Output: 3
Explanation: 12 = 10 + 1 + 1. Note that we do not have to use every kind coin available.

Example 2:

Input: coins = [2], amount = 3

Output: -1
Explanation: The amount of 3 cannot be made up with coins of 2.

Example 3:

Input: coins = [1], amount = 0

Output: 0
Explanation: Choosing 0 coins is a valid way to make up 0.

Constraints:

1 <= coins.length <= 10
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(vector<int>& coins, int target ){
        // Base case 
        if( target < 0 ){
            // No of coins needed to make negative sum -> invalid 
             return INT_MAX ; // as we do min so this becomes irrelevant
        }

        if(target== 0){
            return 0 ; // As discussed no of coins needed to make 0 ;
        }

        int mini = INT_MAX ; //Min No of coins needed to make target

        for(int i = 0 ; i < coins.size() ; i++){
            int ans = func(coins , target - coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini , ans + 1); // ans plus one as we use ith coin as well 
            }
        }

        // Now mini holds minimum no of coins needed to make target
        return mini;
    }

    int funcTopDown(vector<int>& coins, int target , vector<int> &dp){
        // Base case 
        if( target < 0 ){
            // No of coins needed to make negative sum -> invalid 
             return INT_MAX ; // as we do min so this becomes irrelevant
        }

        if(target== 0){
            return dp[0] = 0 ; // As discussed no of coins needed to make 0 ;
        }

        if(dp[target]!= -1){
            return dp[target];
        }

        dp[target]= INT_MAX ; //Min No of coins needed to make target

        for(int i = 0 ; i < coins.size() ; i++){
            int ans = funcTopDown(coins , target - coins[i] , dp);
            if(ans!=INT_MAX){
                dp[target] = min(dp[target], ans + 1); // ans plus one as we use ith coin as well 
            }
        }

        // Now mini holds minimum no of coins needed to make target
        return dp[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        // Three conditions 
        // 1. say (amount == 11) and coins (5,3,1 ) so can have valid solution 
        // 2. say (amount == 3) and coins(6) so return -1 , not valid 
        // 3 . say(amount == 0 ) coins(does not matter ) return 0 


        // One type of coin can be taken multiple times 
        // Target is the driving force here
        // //Basic Recursion 
        // int ans = func(coins , amount) ;
        // if(ans == INT_MAX ){
        //     // Not possible 
        //     return -1 ; 
        // }
        // // recursion handels target 0 case as well 
        // // Exponential without dp 
        // return ans ; 

        // // Top Down dp 
        // vector<int> dp(amount + 1 , -1 ) ; //0 to target 
        // // dp[i] holds the minimum no of coins needed to make target 
        // dp[amount] = funcTopDown(coins ,amount ,dp ) ;
        // if(dp[amount] == INT_MAX ){
        //     // Not possible 
        //     return -1 ; 
        // }
        // // recursion handels target 0 case as well 
        // //With dp each target value stored only once  and coins are called 
        // //So TC:O(amount * coins) and SC:O(amount)
        // return dp[amount] ; 

        // Bottom up 
        vector<int> dp(amount + 1 , -1 ) ;
        dp[0] = 0 ; 

        for(int target  = 1 ; target <= amount ; target++){
            dp[target]= INT_MAX ; //Min No of coins needed to make target
            for(int i = 0 ; i < coins.size() ; i++){
                if( target - coins[i] >= 0 and dp[target - coins[i]] != INT_MAX){
                    dp[target] = min(dp[target] , dp[target - coins[i]] + 1);
                }
                
            }
        }

        //So TC:O(amount * coins) and SC:O(amount)
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
        
        // Cannot be space optimised 
    }
};
