/*
You are given a matrix grid where grid[i] is either a 0 (representing water) or 1 (representing land).

An island is defined as a group of 1's connected horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

The area of an island is defined as the number of cells within the island.

Return the maximum area of an island in grid. If no island exists, return 0.

Example 1:



Input: grid = [
  [0,1,1,0,1],
  [1,0,1,0,1],
  [0,1,1,0,1],
  [0,1,0,0,1]
]

Output: 6
Explanation: 1's cannot be connected diagonally, so the maximum area of the island is 6.

Constraints:

1 <= grid.length, grid[i].length <= 50
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     void dfs(int row, int col ,vector<vector<int>>& grid ,vector<vector<bool>> &visited,int m , int n ,int &area ,int &maxArea ){
    // base case ->3 conditions
        if( row < 0 || row>= m || col < 0 || col>=n) return ;
        if( grid[row][col]== 0) return ;
        if(visited[row][col]) return ;

        area++;
        maxArea = max(maxArea , area);
        visited[row][col] = true ; //consider in an island 

        // right 
        dfs(row,col+1,grid,visited,m,n,area,maxArea);

        // down 
        dfs(row+1,col,grid,visited,m,n,area,maxArea);

        // left
        dfs(row,col-1,grid,visited,m,n,area,maxArea);

        //up
        dfs(row-1,col,grid,visited,m,n,area,maxArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<bool>> visited(m , vector<bool>(n , false));
        int maxArea = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(visited[row][col]==false && grid[row][col]==1){
                    int area = 0 ;
                    dfs(row,col,grid,visited, m ,n , area , maxArea);
                }

            }
        }

        //TC:O(4*m*n)
        //SC:O(m*n) for visited and recursion stack
        return maxArea;
    }


};
