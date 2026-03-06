/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int solve(vector<vector<char>>& matrix , int i , int j , int &maxi){
        // Base condition 
        if( i >= matrix.size() || j>= matrix[0].size()){
            return 0 ;
        }

        int right = solve(matrix , i , j + 1 , maxi );
        int diagonal = solve(matrix , i + 1 , j + 1 , maxi);
        int down = solve( matrix , i + 1 , j , maxi );

        int curr = matrix[i][j];

        if(curr == '1'){
            int ans = 1 + min( right , min(diagonal , down));
            maxi= max(maxi , ans);
            return ans ;
        }else{
            return  0 ;
        }
    }

    int solveMem(vector<vector<char>>& matrix , int i , int j , int &maxi , vector<vector<int>> &dp){
        // Base condition 
        if( i >= matrix.size() || j>= matrix[0].size()){
            return 0 ;
        }

        // Step 2 - check if we already have value 
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solveMem(matrix , i , j + 1 , maxi ,dp );
        int diagonal = solveMem(matrix , i + 1 , j + 1 , maxi ,dp);
        int down = solveMem( matrix , i + 1 , j , maxi ,dp);

        int curr = matrix[i][j];

        if(curr == '1'){
            // Step 3 - Store value in dp 
            dp[i][j] = 1 + min( right , min(diagonal , down));
            maxi= max(maxi , dp[i][j]);
            return dp[i][j] ;
        }else{
            return dp[i][j]=0 ;
        }
    }

    int solveTab(vector<vector<char>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;

        vector<vector<int>> dp(row + 1 , vector<int> (col + 1, 0));

        for(int i = row - 1 ; i >= 0 ; i--){
            for(int j = col -1 ; j >= 0 ; j--){

                int right = dp[ i ] [j + 1 ];
                int diagonal = dp[i + 1 ][ j + 1 ];
                int down = dp[ i + 1 ][ j ];

                int curr = matrix[i][j];

                if(curr == '1'){
                    dp[i][j] = 1 + min( right , min(diagonal , down));
                    maxi= max(maxi , dp[i][j]);

                }else{
                    dp[i][j]=0 ;
                }
            }
        }

        return maxi*maxi;
    }

    // O(1) space solution
    int solveFurtherSpaceOptimsied (vector<vector<char>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        
        // Process the matrix from top-left to bottom-right (in-place)
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        // First row or first column - maximum square size is 1
                        maxi = max(maxi, 1);
                    } else {
                        // Get values from top, left, and diagonal (already computed)
                        int top = matrix[i-1][j] - '0';
                        int left = matrix[i][j-1] - '0';
                        int diagonal = matrix[i-1][j-1] - '0';
                        
                        // Calculate current square size and store back in matrix
                        int minVal = min(top, min(left, diagonal));
                        matrix[i][j] = (char)('0' + minVal + 1);
                        maxi = max(maxi, minVal + 1);
                    }
                }
            }
        }
        
        return maxi * maxi;
    }

    int solveOptimised(vector<vector<char>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;

        vector<int> curr(col + 1 , 0) ; // current row
        vector<int> next (col + 1 , 0); // next row


        for(int i = row - 1 ; i >= 0 ; i--){
            for(int j = col -1 ; j >= 0 ; j--){

                int right = curr[j + 1 ];
                int diagonal = next[ j + 1 ];
                int down = next[ j ];


                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min( right , min(diagonal , down));
                    maxi= max(maxi , curr[j]);

                }else{
                    curr[j]=0 ;
                }

               
            }
            next = curr;
        }

        return maxi*maxi;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        
        // // Simple recursion 
        // int maxi = 0 ;
        // solve(matrix , 0 , 0 , maxi ); // row = 0 and col = 0 
        
        // // maxi contains the largest length but we need the area 
        // // TC:O(3*(n*m))
        // return maxi*maxi ;

        // // DP solution 
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int> (m,-1) );

        // int maxi = 0;
        // //Step 1 - Pass dp 
        // solveMem(matrix , 0 , 0 , maxi ,dp );

        // return maxi*maxi ;

        // Tabulation method 
        //TC:(nxm) and SC:O(nxm)
        //return solveTab(matrix);

        // Space Optimised 
        //TC:(nxm) and SC:O(m)
        return solveOptimised(matrix);


    }

    // To do --> Bring solutiom to O(1) space
};