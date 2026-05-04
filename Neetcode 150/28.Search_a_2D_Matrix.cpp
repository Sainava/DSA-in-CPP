/*
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

Example 1:



Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10

Output: true
Example 2:



Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15

Output: false
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10000 <= matrix[i][j], target <= 10000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;


        int start = 0 ;
        int end = (m*n) - 1;

        int mid = start + (end - start) / 2 ;

        while( start <=end ){
            // Each row has n elements 
            int row = mid / n ;
            int col = mid % n ;

            if( matrix[row][col] == target){
                return true ;
            }
            else if (matrix[row][col] < target){
                start = mid + 1;
            }
            else{
                end = mid -1 ;
            }

            mid = start + (end - start) / 2 ;
        }

        //TC:O(log(m*n)) and SC:O(1)
        return false ;
    }
};
