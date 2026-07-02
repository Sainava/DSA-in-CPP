// 1 July 2026

//2812. Find the Safest Path in a Grid

/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

 

Example 1:


Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
Example 2:


Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
Example 3:


Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
 

Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        //----------------------------------------------------------
        // Step 1:
        // Multi-source BFS to compute the distance of every cell
        // from the nearest thief.
        //----------------------------------------------------------

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();

            for(auto [dx,dy]:dirs){

                int nx=x+dx;
                int ny=y+dy;

                if(nx<0 || ny<0 || nx>=n || ny>=n)
                    continue;

                if(dist[nx][ny]!=INT_MAX)
                    continue;

                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }

        //----------------------------------------------------------
        // Step 2:
        // Binary search on the answer.
        //
        // Can we find a path whose every cell has
        // distance >= mid ?
        //----------------------------------------------------------

        auto canReach = [&](int safe){

            if(dist[0][0] < safe)
                return false;

            queue<pair<int,int>> q;

            vector<vector<int>> vis(n, vector<int>(n,0));

            q.push({0,0});
            vis[0][0]=1;

            while(!q.empty()){

                auto [x,y]=q.front();
                q.pop();

                if(x==n-1 && y==n-1)
                    return true;

                for(auto [dx,dy]:dirs){

                    int nx=x+dx;
                    int ny=y+dy;

                    if(nx<0 || ny<0 || nx>=n || ny>=n)
                        continue;

                    if(vis[nx][ny])
                        continue;

                    if(dist[nx][ny] < safe)
                        continue;

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }

            return false;
        };

        int lo=0;
        int hi=2*n;

        while(lo<hi){

            int mid=(lo+hi+1)/2;

            if(canReach(mid))
                lo=mid;
            else
                hi=mid-1;
        }

        return lo;
    }
};