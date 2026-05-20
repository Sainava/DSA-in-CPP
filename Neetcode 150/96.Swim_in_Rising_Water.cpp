/*
You are given a square 2-D matrix of distinct integers grid where each integer grid[i][j] represents the elevation at position (i, j).

Rain starts to fall at time = 0, which causes the water level to rise. At time t, the water level across the entire grid is t.

You may swim either horizontally or vertically in the grid between two adjacent squares if the original elevation of both squares is less than or equal to the water level at time t.

Starting from the top left square (0, 0), return the minimum amount of time it will take until it is possible to reach the bottom right square (n - 1, n - 1).

Example 1:



Input: grid = [[0,1],[2,3]]

Output: 3
Explanation: For a path to exist to the bottom right square grid[1][1] the water elevation must be at least 3. At time t = 3, the water level is 3.

Example 2:



Input: grid = [
  [0,1,2,10],
  [9,14,4,13],
  [12,3,8,15],
  [11,5,7,6]
]

Output: 8
Explanation: The water level must be at least 8 to reach the bottom right square. The path is [0, 1, 2, 4, 8, 7, 6].

Constraints:

grid.length == grid[i].length
1 <= grid.length <= 50
0 <= grid[i][j] < n^2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int row, int col ,vector<vector<int>>& grid , bool &isPossible ,int &t, int n ,vector<vector<bool>>& visited ){
        if( row < 0 || row>= n || col < 0 || col >= n ) return ;
        if(grid[row][col] > t) return ; 
        if(visited[row][col]) return ; 

        if(row == n-1 && col == n-1 ){
            isPossible = true ;
            return ;
        } 

        visited[row][col] = true ; 
        for(int delR = -1 ; delR <= 1 ; delR++){
            for(int delC=-1 ; delC <= 1 ; delC++){
                if(abs(delR) + abs(delC) == 1){
                    dfs(row + delR, col + delC , grid , isPossible , t ,  n  , visited) ;
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        // At t = 0 , only cells with water level <= 0 can be visited 
        // At t = 1 , only cells with water level <= 1 can be visited 
        // and so on 
        // So we need to find a path from first cell to end cell , and along the path the maximum cell is the time at which we can explore this path 
        // we need to find the minimum t 
        // So we need to minimise the maximum cell in a path 
        // This seems like a binary search problem 
        // Binary search on the answer and answer can range from 0 to max cell value 

        // Step 1 : Find the max value 
        int start = grid[0][0] ; //theoretically start at 0 but we start at cell 0  so atleast this will be the value 
        int end = INT_MIN ; 

        int n = grid.size();

        //TC:O(n*n) = TC:O(n^2)
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                end = max( grid[i][j] , end);
            }
        }

        // So now we have the values of start and end of t , we do binary search on this
        int ans = -1 ; 

        //TC:O(n^2log(max(cell)))
        // As dfs takes n^2 and binary search - log( max(cell))
        while( start <= end){
            int mid = start + (end - start)/2;
            bool isPossible = false ; 
            vector<vector<bool>> visited(n, vector<bool> (n , false));
            dfs(0 ,0 , grid , isPossible ,mid ,  n  , visited) ;    
            if(isPossible){
                ans = mid ;
                end = mid -1 ; // look for a smaller ans , as any time more will work too 
            }else{
                start = mid+1; // no time possible here so we increase t 
            }
        } 

        //TC :O(n^2log(max(cell))) and SC:O(n^2) throughout 
        // Given 0 <= grid[i][j] < n^2
        // so TC:O(n^2log(n^2)) = TC:O(n^2logn)
        return ans;
    }
};
