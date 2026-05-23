/*
Problem statement
You are given an array 'prices' of size 'n', denoting the price of stocks on 'n' days.



Rahul can buy one stock at a time, and he must sell it before buying stock on another day.



The entire transaction of selling and buying the stock requires some transaction fee, given as 'fee'.



Find the maximum profit Rahul can achieve by trading on the stocks.



Example :
Input: 'prices' =  [1, 2, 3] and 'fee' = 1

Output: 1

Explanation: We can generate the maximum profit of 1 by buying the stock on the first day for price = 1 and then selling it on the third day for price = 3.

The profit will be: 3 - 1 - 1(transaction fee) = 1
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 1
1 2 3


Sample Output 1 :
1


Explanation Of Sample Input 1 :
We can generate the maximum profit of 1 by buying the stock on the first day for price = 1 and then selling it on the third day for price = 3.                                                                                                     
The profit will be: 3 - 1 - 1(transaction fee) = 1


Sample Input 2 :
4 2
1 3 5 6


Sample Output 2 :
3


Expected time complexity :
The expected time complexity is O(n).


Constraints :
1 <= 'n' <= 10 ^ 4
0 <= 'prices[i]' <= 10 ^ 5
0 <= 'fee'<= 10 ^ 5
*/
#include<iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Space Optimised 

	vector<int> front(2,0) ;
	vector<int> curr(2,0) ;

		for(int index = n-1 ; index >=0 ; index--){
		// Buy
		curr[1] = max(-prices[index] +front[0],0 + front[1]);                     

		// Not Buy
		curr[0] = max( prices[index] - fee + front[1],0 + front[0]); 

		front = curr ;
	}

	// TC:O(n) and SC:O(1)
	return curr[1];
}
