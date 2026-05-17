/*
Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

Example 1:

Input: grid = [
    ["0","1","1","1","0"],
    ["0","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]
Output: 1
Example 2:

Input: grid = [
    ["1","1","0","0","1"],
    ["1","1","0","0","1"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
  ]
Output: 4
Constraints:

1 <= grid.length, grid[i].length <= 100
grid[i][j] is '0' or '1'.
*/
#include <iostream>
#include <vector>
using namespace std;

// DFS approach
class Solution {
public:
    void dfs(int row, int col ,vector<vector<char>>& grid ,vector<vector<bool>> &visited,int m , int n  ){
        // base case ->3 conditions
        if( row < 0 || row>= m || col < 0 || col>=n) return ;

        if( grid[row][col]=='0') return ;

        if(visited[row][col]) return ;

        visited[row][col] = true ; //consider in an island 

        // right 
        dfs(row,col+1,grid,visited,m,n);

        // down 
        dfs(row+1,col,grid,visited,m,n);

        // left
        dfs(row,col-1,grid,visited,m,n);

        //up
        dfs(row-1,col,grid,visited,m,n);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<bool>> visited(m , vector<bool>(n , false));
        int cnt = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(visited[row][col]==false && grid[row][col]=='1'){
                    cnt++;
                    dfs(row,col,grid,visited, m ,n);
                }

            }
        }
    // Each cell explores 4 directions using DFS
    // But once a cell is visited, it is never processed again

    // So although each DFS call makes 4 recursive calls,
    // every cell is actually visited only once overall

    // TC: O(4 * m * n) = O(m * n)

    // SC: O(m * n) for visited array

    // Recursive stack can go up to O(m * n)
    // in the worst case when the entire grid is one island 
        return cnt ;
    }
};

//BFS
class Solution {
public:
    void bfs(int row , int col ,vector<vector<char>>& grid ,vector<vector<bool>> &visited , int m ,int n ){
        visited[row][col] = true ; 

        queue<pair<int,int>> q ;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second;
            q.pop();

            // traverse the neighbours 

            for(int delRow = -1 ; delRow<=1 ; delRow++){
                for(int delCol = -1 ;delCol<=1 ; delCol++){
                        if( abs(delRow) + abs(delCol) == 1){
                            int nrow = row + delRow ;
                            int ncol = col + delCol ;
                            if( nrow < m && nrow>=0 && ncol<n && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                                q.push({nrow,ncol});
                                visited[nrow][ncol] = true;
                            }
                        }
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // we try bfs 
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<bool>> visited(m , vector<bool>(n , false));
        int cnt = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(visited[row][col]==false && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,grid,visited, m ,n);
                }

            }
        }
    // Each cell explores 4 directions using BFS
    // But once a cell is visited, it is never processed again

    // So although each DFS call makes 4 recursive calls,
    // every cell is actually visited only once overall

    // TC: O(4 * m * n) = O(m * n)

    // SC: O(m * n) for visited array

    // Recursive stack can go up to O(m * n)
    // in the worst case when the entire grid is one island 
        return cnt ;
    }
};
