/*
Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
0 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false
Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.
Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10
Sample Output 2:
true
false
Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.


Hints:
1. Can you find every possible subset of ‘ARR’ and check if its sum is equal to ‘K’?
2. Can you use dynamic programming and use the previously calculated result to calculate the new result?
3. Try to use a recursive approach followed by memoization by including both index and sum we can form. 
*/
#include <iostream>
#include <vector>
using namespace std;

bool func(int index , int target , int n ,vector<int> &arr){
    if( target == 0 ) return true ; 
    if(index == n || target < 0) return false ;

    // Either take or dont take 
    bool noTake = func(index+1 , target ,n,arr );

    // Take 
    bool take  = func(index + 1 , target - arr[index] , n , arr);

    return noTake || take ; 
}

bool funcTopDown(int index , int target , int n ,vector<int> &arr ,vector<vector<int>> &dp){
    if( target == 0 ) return true ; 
    if(index == n || target < 0) return false ;

    if(dp[index][target]!= -1) return dp[index][target];
    
    // Either take or dont take 
    bool noTake = funcTopDown(index+1 , target ,n,arr ,dp );

    // Take 
    bool take  =funcTopDown(index + 1 , target - arr[index] , n , arr ,dp);

    return dp[index][target]= noTake || take ; 
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Exponential 
    //return func(0 , k , n , arr);

    // // Top Down 
    // vector<vector<int>> dp(n , vector<int>(k+1, -1));
    // // dp[i][j] tells if it is possible to reach target j by taking or not taking i 
    // //TC:O(n*k) and SC:O(n*k)
    // return funcTopDown(0 , k , n , arr , dp);


    // // Bottom Up
    // vector<vector<int>> dp(n+1 , vector<int>(k+1, 0)) ;
    // // Entire dp[n][any number] = 0 
    // for(int i = 0 ; i <= n ; i++){
    //     dp[i][0] = 1 ; 
    // }

    // // Now traverse in reverse order 

    // for(int index = n-1 ; index >=0 ; index--){
    //     for(int target = 0 ; target <= k ; target++){
    //         // Either take or dont take 
    //         bool noTake = dp[index+1][target];

    //         bool take = false ; 
    //         // Take 
    //         if( target - arr[index] >=0 ){
    //             take = dp[index+1][target - arr[index]];
    //         }

    //        dp[index][target]= noTake || take ; 
    //     }
    // }
    // // //TC:O(n*k) and SC:O(n*k)
    // return dp[0][k];

    // Space optimised 
    vector<int> curr(k+1);
    vector<int> next(k+1);

    next[0] = 1;

    for(int index = n-1 ; index >=0 ; index--){
        for(int target = 0 ; target <= k ; target++){
            // Either take or dont take 
            bool noTake = next[target];

            bool take = false ; 
            // Take 
            if( target - arr[index] >=0 ){
                take = next[target - arr[index]];
            }

          curr[target]= noTake || take ; 
        }
        next = curr;
    }
    // //TC:O(n*k) and SC:O(k)
    return curr[k];



}