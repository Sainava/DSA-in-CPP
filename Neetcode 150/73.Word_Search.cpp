/*
Given a 2-D grid of characters board and a string word, return true if the word is present in the grid, otherwise return false.

For the word to be present it must be possible to form it with a path in the board with horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.

Example 1:



Input: 
board = [
  ["A","B","C","D"],
  ["S","A","A","T"],
  ["A","C","A","E"]
],
word = "CAT"

Output: true
Example 2:



Input: 
board = [
  ["A","B","C","D"],
  ["S","A","A","T"],
  ["A","C","A","E"]
],
word = "BAT"

Output: false
Constraints:

1 <= board.length, board[i].length <= 5
1 <= word.length <= 10
board and word consists of only lowercase and uppercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, string &word , int index ,bool &isPresent ,int row , int col , vector<vector<bool>> &visited){
        // base cases
                //check if this is the character we needed  
        if(index == word.length()) {
            isPresent = true ;
            return ;
        }
        
        if(row < 0 || row >= board.size() || col < 0 || col>= board[0].size()){
            return ;
        }

        if( visited[row][col]) return ; // already visited 

        if(word[index]!= board[row][col]) return  ; // Not a valid solution 

        visited[row][col] = true ;

        // Now check for the next characters 
        // Move to the next cells
        // Right 
        dfs(board , word, index + 1 , isPresent , row, col+1 , visited );

        // Down
        dfs(board , word, index + 1 , isPresent , row+1, col , visited );

        // Up
        dfs(board , word, index + 1 , isPresent , row-1, col , visited);

        // Left
        dfs(board , word, index + 1 , isPresent , row, col-1 , visited);

        visited[row][col] = false ;

        return ;

    }


    bool exist(vector<vector<char>>& board, string word) {
        // At each cell we add the word and check when length is same 
        int rows= board.size();
        int cols = board[0].size() ;
        bool isPresent = false ;
        vector<vector<bool>> visited(rows, vector<bool> (cols,0));
        int index = 0 ; // index of the result we are checking for 
        // At every cell we check if this could be the starting character and check 

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(!isPresent){
                    dfs(board, word, 0 , isPresent , i , j , visited);
                }
                
            }
        }

        // TC:O(R * C * 4^L) as for each cell (which there are R*C of) we go 4 directions till the last level L
        // SC:O(R*C + L) R*C for the visited and L for the recursion stack as L levels 
        return isPresent ;
    }
};

class Solution {
public:
    bool dfs(int row , int col ,int index ,vector<vector<char>>& board, string word ,vector<vector<bool>> &visited ,int m , int n){

        if(index == word.size() - 1) return true;

        visited[row][col]  = true  ;    

        bool isPossible = false ; 
        for(int delRow = -1 ; delRow <= 1 ; delRow++){
            for(int delCol = -1 ; delCol <= 1 ; delCol++){
                if( abs(delRow)+ abs(delCol) == 1){
                    int r = row+delRow ;
                    int c = col + delCol ; 

                    if( r>= 0 && r<m && c>= 0 && c<n && !visited[r][c] && index + 1 < word.size() && board[r][c]== word[index + 1]){
                        isPossible = dfs(r , c,index + 1 , board , word ,  visited ,m ,n);
                    }
                   if(isPossible){
                        visited[row][col]  = false ; 
                        return true ; 
                   } 
                }
            }
        }
        visited[row][col]  = false ; 
        return isPossible ; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size() ; 

        
        vector<vector<bool>> visited(m , vector<bool>(n,false)); // Will bactrack 
        bool isPresent = false ; 
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                    
                    isPresent = dfs(i , j,0 , board , word ,  visited ,m ,n);
                }
                if(isPresent) return true ; 
            }
        }

        // TC:O(R * C * 4^L) as for each cell (which there are R*C of) we go 4 directions till the last level L
        // SC:O(R*C + L) R*C for the visited and L for the recursion stack as L levels 
        return false ; 
    
    }
};
