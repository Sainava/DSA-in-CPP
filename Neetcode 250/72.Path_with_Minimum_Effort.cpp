/*
ou are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:

Input: heights = [
    [1,1,1],
    [3,2,4],
    [2,5,4]
]

Output: 2
Explanation: The route of [1,1,2,4,4] has a maximum absolute difference of 2 in consecutive cells.

Example 2:

Input: heights = [
    [1,1,1],
    [1,1,2],
    [6,5,2]
]

Output: 1
Explanation: The route of [1,1,1,1,1,2,2] has a maximum absolute difference of 1 in consecutive cells.

Constraints:

row == heights.length
col == heights[i].length
1 <= row, col <= 100
1 <= heights[i][j].length <= 1,000,000 .

*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // DIJKSTRA ON GRID 

        //{dist , row , col}
        priority_queue< vector<int> , vector<vector<int> > , greater<vector<int>> > pq ; 

        int m = heights.size() ; 
        int n = heights[0].size() ; 

        vector<vector<int>> dist( m , vector<int> (n , INT_MAX)) ; // Stores max diff in the path to reach this cell 
        // NOT the previous dist but the maximum difference between any two cells in the path  to reach this cell 
 
        dist[0][0] = 0 ; 

        pq.push({0 , 0 , 0 });

        while( !pq.empty()){
            auto it = pq.top() ; 
            pq.pop() ; 

            int diff  = it[0] ; 
            int row = it[1] ; 
            int col = it[2] ; 

            if( row == m-1 && col == n -1 ) return diff;

            if(diff > dist[row][col])
                continue;


            for(int delRow = -1 ; delRow <= 1 ; delRow++){
                for(int delCol = -1 ; delCol <=1 ; delCol++){

                    if(abs(delRow) + abs(delCol) == 1 ) {

                        int r = row + delRow  ;
                        int c = col + delCol ; 

                        if( r >= 0 && r < m && c >=0 && c < n 
                        && max(diff , abs( heights[row][col] - heights[r][c])) < dist[r][c]
                        ){
                            dist[r][c] = max(diff , abs( heights[row][col] - heights[r][c]));

                            pq.push({dist[r][c] , r , c});
                        }
                    }
                }
            }

           
        }

        // Let V = m*n
        //
        // Time:
        // O(V log V)
        // = O(m*n*log(m*n))
        //
        // Each cell may enter the heap multiple times,
        // but Dijkstra's standard bound remains
        // O(E log V), and E ≈ 4V. ( as each cell can have 4 edges as it can be reached through four directions )
        //
        // Space:
        // O(m*n)
        //
        // dist matrix + priority queue
        return -1 ;
    }
};