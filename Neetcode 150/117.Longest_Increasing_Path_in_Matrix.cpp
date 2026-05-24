/*
You are given a 2-D grid of integers matrix, where each integer is greater than or equal to 0.

Return the length of the longest strictly increasing path within matrix.

From each cell within the path, you can move either horizontally or vertically. You may not move diagonally.

Example 1:



Input: matrix = [[5,5,3],[2,3,6],[1,1,1]]

Output: 4
Explanation: The longest increasing path is [1, 2, 3, 6] or [1, 2, 3, 5].

Example 2:



Input: matrix = [[1,2,3],[2,1,4],[7,6,5]]

Output: 7
Explanation: The longest increasing path is [1, 2, 3, 4, 5, 6, 7].

Constraints:

1 <= matrix.length, matrix[i].length <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int row , int col , int m , int n ,vector<vector<int>>& matrix , vector<vector<int>> &dp){

        if( dp[row][col] != -1 ) return dp[row][col] ; 

        int curr = matrix[row][col] ; 

        int maxi = 0 ; 
        for(int delR = -1 ; delR <= 1 ; delR++){
            for(int delC = -1 ; delC <= 1 ; delC++){
                if( abs(delR) + abs(delC) == 1){
                    int r = row + delR ; 
                    int c = col + delC ;

                    if( r >=0 && r < m && c >= 0 && c<n && 
                            matrix[r][c] > matrix[row][col]
                    ){
                        maxi = max( maxi , func(r, c, m , n , matrix ,dp));
                    }
                }
            }
        }

        return dp[row][col] = 1 + maxi ; 

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        int maxi = INT_MIN ; 

        vector<vector<int>> dp(m , vector<int> ( n , -1)) ;
        //dp[r][c] == longest increasing path starting from cell (r,c) 
        // This is stored universally as only the starting point may change 
        // But the longest increasing from a cell reamins the same 
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                maxi = max( maxi , func(i , j , m , n , matrix  , dp)) ;
            }
        }

        //TC:O((4m*n))) as for every cell , longest path is calculated once and then reused 
        // SC:O(m*n) + SC:O(m*n) recursion stack 
        return maxi  ; 
    }
};
