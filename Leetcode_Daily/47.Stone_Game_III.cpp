// 3 August 2026

//1406. Stone Game III

/*
Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

 

Example 1:

Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
Example 2:

Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
Example 3:

Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
 

Constraints:

1 <= stoneValue.length <= 5 * 104
-1000 <= stoneValue[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve( int index ,vector<int>& stoneValue , vector<int> &dp){
        if (index == stoneValue.size() ) return 0 ;

        if(dp[index]!= -1 ) return dp[index] ; 

        int res = INT_MIN ; // Since Alice will try to maximise (Alice - Bob) and Bob will try to maximise ( Bob - Alice )

        // Question says at max we can take three values 
        int total = 0 ; 
        for(int i = index ; i < index + 3 ; i++){
            if( i >= stoneValue.size()) break ;

            total += stoneValue[i] ; 

            res = max(res ,total - solve(i + 1 , stoneValue , dp) ) ;
        }
        // Why total - recursive call 
        // Think say total is Alice score and what solve will return is ( Bob - Alice )
        // So Alice - ( Bob - Alice) Becomes Alice - Bob which we are retruning 

        // Similarly from Bob's perspective total is Bob's score
        // And ultimately is becomes Bob - ( Alice - Bob) = Bob - Alice 

        return dp[index] =  res ; 
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // We try a different solution than Stone Game 2 which is a bit optimised 
        // Also Stone value here can be negative that only means we need to change how we were intitialisign res and nothing else 

        // We track (Aice - Bob)  or (Bob - Alice) instead of Alice score or Bob score 
        int index = 0 ; 
        int n = stoneValue.size(); 
        vector<int> dp( n , -1 );
        int ans =  solve(index , stoneValue , dp) ; 

        //TC:O(n*3) and SC:O(n+n)
        if ( ans > 0 ) return "Alice" ;
        else if ( ans == 0 ) return "Tie" ; 
        else return "Bob" ; 
    }
};