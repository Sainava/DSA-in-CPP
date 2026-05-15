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
    void solve(int row , int n ,vector<string> &board ,vector<vector<string>> &ans ,unordered_map<int,bool> &colCheck ,unordered_map<int,bool> &leftDiagonalCheck ,unordered_map<int,bool> &rightDiagonalCheck ){
        if(row == n){
            ans.push_back(board);
            return ;
        }

        // check for all cols in this row 
        for(int col = 0 ; col < n ; col++){

            if( colCheck[col] == false && 
                leftDiagonalCheck[(n-1) + (col - row)]==false && 
                rightDiagonalCheck[row + col] == false 
                ){
                
                    // Place queen here 
                    colCheck[col] = true ;
                    leftDiagonalCheck[(n-1) + (col - row)]= true ; 
                    rightDiagonalCheck[row + col] = true ;

                    board[row][col] = 'Q';

                    solve(row + 1 , n , board , ans , colCheck ,leftDiagonalCheck , rightDiagonalCheck );

                    // Backtrack 
                    board[row][col] = '.';

                    colCheck[col] = false ;
                    leftDiagonalCheck[(n-1) + (col - row)]= false ; 
                    rightDiagonalCheck[row + col] = false ;
                }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;

        vector<string> board( n , string(n , '.'));

        unordered_map<int,bool> colCheck ;
        unordered_map<int,bool> leftDiagonalCheck ;
        unordered_map<int,bool> rightDiagonalCheck ;

        int row = 0 ;

        solve(row , n , board , ans , colCheck ,leftDiagonalCheck , rightDiagonalCheck );
        //TC:O(n! * no of solutions) as first row has n choices , second row has n-1 choices , and so on so n! and each solution is copied 
        //SC:O(n) recursive stack 
        //SC:O(n^2) for board and SC:O(n) hash maps 
        return ans ;
    }
};
