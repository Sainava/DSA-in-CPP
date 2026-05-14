/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard so that no two queens can attack each other.

A queen in a chessboard can attack horizontally, vertically, and diagonally.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a unique board layout where the queen pieces are placed. 'Q' indicates a queen and '.' indicates an empty space.

You may return the answer in any order.

Example 1:



Input: n = 4

Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There are two different solutions to the 4-queens puzzle.

Example 2:

Input: n = 1

Output: [["Q"]]
Constraints:

1 <= n <= 8
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void addSolution(vector<string>& board, vector<vector<string>>& ans) {
        ans.push_back(board);
    }

    void solve(
        int row,
        int n,
        vector<vector<string>>& ans,
        vector<string>& board,
        unordered_map<int,bool>& colCheck,
        unordered_map<int,bool>& leftDiagonalCheck,
        unordered_map<int,bool>& rightDiagonalCheck
    ) {

        // Base case
        if(row == n) {
            addSolution(board, ans);
            return;
        }

        // Try placing queen in every column of current row
        for(int col = 0; col < n; col++) {

            // Check if position is safe
            if(
                colCheck[col] == false &&
                leftDiagonalCheck[row + col] == false &&
                rightDiagonalCheck[(n - 1) + (col - row)] == false
            ) {

                // Place queen
                board[row][col] = 'Q';

                colCheck[col] = true;
                leftDiagonalCheck[row + col] = true;
                rightDiagonalCheck[(n - 1) + (col - row)] = true;

                // Recurse for next row
                solve(
                    row + 1,
                    n,
                    ans,
                    board,
                    colCheck,
                    leftDiagonalCheck,
                    rightDiagonalCheck
                );

                // Backtrack
                board[row][col] = '.';

                colCheck[col] = false;
                leftDiagonalCheck[row + col] = false;
                rightDiagonalCheck[(n - 1) + (col - row)] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        unordered_map<int,bool> colCheck;
        unordered_map<int,bool> leftDiagonalCheck;
        unordered_map<int,bool> rightDiagonalCheck;

        solve(
            0,
            n,
            ans,
            board,
            colCheck,
            leftDiagonalCheck,
            rightDiagonalCheck
        );

        return ans;
    }
};