/*
You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may buy and sell one NeetCoin multiple times with the following restrictions:

After you sell your NeetCoin, you cannot buy another one on the next day (i.e., there is a cooldown period of one day).
You may only own at most one NeetCoin at a time.
You may complete as many transactions as you like.

Return the maximum profit you can achieve.

Example 1:

Input: prices = [1,3,4,0,4]

Output: 6
Explanation: Buy on day 0 (price = 1) and sell on day 1 (price = 3), profit = 3-1 = 2. Then buy on day 3 (price = 0) and sell on day 4 (price = 4), profit = 4-0 = 4. Total profit is 2 + 4 = 6.

Example 2:

Input: prices = [1]

Output: 0
Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int func(int index , int buy ,vector<int>& prices, int n , vector<vector<int>> &dp){

    if( index >= n){
        return 0 ;
    }

    if(dp[index][buy]!= -1) return dp[index][buy] ; 

    // On each day
    int profit = INT_MIN ; 
    if( buy){
        // We can buy 
        // But we choose if we want to buy or not so 2 choices 
        int willBuy = -prices[index] + func(index+1 , 0 , prices , n ,dp); // if we buy we cannot buy next day 
        int willNotBuy = 0 +  func(index+1 , 1 , prices , n ,dp);  // if we did not buy we can buy next day 
        profit = max(willBuy ,willNotBuy );
    }else{
        // We can sell 
        // But we choose if we want to sell or not so 2 choices 

        int willSell = prices[index] + func(index+2 , 1 , prices , n , dp); // if we sell we can buy next day 
        int willNotSell = 0 +  func(index+1 , 0 , prices , n , dp); // if we do not sell we cannot buy next day 
        profit = max(willSell ,willNotSell );
    }
    
    dp[index][buy] = profit ;
    return dp[index][buy];

    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        //Top - Down 
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // int index = 0 ;
        // int buy = 1 ; // Tells us whether we can buy or no , On day 1 we can buy as we have not bought anything before 
        // //TC:O(n*2) and SC:O(n*2)
        // return func(index ,buy ,prices , n ,dp) ;


        // // Bottom Up 
        // vector<vector<int>> dp(n+2,vector<int>(2,0));

        // for(int index = n-1 ; index >=0 ; index--){
        //     for(int buy = 0 ; buy <= 1 ; buy++){
        //         // On each day
        //         int profit = INT_MIN ; 
        //         if( buy){
        //             // We can buy 
        //             // But we choose if we want to buy or not so 2 choices 
        //             int willBuy = -prices[index] + dp[index+1][0]; // if we buy we cannot buy next day 
        //             int willNotBuy = 0 +  dp[index+1][1] ;  // if we did not buy we can buy next day 
        //             profit = max(willBuy ,willNotBuy );
        //         }else{
        //             // We can sell 
        //             // But we choose if we want to sell or not so 2 choices 

        //             int willSell = prices[index] + dp[index+2][1]; // if we sell we can buy next day 
        //             int willNotSell = 0 +  dp[index+1][0]; // if we do not sell we cannot buy next day 
        //             profit = max(willSell ,willNotSell );
        //         }
                
        //         dp[index][buy] = profit ;
        //     }
        // }
        // //TC:O(n*2) and SC:O(n*2)
        // return dp[0][1];


        // // Bottom Up  -> Written Better
        // vector<vector<int>> dp(n+2,vector<int>(2,0));

        // for(int index = n-1 ; index >=0 ; index--){
        //     // Buy
        //     dp[index][1] = max(-prices[index] + dp[index+1][0],0 +  dp[index+1][1]);                     

        //     // Not Buy
        //     dp[index][0] = max(prices[index] + dp[index+2][1],0 +  dp[index+1][0]); 

        // }
        // //TC:O(n) and SC:O(n*2)
        // return dp[0][1];

        // Space Optimised 
        vector<int> front2(2,0) ;
        vector<int> front1(2,0) ;
        vector<int> curr(2,0) ;

         for(int index = n-1 ; index >=0 ; index--){
            // Buy
            curr[1] = max(-prices[index] +front1[0],0 + front1[1]);                     

            // Not Buy
            curr[0] = max(prices[index] + front2[1],0 + front1[0]); 

            front2 = front1 ; 
            front1 = curr ;
        }

        // TC:O(n) and SC:O(1)
        return curr[1];
    }

   
};
