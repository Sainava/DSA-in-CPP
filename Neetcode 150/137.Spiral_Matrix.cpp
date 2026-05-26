/*
Given an m x n matrix of integers matrix, return a list of all elements within the matrix in spiral order.

Example 1:



Input: matrix = [[1,2],[3,4]]

Output: [1,2,4,3]
Example 2:



Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output: [1,2,3,6,9,8,7,4,5]
Example 3:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Constraints:

1 <= matrix.length, matrix[i].length <= 10
-100 <= matrix[i][j] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() ; 
        int n = matrix[0].size() ;

        int cnt = 0 ;

        int startRow = 0 ; 
        int endRow = m-1 ;
        
        int startCol = 0 ; 
        int endCol = n-1 ; 

        vector<int> ans ; 

        // We do cnt < m*n at every loop because we need to stop as soon as every element has beem traversed once and once only 
        while(cnt < m*n){

            for(int i = startCol ; i <= endCol && cnt < m*n; i++){
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;

            for(int i = startRow ; i <= endRow && cnt < m*n ; i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;

            for(int i = endCol ; i>=startCol && cnt < m*n; i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;

            for(int i = endRow ; i>= startRow  && cnt < m*n; i--){
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;

        }

        //TC:O(m*n) and SC:O(m*n) to return answer , no auxillary space
        return ans ;
    }
};
