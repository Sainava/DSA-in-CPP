//2 June 2026

//3286. Find a Safe Walk Through a Grid

/*
You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.


Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.


Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.



Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
2 <= m * n
1 <= health <= m + n
grid[i][j] is either 0 or 1.
 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        // Health remaining after entering the starting cell
        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        // best[r][c] = maximum health remaining with which we have
        // reached cell (r,c). If we reach it again with less or equal
        // health, that path is useless.
        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0}, startHealth});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()){

            auto cur = q.front();
            q.pop();

            int r = cur.first.first;
            int c = cur.first.second;
            int remHealth = cur.second;

            if(r == m-1 && c == n-1)
                return true;

            for(auto [dr,dc] : dir){

                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = remHealth - grid[nr][nc];

                // Must always have positive health
                if(newHealth <= 0)
                    continue;

                // Already reached this cell with equal or more health
                if(best[nr][nc] >= newHealth)
                    continue;

                best[nr][nc] = newHealth;

                q.push({{nr,nc}, newHealth});
            }
        }

        return false;
    }
};