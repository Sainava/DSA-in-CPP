/*
You are given a 
m
×
n
m×n 2D grid initialized with these three possible values:

-1 - A water cell that can not be traversed.
0 - A treasure chest.
INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest then the value should remain INF.

Assume the grid can only be traversed up, down, left, or right.

Modify the grid in-place.

Example 1:

Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]
Example 2:

Input: [
  [0,-1],
  [2147483647,2147483647]
]

Output: [
  [0,-1],
  [1,2]
]
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is one of {-1, 0, 2147483647}
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        // unweighted graph and distances -> BFS 

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q ; 

        //TC:O(m*n)
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]== 0){
                    q.push({row,col});
                }
            }
        }

        // We have all treasures in the queue , now we just do bfs from each and update distances

        //TC:O(m*n) since even though we check 4 directions , we push only once 
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second ;
            q.pop();

            for(int delRow = -1 ; delRow<=1; delRow++){
                for(int delCol = -1 ; delCol <= 1 ; delCol++){
                    if( abs(delRow) + abs(delCol) == 1){
                        int r = row + delRow ;
                        int c = col + delCol ;

                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == INT_MAX){
                            // Now we are in an island 
                            grid[r][c] =grid[row][col] + 1;
                            q.push({r,c});
                        }
                    
                    }
                    
                }
            }
        }

        //TC:O(m*n) and SC:O(m*n)
        return ;
            
    }
};
