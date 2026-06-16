/*
Alice and Bob are playing a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:

Input: piles = [1,2,3,1]

Output: true
Explanation: Alice takes first pile, then Bob takes the last pile, then Alice takes the pile from the end and Bob takes the last remaining pile. Alice's score is 1 + 3 = 4. Bob's score is 1 + 2 = 3.

Example 2:

Input: piles = [2,1]

Output: true
Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Alice start first so she will always win 
        
        // There are a few conditions 

        // One there are even elements in the array . So they get get to pick the same no of piles 

        // The total sum is odd 

        // This means if we divide the array into 2 ( since even no of elements ) One for alice and one for bob 
        // We know sum(one half) > sum(other half) since total sum is odd so one half is always greater 

        // Now essentially alice just has to pick the half that has more sum and since she start and she plays optimally she can do that and hence she will always win 


        // Say there are 2 piles [5,6] -> Alice starts so she justs picks the larger one ( here 6 ) so she wins 

        // Say 4 elements -> [5,1,100,6] -> Now if she is gredy at each step it is not gonna work 
        // Say she compares (5,6) and picks 6 now array->[5,1,100] . Bob will pick 100 and -> [5,1] -> She picks 5 and bob picks 1 
        // So total ALice = 11 (5 + 6) and Bob(101) so Bob wins . So playing optimally does not mean greddily 
        // Here since Alice starts she can essentially decide the next element she wants to pick 

        // Same question -> [5,1,100,6] -> Alice knows she wants to get the 100 one . Since she starts she can limit bob
        // She picks 5 , now array -> [1,100,6] -> No matter what bob picks -> Alice picks 100 and she wins 

        // That is the core idea . Alice can always decide what she wants to pick next 

        // Another VERY IMPORTANT observation

        // Alice  has a definite way of winning ,

        // Alice can decide to take all the even index elements or all the odd index elements

        // Say indices 0,1,2,3,.... (n-1) -> n-1 is odd since n is even 

        // Say she picks index 0 pile . Remaining is (1,2,3,4,....n-1) . Now Bob has no choice but to pick odd index

        // Say now bob picks 1 -> Remaining (2,3,4,...(n-1)) . Now Alice can pick even index(2) or odd( n -1 ) . But since she will pick even say 2
        // This means again Bob only has choices to pick odd indices 3 or n-1 

        // Question is why would she do this ?

        // Say Alice picked all the even index elements ( so n/2 she picked) . This FORCES Bob to pick all the odd index elements ( again n/2 elements)

        // Now she both have equal number of piles ( n/2 each ) but since total sum is odd .

        // Sum of one half -> Even indices or odd indices will be greater . Has to be because if they were equal that would mean Sum(n) = 2*sum(n/2) that would mean sum(n) is even and THAT IS NOT THE CASE 

        // So Alice only needs to see If( sum(even Indices) > sum(odd Indices)) . If yes she picks even indices . If NO she picks odd indices 

        // She picks the indices which have greater sum and WE are told she plays optimally meaning she makes the best choice 

        // So SHE STARTS FIRST AND GUARANTEES HER A VICTORY 

        //TC:O(1) and SC:O(1)
        return true ;


    }
};


class Solution {
public:
    int solve( int l , int r ,vector<int>& piles, vector< vector<int>> &dp ){
        // Base Case 
        if( l > r) return 0 ; // No elements to chosse from so  return 0 ; 

        if(dp[l][r] != -1 ) return dp[l][r];

        // Can Alice can choose l or r -> We know greedy approach does not work so we need to try both 

        // Lets say she took l -> (l , l + 1 , l +2 , ..... r -1 , r)
        // Next bob can choose l +1 or r leaving Alice next choice to be (l+2 ...r) or (l+1 ...r -1) ;
        // All are mutually exclusive cases 
        int left1 = piles[l] + solve(l+2 ,r , piles , dp) ; 
        int left2 = piles[l] + solve(l +1 , r-1 , piles ,dp) ;

        // Now if she picks r -> Bob is left with (l .... r-1 )
        // Alice next choice would be (l + 1 ..... r-1 ) or (l.... r-2 );

        int right1 = piles[r] + solve(l +1 , r-1 , piles, dp);
        int right2 = piles[r] + solve(l , r-2 , piles,dp);


        // Need the max of the four
        int left = max(left1 ,left2) ; 
        int right = max(right1 , right2);

        return dp[l][r] = max(left , right) ; 
        
    }

    bool stoneGame(vector<int>& piles) {
        // Solution one ONLY works if Total Sum = odd 
        // IF not we need a general solution 

        // So now this is like a game playing algorithm 

        // Again solution say elements -> [5,1,100,3,4,6]

        // Now Alice picks                  5   or           6 -> So two branches 
        //  Bob picks               (1  or   6)   or    (5      or  4) -> Second level 
        // Then Alice picks  (100 or 9 ) or (1 or 4) or (1 or 4) or (5 or 3) -> Third level


        // Then at the root we see if Alice or Bob took the greater sum -> We only need one since the other is just Total sum - sum(Alice)
        // Notice we can define states (left , right) for options they have and that these states are repeating ( like 1 or 4)

        // So DP Can be used 
        int n = piles.size() ; 
        vector< vector<int>> dp( n ,vector<int> ( n , -1 )); // l can  be n values and r van be n values 

        // (l,r) is basically starting and ending index of subarray 
        int l = 0 ; 
        int r = n - 1;

        // What is the max amount alice can get 
        // TC:O(n*n) and SC:O(n*n)
        int Alice = solve(l ,r , piles , dp) ; 
        
        int totalSum = 0 ;

        for(int p : piles){
            totalSum += p ;
        }

        int Bob = totalSum - Alice ;

        //TC:O(n*n) and SC:O(n*n)
        return Alice - Bob ;
    }
};