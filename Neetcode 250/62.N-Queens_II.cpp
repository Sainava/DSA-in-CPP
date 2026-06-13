/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

You are given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:



Input: n = 4

Output: 2
Explanation: There are two different solutions to the 4-queens puzzle.

Example 2:

Input: n = 1

Output: 1
Constraints:

1 <= n <= 9
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int solve(int row , int n ,vector<bool> &colCheck ,vector<bool> &leftDiagonalCheck ,vector<bool> &rightDiagonalCheck ){
        if(row == n){
            return 1 ;
        }

        // check for all cols in this row 
        int cnt = 0 ; 

        for(int col = 0 ; col < n ; col++){

            if( colCheck[col] == false && 
                leftDiagonalCheck[(n-1) + (col - row)]==false && 
                rightDiagonalCheck[row + col] == false 
                ){
                
                    // Place queen here 
                    colCheck[col] = true ;
                    leftDiagonalCheck[(n-1) + (col - row)]= true ; 
                    rightDiagonalCheck[row + col] = true ;


                    cnt += solve(row + 1 , n ,  colCheck ,leftDiagonalCheck , rightDiagonalCheck );

                    // Backtrack 

                    colCheck[col] = false ;
                    leftDiagonalCheck[(n-1) + (col - row)]= false ; 
                    rightDiagonalCheck[row + col] = false ;
                }
        }

        return cnt ; 
    }

    int totalNQueens(int n) {
        
        vector<bool> colCheck(n,false);
        vector<bool> leftDiagonalCheck(2*n-1,false);
        vector<bool> rightDiagonalCheck(2*n-1,false);

        int row = 0 ;

        return solve(row , n , colCheck ,leftDiagonalCheck , rightDiagonalCheck );

        // Time Complexity:
        // O(n!)
        //
        // Reason:
        // - We place exactly one queen per row.
        // - At row 0 we can try up to n columns.
        // - At row 1 up to (n-1) columns.
        // - At row 2 up to (n-2) columns.
        // - ...
        // - This gives roughly n! valid/backtracking states.
        //
        // Placement validity checks are O(1) using
        // column and diagonal lookup tables.

        // Space Complexity:
        // O(n)
        //
        // Reason:
        // - O(n) recursion depth.
        // - O(n) column tracking.
        // - O(2n-1) left diagonal tracking.
        // - O(2n-1) right diagonal tracking.
        //
        // Overall auxiliary space = O(n).

    }
};