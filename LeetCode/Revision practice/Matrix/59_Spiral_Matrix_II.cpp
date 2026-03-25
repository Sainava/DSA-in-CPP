/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1 ;
        int total = n * n ;

        vector<vector<int>>  ans( n , vector<int> (n , 0 )) ;

        int startingRow = 0 ;
        int startingCol = 0 ;
        int endingRow = n - 1 ;
        int endingCol = n - 1 ;

        while( cnt <= total){
            
            // print starting row 
            for(int i = startingCol ; i <= endingCol && cnt<=total; i++){
                ans[startingRow][i] = cnt ;
                cnt++;
            }
            startingRow++;

            // print ending Col
            for(int i = startingRow ; i <= endingRow && cnt<=total; i++){
                ans[i][endingCol] = cnt;
                cnt++;
            }
            endingCol--;

            // print ending Row ;
            for(int i = endingCol ; i >= startingCol && cnt<=total; i--){
                ans[endingRow][i] = cnt;
                cnt++;
            }
            endingRow--;

            //print starting Col
            for(int i = endingRow ; i>=startingRow && cnt<=total; i--){
                ans[i][startingCol] = cnt;
                cnt++;
            }
            startingCol++;

        }

        //TC:O(mxn)
        //SC:O(1) extra space 
        return ans;
    }
};