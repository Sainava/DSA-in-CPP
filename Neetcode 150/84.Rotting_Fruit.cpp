/*
You are given a 2-D matrix grid. Each cell can have one of three possible values:

0 representing an empty cell
1 representing a fresh fruit
2 representing a rotten fruit
Every minute, if a fresh fruit is horizontally or vertically adjacent to a rotten fruit, then the fresh fruit also becomes rotten.

Return the minimum number of minutes that must elapse until there are zero fresh fruits remaining. If this state is impossible within the grid, return -1.

Example 1:



Input: grid = [[1,1,0],[0,1,1],[0,1,2]]

Output: 4
Example 2:

Input: grid = [[1,0,1],[0,2,0],[1,0,1]]

Output: -1
Constraints:

1 <= grid.length, grid[i].length <= 10
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Grid -> need distance as fruits near to rotten fruits get rotten quicker so think of bfs 

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q ; 

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){

                if( grid[row][col] == 2 ){
                    q.push({row,col});
                }
            }
        }

        // We pushed all rotten fruits in the queue 

        while( !q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int delRow = -1 ; delRow <= 1 ; delRow++){
                for(int delCol = -1 ; delCol <= 1 ; delCol++){
                    if( abs(delRow) + abs(delCol) == 1){
                        int r = row + delRow ; 
                        int c = col + delCol ;

                        if( r >= 0 && r < m && c >= 0 && c<n && grid[r][c] == 1){
                            grid[r][c] = grid[row][col] + 1 ; 
                            q.push({r,c});
                        }
                        
                    }
                }
            }
        }

        // We marked the fruits that get rotten as time t ( but time starts from 2 so be careful)

        //traverse again to see to find max or if any fruits remain 

        int maxCount = 0 ; 
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){

                if( grid[row][col] == 1 ){
                    return -1 ; // fresh fruits remain 
                }

                if( grid[row][col] > 2){
                    maxCount = max(maxCount , grid[row][col] - 2);
                }
                
            }
        }

        //TC:O(m*n) and SC:O(m*n)
        return maxCount ; 

    }
};
