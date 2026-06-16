/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * (10^9).

Example 1:

Input: obstacleGrid = [[0,0,0],[0,0,0],[0,1,0]]

Output: 3
Explanation: There are three ways to reach the bottom-right corner:

Right -> Right -> Down -> Down
Right -> Down -> Right -> Down
Down -> Right -> Right -> Down
Example 2:

Input: obstacleGrid = [[0,0,0],[0,0,1],[0,1,0]]

Output: 0
Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int row , int col , int m ,int n , vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp){
        if( row == m-1 && col == n-1) return 1 ; 

        if( dp[row][col] != -1) return dp[row][col] ;

        // Down 
        int r = row + 1 ; 
        int c = col;
        int down = 0 ; 
        if( r>= 0 && r< m && obstacleGrid[r][c] == 0){
            down = solve(r , c , m , n ,obstacleGrid ,dp) ;
        }

        // Right 
        r = row ;
        c = col + 1 ;
        int right = 0 ; 
        if( c >= 0 && c < n && obstacleGrid[r][c] == 0){
            right = solve(r , c , m , n ,obstacleGrid , dp) ;
        }

        return dp[row][col] = down + right ; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1 ) return 0 ; 

        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        int row = 0 ; 
        int col = 0 ;

        vector<vector<int>> dp( m  , vector<int> ( n , -1));

        //TC:O(m*n) and SC:(m*n)
        return solve(row , col , m , n , obstacleGrid , dp) ;
    }
};



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1 ) return 0 ; 

        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        vector<vector<int>> dp( m , vector<int> ( n , 0));

        dp[m-1][n-1] = 1 ; 

        for(int row = m-1 ; row >= 0 ; row--){
            for ( int col = n - 1 ; col >= 0 ; col--){
                if( row == m-1 && col == n-1) continue ; 

                // Down 
                int r = row + 1 ; 
                int c = col;
                int down = 0 ; 
                if( r>= 0 && r< m && obstacleGrid[r][c] == 0){
                    down = dp[r][c] ;
                }

                // Right 
                r = row ;
                c = col + 1 ;
                int right = 0 ; 
                if( c >= 0 && c < n && obstacleGrid[r][c] == 0){
                    right = dp[r][c];
                }

                dp[row][col] = down + right ;     
            }
        }
        //TC:O(m*n) and SC:(m*n)
        return dp[0][0] ; 
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 ||
           obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<int> dp(n, 0); // current row

        dp[n-1] = 1;

        for(int row = m-1; row >= 0; row--){

            for(int col = n-1; col >= 0; col--){

                if(obstacleGrid[row][col] == 1){
                    dp[col] = 0;
                }
                else if(col < n-1){
                    dp[col] += dp[col+1];
                }
            }
        }

        // Time Complexity: O(m*n)
        // Every cell is processed once.
        //
        // Space Complexity: O(n)
        // Only one row of DP is stored.
        return dp[0];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 ||
           obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<int> curr(n, 0); 
        vector<int> next( n , 0 );

        curr[n-1] = 1 ;


        for(int row = m-1; row >= 0; row--){

            for(int col = n-1; col >= 0; col--){
                    if( row == m-1 && col == n-1) continue ; 
                    
                    // Down 
                    int r = row + 1 ; 
                    int c = col;
                    int down = 0 ; 
                    if( r>= 0 && r< m && obstacleGrid[r][c] == 0){
                        down = next[c] ;
                    }

                    // Right 
                    r = row ;
                    c = col + 1 ;
                    int right = 0 ; 
                    if( c >= 0 && c < n && obstacleGrid[r][c] == 0){
                        right = curr[c];
                    }

                    curr[col] = down + right ;     
                }

                next = curr; 
            }

            //TC:O(m*n) and SC:(n)
            return next[0];
           
        }
        
};
