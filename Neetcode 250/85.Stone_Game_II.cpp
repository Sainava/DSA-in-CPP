/*
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [3,1,2,5,7]

Output: 10
Explanation: Alice takes first pile, then Bob takes the second pile, then Alice takes the next two piles and Bob takes the last remaining pile. This makes Alice's score 3 + 2 + 5 = 10, which is the maximum Alice can get.

Example 2:

Input: piles = [4,3,2,5,10]

Output: 11
Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10,000

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve (int alice , int index , int M ,vector<int>& piles ,vector < vector < vector<int> >> &dp ){
        if(index == piles.size()) return 0 ; 

        if( dp[alice][index][M] != -1 ) return dp[alice][index][M] ;

        int res = 0 ; // IF Alice turn

        if(alice == 1){
            // Bob's turn 
            res = INT_MAX ; // Since we need to minimise it 
        }

        // Question says that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.
        int total = 0 ; // stores sum of subarray ( index to index + 2M - 1) -> Since index is the first new element we can take and we can atmax take 2M elements 
        for(int x = 1; x <= 2*M ; x++){
            if( index + x - 1 >= piles.size()) break ; // We are out of bounds 

            total += piles[index + x - 1] ;

            if( alice == 0) {
                // We need to maximise the res 
                res = max( res ,total + solve(1 , index + x , max(M , x) , piles , dp )) ;
            }
            else {
                res = min( res , solve(0 , index + x ,max(M , x) , piles , dp )); // Here solve returns alice score so we bob tries to minimise that
            }
        }


        return dp[alice][index][M] = res ; // Remember this is just the scpre that Alice got so we added total to its recursion call and not to bob's
    }

    int stoneGameII(vector<int>& piles) {
        // We need Alice's score 

        // So this is like a game playing algorithm 
        // On Alice turn she will try to maxmise her score 
        //On Bob turn he will try to minimise alice score -> The question does not care about Bob score so we won't either 
        int n = piles.size() ;
        // DP state { 2 , n , n } 2 for Alice or Bob -> Then n choices for the starting index and n for the value of m as it changes throughout the question
        vector < vector < vector<int> >> dp ( 2 , vector <vector <int>> ( n + 1, vector <int> ( n + 1 , -1)));

        //TC :O( 2 * n * n * n) ( The last n is for the loop we run at every call) = TC:O(n^3)
        // SC:O( 2 * n * n)  = SC:O(n^2)
        return solve( 0 , 0 , 1 , piles , dp ) ;  // 0 means Alice and she starts from index 1 and M initial value is 1 
    }
};