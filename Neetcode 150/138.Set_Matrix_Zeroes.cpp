/*
Given an m x n matrix of integers matrix, if an element is 0, set its entire row and column to 0's.

You must update the matrix in-place.

Follow up: Could you solve it using O(1) space?

Example 1:



Input: matrix = [
  [0,1],
  [1,0]
]

Output: [
  [0,0],
  [0,0]
]
Example 2:



Input: matrix = [
  [1,2,3],
  [4,0,5],
  [6,7,8]
]

Output: [
  [1,0,3],
  [0,0,0],
  [6,0,8]
]
Constraints:

1 <= matrix.length, matrix[0].length <= 100
-2^31 <= matrix[i][j] <= (2^31) - 1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // The idea is to treat the first col and first row  as additional datastructure 
        // So if any row and column are zero 

        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        int firstColCheck = 1 ; 

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(matrix[i][j] == 0){    
                    if ( j == 0){
                        firstColCheck = 0 ; 
                    }else{
                        matrix[0][j] = 0 ; 
                        matrix[i][0] = 0 ;
                    }
                }
            }
        }

        // Now mark zeroes where there are zero 
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0 ; 
                }
            }
        }

        if( matrix[0][0] == 0 ) {
            // Then entire first row should be zero 
            for(int i = 1 ; i < n ; i++){
                matrix[0][i] = 0 ; 
            }
        }

        if( firstColCheck == 0 ){
            // Then the first col should be zero 
            for(int i = 0 ; i < m ; i++){
                matrix[i][0] = 0 ; 
            }
        }

        // TC :O( 2 (m*n)) and SC:O(1)
    }
};
