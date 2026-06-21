// 21 June 2026

//1833. Maximum Ice Cream Bars

/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSortArray(vector<int>& nums) {

        // Will use counting sort -> Only use when the maxNumber is not large and numbers are non - negative

        // Step 1 : Find the maximum number 

        int k = INT_MIN ; // max Number 

        for(int num : nums){
            k = max(k , num) ;
        }

        // Step 2 : Create a vector of size k + 1 . We will store frequencies in this . Now the max number is k and we assume min is 0 
        vector<int> vec(k+1 , 0);

        for(int num: nums){
            vec[num]++;
        }

        //Step 3: Now we have the frequencies . Now we will do a prefix sum for all elements

        for(int i = 1 ; i < vec.size() ; i++){
            vec[i] = vec[i] + vec[i-1] ;
        }

        //Step 4 
        // Now we shift each element by 1 and make last index 0 
        for(int i = k  ; i>= 1 ; i--){
            vec[i] = vec[i-1];
        }
        vec[0] = 0 ;

        // Step 5 : After the last step what we have at each index is how many numbers are there before this number 
        // So we basically have the starting index of each 
        int n = nums.size() ;
        vector<int> ans(n , 0);

        for(int i = 0 ; i < n ; i++){
            int index = vec[nums[i]];
            vec[nums[i]]++;

            ans[index] = nums[i] ; 
        }
        
        return ans ; 
    }

    int maxIceCream(vector<int>& costs, int coins) {
        // // Solution 1 
        // int maxCnt = 0 ; 
        // sort(costs.begin() , costs.end());

        // for(int cost : costs){
        //     if(coins - cost >= 0){
        //         coins = coins - cost ;
        //         maxCnt++;
        //     }else{
        //         return maxCnt ; 
        //     }
            
        // }
        // //TC:O(nlogn) and SC:O(logn)
        // return maxCnt ; 


        // // Solution 2 -> Will use counting sort 
        // costs = countSortArray( costs ) ; 

        // int maxCnt = 0 ; 
        // for(int cost : costs){
        //     if(coins - cost >= 0){
        //         coins = coins - cost ;
        //         maxCnt++;
        //     }else{
        //         return maxCnt ; 
        //     }
            
        // }
        // // TC :O( n + max(array) ) and SC:O(n + max(array) ) for countsort 
        // // So overall TC:O(n + max(costs)) and SC:O(n + max(costs) )
        // return maxCnt ; 


        // Solution 3 : Using the frequency array directly from counting sort 

        // Step 1 : Find the maximum number 

        int k = INT_MIN ; // max Number 

        for(int num : costs){
            k = max(k , num) ;
        }

        // Step 2 : Create a vector of size k + 1 . We will store frequencies in this . Now the max number is k and we assume min is 0 
        vector<int> freq(k+1 , 0);

        for(int num: costs){
            freq[num]++;
        }

        // Now we do greedy of the freq directly ; 
        int total = freq[0] ;  // Doesn't make a difference as the constraints say no ice cream costs 0 so we can do total = 0 
        for(int i = 1 ; i < freq.size() ; i++){
            if( coins < i ) break ;

            int canBuy = min( freq[i] , coins/i); 
            coins -= canBuy * i;
            total = total + canBuy;
            
        }

        //TC:O(n + max(costs)) and SC:O(max(costs))  k is bounded by 10^5 so may say O(n) but that is approx and not accurate -> Optimal O( n + k ) where k = max(costs)
        return total  ; 
    }
};