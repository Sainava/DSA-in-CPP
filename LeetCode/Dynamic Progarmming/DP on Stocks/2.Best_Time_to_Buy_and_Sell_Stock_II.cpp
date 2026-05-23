/*
Problem statement
You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.

 Note :
You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
Sample Input 2 :
1
7
7 6 5 4 3 2 1
Sample Output 2 :
0
Explanation :
We can make the maximum profit by not buying the stock.
*/

#include<iostream>
#include<vector>
using namespace std;

long func(int index , int buy ,long *values, int n , vector<vector<long>> &dp){

    if( index == n){
        return 0 ;
    }

    if(dp[index][buy]!= -1) return dp[index][buy] ; 

    // On each day
    long profit = LONG_MIN ; 
    if( buy){
        // We can buy 
        // But we choose if we want to buy or not so 2 choices 
        long willBuy = -values[index] + func(index+1 , 0 , values , n ,dp); // if we buy we cannot buy next day 
        long willNotBuy = 0 +  func(index+1 , 1 , values , n ,dp);  // if we did not buy we can buy next day 
        profit = max(willBuy ,willNotBuy );
    }else{
        // We can sell 
        // But we choose if we want to sell or not so 2 choices 

        long willSell = values[index] + func(index+1 , 1 , values , n , dp); // if we sell we can buy next day 
        long willNotSell = 0 +  func(index+1 , 0 , values , n , dp); // if we do not sell we cannot buy next day 
        profit = max(willSell ,willNotSell );
    }
    
    dp[index][buy] = profit ;
    return dp[index][buy];
}

long getMaximumProfit(long *values, int n)
{
   

    // //Top - Down 
    // vector<vector<long>> dp(n,vector<long>(2,-1));
    // int index = 0 ;
    // int buy = 1 ; // Tells us whether we can buy or no , On day 1 we can buy as we have not bought anything before 
    //TC:O(n*2) and SC:O(n*2)
    // return func(index ,buy ,values , n ,dp) ;

    // // Bottom Up 
    // vector<vector<long>> dp(n+1,vector<long>(2,0));

    // for(int index = n-1 ; index >=0 ; index--){
    //     for(int buy = 0 ; buy <= 1 ; buy++){
    //         // On each day
    //         long profit = LONG_MIN ; 
    //         if( buy){
    //             // We can buy 
    //             // But we choose if we want to buy or not so 2 choices 
    //             long willBuy = -values[index] + dp[index+1][0]; // if we buy we cannot buy next day 
    //             long willNotBuy = 0 +  dp[index+1][1] ;  // if we did not buy we can buy next day 
    //             profit = max(willBuy ,willNotBuy );
    //         }else{
    //             // We can sell 
    //             // But we choose if we want to sell or not so 2 choices 

    //             long willSell = values[index] + dp[index+1][1]; // if we sell we can buy next day 
    //             long willNotSell = 0 +  dp[index+1][0]; // if we do not sell we cannot buy next day 
    //             profit = max(willSell ,willNotSell );
    //         }
            
    //         dp[index][buy] = profit ;
    //     }
    // }
    // //TC:O(n*2) and SC:O(n*2)
    // return dp[0][1];

    // // Space Optimised 
    // vector<long> nextDay(2,0);
    // vector<long> currDay(2,0);

    // for(int index = n-1 ; index >=0 ; index--){
    //     for(int buy = 0 ; buy <= 1 ; buy++){
    //         // On each day
    //         long profit = LONG_MIN ; 
    //         if( buy){
    //             // We can buy 
    //             // But we choose if we want to buy or not so 2 choices 
    //             long willBuy = -values[index] + nextDay[0]; // if we buy we cannot buy next day 
    //             long willNotBuy = 0 +  nextDay[1] ;  // if we did not buy we can buy next day 
    //             profit = max(willBuy ,willNotBuy );
    //         }else{
    //             // We can sell 
    //             // But we choose if we want to sell or not so 2 choices 

    //             long willSell = values[index] + nextDay[1]; // if we sell we can buy next day 
    //             long willNotSell = 0 + nextDay[0]; // if we do not sell we cannot buy next day 
    //             profit = max(willSell ,willNotSell );
    //         }
            
    //         currDay[buy] = profit ;
    //     }
    //     nextDay = currDay;
    // }
    // //TC:O(n*2) and SC:O(1)
    // return currDay[1];

    // Space Optimised  -> Use 4 variables 
    long aheadBuy  = 0 ;
    long aheadNotBuy  = 0 ;
    long currBuy = 0 ;
    long currNotBuy = 0 ;

    for(int index = n-1 ; index >=0 ; index--){
                // On each day                
                long willBuy = -values[index] + aheadNotBuy; // if we buy we cannot buy next day 
                long willNotBuy = 0 + aheadBuy ;  // if we did not buy we can buy next day 
                currBuy = max(willBuy ,willNotBuy );

                long willSell = values[index] + aheadBuy; // if we sell we can buy next day 
                long willNotSell = 0 + aheadNotBuy; // if we do not sell we cannot buy next day 
                currNotBuy = max(willSell ,willNotSell );
            
                aheadBuy = currBuy ;
                aheadNotBuy = currNotBuy ;
    }
    //TC:O(n*2) and SC:O(1)
    return currBuy;
}