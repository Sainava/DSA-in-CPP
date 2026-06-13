/*
You are given a row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1.

Return the perimeter of the island.

Example 1:



Input: grid = [
    [1,1,0,0],
    [1,0,0,0],
    [1,1,1,0],
    [0,0,1,1]
]

Output: 18
Explanation: The perimeter is the 18 red stripes shown in the image above.

Example 2:

Input: grid = [[1,0]]

Output: 4
Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int dfs(int row , int col , int m , int n ,vector<vector<int>>& grid , vector<vector<bool>> &visited){
        

        visited[row][col] = true ; 

        int cnt = 0 ; // This returns the no of sides it is covered by water + plus its neighbours values 
        for(int delRow = -1 ; delRow <= 1 ; delRow++){
            for(int delCol = -1 ; delCol <= 1 ; delCol++){

                if( abs(delRow) + abs(delCol) == 1){

                    int r = row + delRow ; 
                    int c = col + delCol ; 

                    if (r < m && r >= 0 && c < n && c >= 0 && grid[r][c] == 1){
                        if( !visited[r][c] ) {
                            cnt += dfs(r , c , m , n , grid , visited);
                        }
                    }
                    else{
                        // Water 
                        cnt ++ ; 
                    }
                }
            }
        }

        return cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size();

        int row = 0 ; 
        int col = 0 ; 
        vector<vector<bool>> visited(m ,vector<bool> ( n ,false) );
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(grid[i][j] == 1){
                    // Since only one island so we only need to do this once 
                   return  dfs(i , j, m , n , grid , visited);
                }
            }
        }

        //TC:O(m x n ) and SC:O(m x n)
        return -1 ; 
    }
};