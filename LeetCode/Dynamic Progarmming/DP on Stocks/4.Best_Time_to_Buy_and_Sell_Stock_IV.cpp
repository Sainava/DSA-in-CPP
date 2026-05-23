/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

// Solution using 3D DP -> index , buy/sell and cap
class Solution {
public:

    int func(int index , int buy ,int cap ,vector<int>& prices, int n , vector<vector<vector<int>>> dp){

        if( index == n || cap == 0){
            return 0 ;
        }

        if(dp[index][buy][cap]!= -1) return dp[index][buy][cap] ; 

        // On each day
        int profit = INT_MIN ; 
        if( buy){
    
            int willBuy = -prices[index] + func(index+1 , 0 , cap , prices , n ,dp); // if we buy we cannot buy next day 
            int willNotBuy = 0 +  func(index+1 , 1 ,cap , prices , n ,dp);  // if we did not buy we can buy next day 
            profit = max(willBuy ,willNotBuy );
        }else{
            int willSell = prices[index] + func(index+1 , 1 , cap -1 , prices , n , dp); // if we sell we can buy next day 
            int willNotSell = 0 +  func(index+1 , 0 ,cap , prices , n , dp); // if we do not sell we cannot buy next day 
            profit = max(willSell ,willNotSell );
        }
        
        dp[index][buy][cap] = profit ;
        return dp[index][buy][cap];
    }

    int maxProfit(int k, vector<int>& prices) {
        // 3-D DP 
    int n = prices.size() ;

    // //Top - Down 
    // vector<vector<vector<int>>> dp(n,
    //     vector<vector<int>>( 2 , vector<int> (3 ,-1))
    // ); // cap 3 as 3 possible values -> 0 transactions remaining or 1 transaction remaining or 2

    // int index = 0 ;
    // int buy = 1 ; // Tells us whether we can buy or no , On day 1 we can buy as we have not bought anything before 
    // int cap = k ; // We can do 2 transaction
    
    // //TC:O(n *2*k) and SC:O(n*2*k)
    // return func(index ,buy ,cap , prices , n ,dp);

    // //Bottom - Up  
    // vector<vector<vector<int>>> dp(n,
    //     vector<vector<int>>( 2 , vector<int> (k+1 ,0))
    // );


    // for(int index = n-1 ; index >=0 ; index--){
    //     for(int buy = 0 ; buy <= 1 ; buy++){
    //         for(int cap = 1 ; cap <=k ; cap++){
    //             // On each day
    //             int profit = INT_MIN ; 
    //             if( buy){
            
    //                 int willBuy = -prices[index] + func(index+1 , 0 , cap , prices , n ,dp); // if we buy we cannot buy next day 
    //                 int willNotBuy = 0 +  func(index+1 , 1 ,cap , prices , n ,dp);  // if we did not buy we can buy next day 
    //                 profit = max(willBuy ,willNotBuy );
    //             }else{
    //                 int willSell = prices[index] + func(index+1 , 1 , cap -1 , prices , n , dp); // if we sell we can buy next day 
    //                 int willNotSell = 0 +  func(index+1 , 0 ,cap , prices , n , dp); // if we do not sell we cannot buy next day 
    //                 profit = max(willSell ,willNotSell );
    //             }
                
    //             dp[index][buy][cap] = profit ;
    //         }

    //     }
    // }
    // //TC:O(n*2*k) and SC:O(n*2*k)
    // return dp[0][1][k];

    // Space Optimised 
    vector<vector<int>> nextDay( 2 , vector<int> (k+1 ,0));
    vector<vector<int>> currDay( 2 , vector<int> (k+1 ,0));

    for(int index = n-1 ; index >=0 ; index--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 1 ; cap <=k ; cap++){
                // On each day
                int profit = INT_MIN ; 
                if( buy){
            
                    int willBuy = -prices[index] + nextDay[0][cap]; // if we buy we cannot buy next day 
                    int willNotBuy = 0 +  nextDay[1][cap];  // if we did not buy we can buy next day 
                    profit = max(willBuy ,willNotBuy );
                }else{
                    int willSell = prices[index] + nextDay[1][cap -1]; // if we sell we can buy next day 
                    int willNotSell = 0 +  nextDay[0][cap]; // if we do not sell we cannot buy next day 
                    profit = max(willSell ,willNotSell );
                }
                
                currDay[buy][cap] = profit ;
            }
        }

        nextDay = currDay;
    }
    //TC:O(n*2*3) and SC:O(1)
    return currDay[1][k];
    }
};

class Solution {
public:
    int func(int index , int transNo ,vector<int>& prices , int n ,int k ,vector<vector<int>> &dp){
        if(index == n || transNo == 2*k) return 0 ;

        if(dp[index][transNo]!= -1) return dp[index][transNo] ;

        if( transNo % 2 == 0){
            // Buy 
            return dp[index][transNo] = max(-prices[index] + func(index + 1, transNo + 1 , prices , n , k ,dp),
                        0 + func(index + 1, transNo , prices , n , k , dp)  
            );
        }
        else{
            // Sell
            return dp[index][transNo] = max(prices[index] + func(index + 1, transNo + 1 , prices , n , k ,dp),
                        0 + func(index + 1, transNo , prices , n , k ,dp)  
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        // TransNo as such B S B S B S
        //                 0 1 2 3 4 5    
        int n = prices.size() ;

        // // Top Down 
        // vector<vector<int>> dp(n , vector<int>(2*k+1,-1));
        // return func(0 , 0 , prices, n , k , dp)  ;        

    //     // Bottom UP 
    //    vector<vector<int>> dp(
    //         n + 1,
    //         vector<int>(2 * k + 1, 0)
    //     );

    //     for(int index = n - 1; index >= 0; index--) {

    //         for(int transNo = 2 * k - 1;
    //             transNo >= 0;
    //             transNo--) {

    //             // Buy state
    //             if(transNo % 2 == 0) {

    //                 dp[index][transNo] = max(
    //                     -prices[index] +
    //                     dp[index + 1][transNo + 1],

    //                     dp[index + 1][transNo]
    //                 );
    //             }

    //             // Sell state
    //             else {

    //                 dp[index][transNo] = max(
    //                     prices[index] +
    //                     dp[index + 1][transNo + 1],

    //                     dp[index + 1][transNo]
    //                 );
    //             }
    //         }
    //     }

    //     return dp[0][0];

        // Space Optimisation 
        vector<int> next(2 * k + 1, 0) ;
        vector<int> curr(2 * k + 1, 0) ;

        for(int index = n - 1; index >= 0; index--) {

            for(int transNo = 2 * k - 1;
                transNo >= 0;
                transNo--) {

                // Buy state
                if(transNo % 2 == 0) {

                    curr[transNo] = max(
                        -prices[index] +
                       next[transNo + 1],

                        next[transNo]
                    );
                }

                // Sell state
                else {

                    curr[transNo] = max(
                        prices[index] +
                        next[transNo + 1],

                       next[transNo]
                    );
                }
            }
            next = curr;
        }

        return curr[0];
    }
};