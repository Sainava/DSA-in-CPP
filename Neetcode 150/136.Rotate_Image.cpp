/*
Given a square n x n matrix of integers matrix, rotate it by 90 degrees clockwise.

You must rotate the matrix in-place. Do not allocate another 2D matrix and do the rotation.

Example 1:



Input: matrix = [
  [1,2],
  [3,4]
]

Output: [
  [3,1],
  [4,2]
]
Example 2:



Input: matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

Output: [
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Take transpose and then reverse each row 
        int n = matrix.size() ;
        
        // Transpose
        for(int i = 0 ; i < n ; i++){
            for(int j = i  ; j < n ; j++){
                swap(matrix[i][j] ,matrix[j][i]);
            }
        }

        //Now reverse each row
        for(int i = 0 ; i < n ; i++){
            int start =0;
            int end = n-1;

            while(start < end){
                swap(matrix[i][start] , matrix[i][end]);
                start++;
                end--;
            }
        }

        // TC:O(n*n) for transpose and TC:O(n*n) for reversal  and SC:O(1)
    }
};
