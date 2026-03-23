/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size() ; 

        // //Brute force
        // vector<vector<int>> ans(n, vector<int> (n,0));

        // for(int i = 0 ; i < n ; i++){

        //     for(int j = 0 ; j < n ; j++){

        //         ans[j][(n-1) - i ] = matrix[i][j];
        //     }
        // }

        // // Now place back in matrix
        // for(int i = 0 ; i < n ; i++){

        //     for(int j = 0 ; j < n ; j++){

        //         matrix[i][j] = ans[i][j];
        //     }
        // }

        // //TC:O( 2 * (n^2)) and SC:(n^2)
        // return ;


        // Optimised 
        // 2 steps : Transpose and reverse each row 

        int n = matrix.size() ;

        // Step 1 : Transpose 

        // For transpose , only traverse in the upper triangle of matrix 
        // TC : O( n/2 x n/2 )
        for(int i = 0 ; i < n ; i++ ){

            for(int j = i + 1  ; j < n ; j++ ){
                
                swap( matrix[i][j] , matrix[j][i] );
            }
        }

        // Now reverse each row 

        //TC:O( n x n/2 )
        for(int i = 0 ; i < n ; i++ ){

            reverse( matrix[i].begin() , matrix[i].end());
        }

        //TC : ( n^2 /4 + n^2/2) and SC:O(1)
        return ;
    }
};