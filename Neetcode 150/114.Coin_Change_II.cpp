/*
You are given an integer array coins representing coins of different denominations (e.g. 1 dollar, 5 dollars, etc) and an integer amount representing a target amount of money.

Return the number of distinct combinations that total up to amount. If it's impossible to make up the amount, return 0.

You may assume that you have an unlimited number of each coin and that each value in coins is unique.

Example 1:

Input: amount = 4, coins = [1,2,3]

Output: 4
Explanation:

1+1+1+1 = 4
1+1+2 = 4
2+2 = 4
1+3 = 4
Example 2:

Input: amount = 7, coins = [2,4]

Output: 0
Constraints:

1 <= coins.length <= 100
1 <= coins[i] <= 5000
0 <= amount <= 5000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int index ,int amount , vector<int>& coins , vector<vector<int>> &dp){
        // base case 
        if(index == 0 ){
            if( amount % coins[0] == 0 ){
                // Means it is possible 
                return 1 ;
            }
            else{
                // means amount - coins[0] < 0 
                return 0 ;
            }
        }

        if( dp[index][amount] != -1 ) return dp[index][amount] ; 

        // Not take
        int notTake = func(index - 1 , amount , coins ,dp);

        // Take 
        int take = 0 ;
        if(coins[index] <= amount){
            take = func(index , amount - coins[index] , coins ,dp) ; // As same coin can be taken again and again we do not reduce index 
        }

        return dp[index][amount] = notTake + take ;

    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size() ;

        // // Top - Down 
        // int index = n - 1 ;
        // vector<vector<int>> dp(n , vector<int> (amount+1 ,-1));
        // // dp[i][target] tells us the no of ways to make target with coins[0...i]
        // // TC:O(n*amount) and SC:O(n*amount)
        // return func(index , amount , coins , dp) ;

        // // Bottom Up
        // vector<vector<int>> dp(n , vector<int> (amount+1 ,0));
        // for(int target = 0 ; target <= amount ; target++){
        //     if( target % coins[0] == 0) dp[0][target] = 1 ;    
        // }

        // for(int index = 0 ; index < n ; index++){
        //     dp[index][0] = 1;
        // }    

        // for(int index = 1 ; index < n ; index++){
        //     for(int target = 0 ; target <= amount ; target++){

        //         // Not take
        //         int notTake = dp[index - 1][target];

        //         // Take 
        //         int take = 0 ;
        //         if(coins[index] <= target){
        //             take = dp[index][target - coins[index]] ;
        //         }

        //         dp[index][target] = notTake + take ;
        //     }
        // }
        // // TC:O(n*amount) and SC:O(n*amount)
        // return dp[n-1][amount] ;

        // Space optimised
        vector<int> prev(amount+1 ,0);
        vector<int> curr(amount+1 ,0);

        for(int target = 0 ; target <= amount ; target++){
            if( target % coins[0] == 0) prev[target] = 1 ;    
        }
        
        curr[0] = 1 ;

        for(int index = 1 ; index < n ; index++){
            for(int target = 0 ; target <= amount ; target++){

                // Not take
                int notTake = prev[target];

                // Take 
                int take = 0 ;
                if(coins[index] <= target){
                    take = curr[target - coins[index]] ;
                }

                curr[target] = notTake + take ;
            }
            prev = curr ;
        }
        // TC:O(n*amount) and SC:O(n*amount)
        return prev[amount] ;
    }
    
};
