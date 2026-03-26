/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
*/
#include<iostream>
#include<vector>    
using namespace std ;

class Solution {
public:
    static int countNeighbours(int row , int col ,int m ,int n , vector<vector<int>>& board){
        // Consider the element to be a middle element of a 3x3 matrix and count 
        int cnt = 0 ;
        for(int i = row - 1 ; i <=row + 1  ; i++){
            for(int j = col - 1 ; j <=col + 1 ;j++){
                if(i==row and j==col) continue ; // DO NOT COUNT ITSELF 

                if( ( i>=0 && i<m )&&
                    ( j>=0 && j<n ) && 
                    ( board[i][j] == 1 || board[i][j] == 3)) cnt++;
            }
        }

        return cnt;
           
        }


    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size() ;
        int n = board[0].size() ;

        // Cell is 1 or 0 

        // Cell 1 stays 1 if 2 or 3 neighbours are 1 , else it dies
        // Cell 0 becomes 1 if exactly 3 of its neighbours are 1

        // Mapping required to solve in O(1) space 

        // Original -> New -> State 
        // 0        -> 0    ->  0
        // 1        -> 0    ->  1
        // 0        -> 1    ->  2
        // 1        -> 1    ->  3

        //TC:O(m x n )
        for(int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                
                // TC:O(9)
                int neighbours = countNeighbours( i , j, m , n , board);

                if(board[i][j] == 1){
                    if( neighbours == 2 || neighbours == 3){
                        board[i][j] = 3; // 1 will stay one 
                    }
                }
                else{ // cell is zero 
                    if(neighbours == 3 ){
                        board[i][j] = 2;
                    }
                }
                
            }
        }

        // Now change the (2 and 3 to 1) and (1 to 0)

        //TC:O(m x n)
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) {

                if(board[i][j] == 2 || board[i][j] == 3){
                    board[i][j] = 1;
                }else {
                    board[i][j] = 0 ;
                }
            }
        }

        // TC:O(2*(m x n ) ) and SC:O(1)
        return ;
    }
};