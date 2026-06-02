/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. However, you can buy it then immediately sell it on the same day. Also, you are allowed to perform any number of transactions but can hold at most one share of the stock at any time.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3. Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]

Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4. Total profit is 4.

Constraints:

1 <= prices.length <= 30,000
0 <= prices[i] <= 10,000
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int func(int index , int buy ,vector<int>& prices , int n ,vector<vector<int>> &dp){
        if( index == n) return 0 ; 

        if( dp[index][buy]!= -1 ) return dp[index][buy] ;

        // Can buy and sell on the same day , that would mean net profit = 0 so the skip handles this case
        if( buy){
            int willBuy = -prices[index] + func(index  + 1, 0 , prices , n , dp) ; 
            int wontBuy = 0 + func(index + 1 , 1 , prices , n , dp) ;

            return dp[index][buy] = max(willBuy , wontBuy);
        }
        else{
            int willSell = prices[index] + func(index + 1 , 1 , prices , n ,dp);
            int wontSell = 0 + func( index + 1 , 0 , prices , n , dp);

            return dp[index][buy] = max(willSell , wontSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int index = 0 ; 
        int buy = 1 ; // One means we can buy

        //TC:O(n*2) and SC:O(n*2)
        vector<vector<int>> dp(n+1 , vector<int> (2 , -1)) ;
        return func(index , buy , prices , n , dp);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int index = 0 ; 
        int buy = 1 ; // One means we can buy

        //TC:O(n*2) and SC:O(n*2)
        vector<vector<int>> dp(n+1 , vector<int> (2 , 0)) ;
        
        for(int index = n - 1 ; index>= 0 ; index--){
            
            dp[index][1] = max(-prices[index] + dp[index + 1][0]  ,0 + dp[index + 1 ][1]) ;

            dp[index][0] = max(prices[index] + dp[index + 1][1] ,  0 + dp[index + 1] [0]) ;

        }
        //TC:O(n) and SC:O(n*2)
        return dp[0][1] ; 
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int index = 0 ; 
        int buy = 1 ; // One means we can buy

        //TC:O(n*2) and SC:O(n*2)
        vector<int> curr(2 , 0) ;
        vector<int> next(2 , 0) ;
        
        for(int index = n - 1 ; index>= 0 ; index--){
            
            curr[1] = max(-prices[index] + next[0]  ,0 + next[1]) ;

            curr[0] = max(prices[index] + next[1] ,  0 + next[0]) ;

            next = curr ;
        }

        //TC:O(n) and SC:O(1)
        return next[1] ; 
    }
};