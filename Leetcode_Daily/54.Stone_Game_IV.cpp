// 10 August 2026

// 1510. Stone Game IV

/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player
makes a move consisting of removing any non-zero square number of stones in the
pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game
otherwise return false, assuming both players play optimally.



Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have
any moves. Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one
winning the game (2 -> 1 -> 0). Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move,
removing 4 stones (4 -> 0).


Constraints:

1 <= n <= 105
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool winnerSquareGame(int n) {

    vector<bool> dp(n + 1, false);

    // dp[0] = false
    // If there are 0 stones, the current player cannot move,
    // so they lose.

    for (int i = 1; i <= n; i++) {

      // Try removing every possible square number:
      // 1, 4, 9, 16, ...
      for (int j = 1; j * j <= i; j++) {

        int square = j * j;

        // If removing this square leaves the opponent
        // in a losing position, then current player wins.
        if (dp[i - square] == false) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};