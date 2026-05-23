/*
There is an m x n grid where you are allowed to move either down or to the right at any point in time.

Given the two integers m and n, return the number of possible unique paths that can be taken from the top-left corner of the grid (grid[0][0]) to the bottom-right corner (grid[m - 1][n - 1]).

You may assume the output will fit in a 32-bit integer.

Example 1:



Input: m = 3, n = 6

Output: 21
Example 2:

Input: m = 3, n = 3

Output: 6
Constraints:

1 <= m, n <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void func(int row , int col ,int m , int n , int &cnt ){
        if(row < 0 || row >= m || col < 0 || col >= n ) return ;

        if( row == m-1 && col == n-1){
            cnt++;
        }

        // Down 
        func(row + 1 , col , m , n ,cnt);

        // Right
        func(row , col + 1 , m , n ,cnt);
    }

    int funcTopDown(int row , int col ,int m , int n ,vector<vector<int>> &dp  ){
        if(row < 0 || row >= m || col < 0 || col >= n ) return  0;
        if( row == 0 && col == 0 ) return dp[0][0] = 1;

        if(dp[row][col]!= -1 ) return dp[row][col] ;

        dp[row][col] = funcTopDown(row -1 , col , m ,n ,dp) + funcTopDown(row , col -1 , m ,n ,dp) ;

        return dp[row][col];
        
    }

    int uniquePaths(int m, int n) {
        
        //Recursion 
        // int row = 0 ; 
        // int col = 0 ;
        // int cnt = 0 ; 
        // func(row, col , m , n ,cnt);

        // //TC:O(2^m*n) and SC:O(m*n)
        // return cnt++ ;

        // // Top - Down DP 
        // // dp[i][j] is no of ways in which we can reach i th row and  j th col  from 0,0
        // vector<vector<int>> dp(m , vector<int> (n , -1)) ; 

        // // dp[i][j] = no of ways to reach dp[i-1][j](top) and dp[i][j-1] left
        // int row = m-1 ; 
        // int col = n - 1; 
        // //TC:O(m*n) and SC:O(m*n)
        // return funcTopDown(row, col , m , n , dp) ;


        // // Bottom up 
        // vector<vector<int>> dp(m , vector<int> (n ,0)) ; 
        // dp[0][0] = 1 ; 

        // for(int row = 0 ; row < m ; row++){
        //     for(int col = 0 ; col < n ; col++){
        //         if( row == 0 && col == 0 ) continue ; // We already have dp[0][0]

        //         int num1 = 0 ;
        //         int num2 = 0 ;

        //         if( (row - 1) >= 0 && (row - 1) < m ){
        //             num1 = dp[row -1][col] ;
        //         }

        //         if ((col - 1) >= 0 && (col - 1) < n){
        //             num2 = dp[row][col -1] ;
        //         }

               
                
        //     }
        // }

        // //TC:O(m*n) and SC:O(m*n)
        // return dp[m-1][n-1];

        // Space Optimised 
        vector<int> prevRow(n, 0 );
        vector<int> currRow(n, 0 );

        currRow[0] = 1 ;

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if( row == 0 && col == 0 ) continue ; // We already have dp[0][0]

                int num1 = 0 ;
                int num2 = 0 ;

                if( (row - 1) >= 0 && (row - 1) < m ){
                    num1 = prevRow[col] ;
                }

                if ((col - 1) >= 0 && (col - 1) < n){
                    num2 = currRow[col -1] ;
                }
                currRow[col] = num1 + num2 ;
            }
            prevRow = currRow ; 
            
        }

        //TC:O(m*n) and SC:O(2n)
        return currRow[n-1];

    }
};
