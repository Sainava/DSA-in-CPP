/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans ;

        int rows = matrix.size();
        int cols=matrix[0].size();

        int cnt = 0 ;
        int total = rows*cols;

        int startingRow = 0 ;
        int startingCol = 0 ;
        int endingRow = rows - 1 ;
        int endingCol = cols - 1 ;

        while ( cnt < total ){

            // print starting row 
            for(int  i = startingCol ; i <= endingCol && cnt < total ; i++){
                ans.push_back( matrix[startingRow][i]);
                cnt++;
            }
            startingRow++;

            //print Ending Col
            for(int i = startingRow ; i <= endingRow && cnt < total ; i++){
                ans.push_back( matrix[i][endingCol]);
                cnt++;
            }
            endingCol--;

            // print Ending Row in Reverse 
            for(int i = endingCol ; i >= startingCol && cnt < total; i--){
                ans.push_back( matrix[endingRow][i]);
                cnt++;
            }
            endingRow--;

            // print Starting Col in Reverse 
            for(int i = endingRow ; i >= startingRow && cnt < total ; i--){
                ans.push_back( matrix[i][startingCol]);
                cnt++;
            }
            startingCol++;
        }

        //TC:O(n x m)
        //SC:O(1)
        return ans ;

    }
};