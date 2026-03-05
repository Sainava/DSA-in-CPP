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

    int maximalSquare(vector<vector<char>>& matrix) {
        
        // // Simple recursion 
        // int maxi = 0 ;
        // solve(matrix , 0 , 0 , maxi ); // row = 0 and col = 0 
        
        // // maxi contains the largest length but we need the area 
        // // TC:O(3*(n*m))
        // return maxi*maxi ;

        // DP solution 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1) );

        int maxi = 0;
        //Step 1 - Pass dp 
        solveMem(matrix , 0 , 0 , maxi ,dp );

        return maxi*maxi ;
    }
};