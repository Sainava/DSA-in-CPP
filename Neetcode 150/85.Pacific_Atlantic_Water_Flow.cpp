/*
You are given a rectangular island heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The islands borders the Pacific Ocean from the top and left sides, and borders the Atlantic Ocean from the bottom and right sides.

Water can flow in four directions (up, down, left, or right) from a cell to a neighboring cell with height equal or lower. Water can also flow into the ocean from cells adjacent to the ocean.

Find all cells where water can flow from that cell to both the Pacific and Atlantic oceans. Return it as a 2D list where each element is a list [r, c] representing the row and column of the cell. You may return the answer in any order.

Example 1:



Input: heights = [
  [4,2,7,3,4],
  [7,4,6,4,7],
  [6,3,5,3,6]
]

Output: [[0,2],[0,4],[1,0],[1,1],[1,2],[1,3],[1,4],[2,0]]
Example 2:

Input: heights = [[1],[1]]

Output: [[0,0],[1,0]]
Constraints:

1 <= heights.length, heights[r].length <= 100
0 <= heights[r][c] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(int row , int col ,vector<vector<bool>> &visited ,vector<vector<int>>& heights ,int m , int n , int current ){
        if( row < 0 || row >=m || col < 0 || col>= n) return ;
        if(visited[row][col]) return ; 

        
        if (heights[row][col] >= current){
            visited[row][col] = true ;  // This means it is reachable by ocean 
            // That is why we do not do visit earlie as a cell that cannot be reached by this starting cell may be reachable by other starting cell so we need to check it more than once 

            // now check the others 

            for(int delRow = -1 ; delRow <=1 ; delRow++){
                for(int delCol = -1 ; delCol <= 1 ; delCol++){
                    if( abs(delRow) + abs(delCol) == 1 ) {
                        dfs(row + delRow, col+delCol ,visited,heights,m,n,heights[row][col] );
                }
            }
                    
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Instead of thinking can i reach both oceans from this cell , 
        // Reverse and think , what cells from the ocean 

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> visitPacific(m , vector<bool> (n , false)); // here visited is only marked true when it is reachable by ocean 
        vector<vector<bool>> visitAtlantic(m , vector<bool> (n , false));

        // For the pacific ocean we need to check the first row and the first col
        // For the atlantic ocean we need to check the last row and the last col

        // First row and last row 
        for(int col = 0 ; col < n ; col++){
            dfs(0, col ,visitPacific,heights,m,n, heights[0][col]);
            dfs(m-1, col ,visitAtlantic,heights,m,n, heights[m-1][col]);
        }

        // First col and last col
        for(int row = 0 ; row < m ; row++){
            dfs(row , 0 ,visitPacific,heights,m,n, heights[row][0]);
            dfs(row , n-1 ,visitAtlantic,heights,m,n, heights[row][n-1]);
        }

        vector<vector<int>> ans ; 

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(visitPacific[row][col] && visitAtlantic[row][col]){
                    ans.push_back({row,col});
                }
            }
        }

        // Each cell once reachable(visited) will not be proessed again and will return immediately 
        // This is the same for pacific and atlantic 
        // SO TC:O(2(m*n))

        // SC:O(m*n) recursion stack and visited 
        return ans ;
           
    }
};
