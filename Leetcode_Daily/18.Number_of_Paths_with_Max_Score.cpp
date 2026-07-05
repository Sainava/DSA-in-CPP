// 05 July 2026

//1301. Number of Paths with Max Score

/*
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Starting point
        score[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'X')
                    continue;

                if (i == 0 && j == 0)
                    continue;

                int best = -1;
                long long cnt = 0;

                // From Top
                if (i > 0 && score[i-1][j] != -1) {

                    if (score[i-1][j] > best) {
                        best = score[i-1][j];
                        cnt = ways[i-1][j];
                    }
                    else if (score[i-1][j] == best) {
                        cnt = (cnt + ways[i-1][j]) % MOD;
                    }
                }

                // From Left
                if (j > 0 && score[i][j-1] != -1) {

                    if (score[i][j-1] > best) {
                        best = score[i][j-1];
                        cnt = ways[i][j-1];
                    }
                    else if (score[i][j-1] == best) {
                        cnt = (cnt + ways[i][j-1]) % MOD;
                    }
                }

                // From Diagonal
                if (i > 0 && j > 0 && score[i-1][j-1] != -1) {

                    if (score[i-1][j-1] > best) {
                        best = score[i-1][j-1];
                        cnt = ways[i-1][j-1];
                    }
                    else if (score[i-1][j-1] == best) {
                        cnt = (cnt + ways[i-1][j-1]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                score[i][j] = best;

                if (board[i][j] != 'S')
                    score[i][j] += board[i][j] - '0';

                ways[i][j] = cnt % MOD;
            }
        }

        if (score[n-1][n-1] == -1)
            return {0,0};

        // TC: O(n²)
        // Each cell checks at most 3 neighbors.
        //
        // SC: O(n²)
        // score[][] + ways[][]
        return {score[n-1][n-1], ways[n-1][n-1]};
    }
};