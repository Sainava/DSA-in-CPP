/*
You are given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:

Input: matrix = [
    [2,1],
    [-1,3]
]

Output: [
    [2,-1],
    [1,3]
]
Example 2:

Input: [
    [1,0,5],
    [2,4,3]
]

Output: [
    [1,2],
    [0,4],
    [5,3]
]
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 100,000
-1,000,000,000 <= matrix[i][j] <= 1,000,000,000

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 

        // The following only works for square matrix ( m = n )
        // for(int i = 0 ; i < m ; i++){
        //     for (int j = i ; j < n ; j++){
        //         swap(matrix[i][j] , matrix[j][i]) ; 
        //     }
        // }

        vector<vector<int>> res(n , vector<int> (m)) ; 

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                res[i][j] = matrix[j][i] ; 
            }
        }

        //TC:O(m x n ) and SC:O(n x m )for and SC:O(1) auxillary 
        return res ; 
    }
};