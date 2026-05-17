/*
You are given a 2-D matrix board containing 'X' and 'O' characters.

If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.

Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board.

Example 1:



Input: board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","O","O","X"],
  ["X","X","X","O"]
]

Output: [
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","O"]
]
Explanation: Note that regions that are on the border are not considered surrounded regions.

Constraints:

1 <= board.length, board[i].length <= 200
board[i][j] is 'X' or 'O'.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(int row ,int col ,vector<vector<bool>> &visited ,vector<vector<char>>& board ,int m , int n ){

        if( row < 0 || row>=m || col < 0 || col>=n) return ;
        if( board[row][col]=='X') return ;
        if( visited[row][col]) return ;

        // Means it is reachable by 'O' 

        // Mark as visited and continue 
        visited[row][col] = true ; 

        for ( int delRow = -1 ; delRow<=1 ; delRow++){
            for(int delCol = -1 ; delCol<=1 ; delCol++){

                if(abs(delRow) + abs(delCol) == 1){
                     dfs(row + delRow,col + delCol,visited,board,m,n);
                }
            }
        }


    }

    void solve(vector<vector<char>>& board) {
        // Find the border 'O's because ofcourse they are not surrounded
        // Then find the 'O's that can be reached from the border 'O' as this will also be considered not surrounded 
        // Remember only possible moving directions is u,right,down,left

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));// This will help us to mark answers

        // Top row and bottom row 
        for(int col = 0 ; col < n ; col++){ 
            if(board[0][col]=='O'){
                dfs(0,col,visited,board,m,n);
            }
            if(board[m-1][col]=='O'){
                dfs(m-1,col,visited,board,m,n);
            }
        }


        // Left col and right col 
        for(int row = 0 ; row < m ; row++){ 
            if(board[row][0]=='O'){
                dfs(row,0,visited,board,m,n);
            }
            if(board[row][n-1]=='O'){
                dfs(row,n-1,visited,board,m,n);
            }
        }

        for(int row = 0 ; row < m ; row++ ){
            for(int col = 0 ; col < n ; col++){
                if( visited[row][col] == 0 && board[row][col] == 'O'){
                    // This 'O' is surrounded and so was not reachable 
                    // Change it 
                    board[row][col] = 'X';
                }
            }
        }
        
        //Once visited , it will not be processed again so 
        // TC:O(m*n)
        // SC:O(m*n) for the visited and recursive stack 
        return ;


    }
};
