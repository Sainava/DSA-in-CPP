/*
You are given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [
    [1,2,0],
    [5,4,2],
    [1,1,3]
]

Output: 8
Explanation: The path with minimum sum is 1 -> 2 -> 0 -> 2 -> 3.

Example 2:

Input: grid = [
    [2,2],
    [1,0]
]

Output: 3
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve( int row , int col ,int m , int n , vector<vector<int>>& grid , vector<vector<int>> &dp){
        // Base case 
        if(row == m - 1 && col == n-1 ) return grid[row][col] ; 

        if( dp[row][col] != -1 ) return dp[row][col] ;

        int path = INT_MAX ;

        // Down 
        int r = row + 1 ; 

        if( r >= 0 && r <m) {
            path = min( path , grid[row][col] + solve(r , col , m , n , grid ,dp) );
        }

        // right 
        int c = col + 1 ;
        if(c>= 0 && c < n ){
            path = min( path , grid[row][col] + solve(row , c , m , n , grid , dp));
        }

        return dp[row][col] = path ; 

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;
        int row = 0 ; 
        int col = 0 ; 

        vector<vector<int>> dp( m , vector<int> (n , -1));

        //TC:O(m * n) and SC:O(m*n )
        return solve( row , col ,m , n ,grid , dp) ;

         
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ; 
        int n = grid[0].size() ;

        vector<vector<int>> dp( m + 1, vector<int> (n + 1, 0));

        dp[m-1][n-1] = grid[m-1][n-1] ;


        for(int row = m-1 ; row>= 0 ; row--){
            for(int col = n-1 ; col >= 0 ; col--){
                if( row == m- 1 && col == n-1 ) continue ; 
                int path = INT_MAX ;
                // Down 
                int r = row + 1 ; 

                if( r >= 0 && r <m) {
                    path = min( path , grid[row][col] + dp[r][col]);
                }

                // right 
                int c = col + 1 ;
                if(c>= 0 && c < n ){
                    path = min( path , grid[row][col] + dp[row][c] );
                }

               dp[row][col] = path ; 
            }
        }   

        //TC:O(m*n) and SC:O(m*n)
        return dp[0][0] ; 
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
               int m = grid.size() ; 
        int n = grid[0].size() ;

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        curr[n-1] = grid[m-1][n-1] ;

        for(int row = m-1 ; row>= 0 ; row--){
            for(int col = n-1 ; col >= 0 ; col--){
                if( row == m- 1 && col == n-1 ) continue ; 
                int path = INT_MAX ;
                // Down 
                int r = row + 1 ; 

                if( r >= 0 && r <m) {
                    path = min( path ,grid[row][col] + next[col]);
                }

                // right 
                int c = col + 1 ;
                if(c>= 0 && c < n ){
                    path = min( path , grid[row][col] + curr[c] );
                }

               curr[col] = path ; 
            }
            next = curr ; 
        }   

        //TC:O(m*n) and SC:O(n)
        return next[0] ; 
    }
};