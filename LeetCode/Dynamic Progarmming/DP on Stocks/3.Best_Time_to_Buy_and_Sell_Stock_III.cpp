/*
Problem statement
You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘n’ days.



You are given an array ‘prices’ which such that ‘prices[i]’ denotes the price of the stock on the ith day.



You don't want to do more than 2 transactions. Find the maximum profit that you can earn from these transactions.



Note

1. Buying a stock and then selling it is called one transaction.

2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again. 
Example:
Input: ‘n’ = 7, ‘prices’ = [3, 3, 5, 0, 3, 1, 4].

Output: 6

Explanation: 
The maximum profit can be earned by:
Transaction 1: Buying the stock on day 4 (price 0) and then selling it on day 5 (price 3). 
Transaction 2: Buying the stock on day 6 (price 1) and then selling it on day 6 (price 4).
Total profit earned will be (3 - 0) + ( 4 - 1) = 6. 
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
1 3 1 2 4 8
Sample Output 1:
9
Explanation Of Sample Input 1 :
The maximum profit can be earned by:
Transaction 1: Buying the stock on day 1 (price 1) and then selling it on day 2 (price 3). 
Transaction 2: Buying the stock on day 3 (price 1) and then selling it on day 6 (price 8).
Total profit earned will be (3 - 1) + ( 8 - 1) = 9. 
Sample Input 2:
5
5 4 3 2 1
Sample Output 2:
0
Explanation of Sample Output 2:
It's better not to do any transactions as the stock prices are decreasing. 
Expected time complexity:
The expected time complexity is O(n).
Constraints:
1 <= ‘n’ <= 10^6
0 <= ‘prices[i]’ <= 10^3

Where ‘prices[i]’ is the stock price on ith day. 

Time Limit: 1 sec.
*/

#include<iostream>
#include<vector>
using namespace std;

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



int maxProfit(vector<int>& prices)
{   
    // 3-D DP 
    int n = prices.size() ;

    // //Top - Down 
    // vector<vector<vector<int>>> dp(n,
    //     vector<vector<int>>( 2 , vector<int> (3 ,-1))
    // ); // cap 3 as 3 possible values -> 0 transactions remaining or 1 transaction remaining or 2

    // int index = 0 ;
    // int buy = 1 ; // Tells us whether we can buy or no , On day 1 we can buy as we have not bought anything before 
    // int cap = 2 ; // We can do 2 transaction
    
    // //TC:O(n *2*3) and SC:O(n*2*3)
    // return func(index ,buy ,cap , prices , n ,dp);

    // //Bottom - Up  
    // vector<vector<vector<int>>> dp(n,
    //     vector<vector<int>>( 2 , vector<int> (3 ,0))
    // );


    // for(int index = n-1 ; index >=0 ; index--){
    //     for(int buy = 0 ; buy <= 1 ; buy++){
    //         for(int cap = 1 ; cap <=2 ; cap++){
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
    // //TC:O(n*2*3) and SC:O(n*2*3)
    // return dp[0][1][2];

    // Space Optimised 
    vector<vector<int>> nextDay( 2 , vector<int> (3 ,0));
    vector<vector<int>> currDay( 2 , vector<int> (3 ,0));

    for(int index = n-1 ; index >=0 ; index--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 1 ; cap <=2 ; cap++){
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
    return currDay[1][2];



}