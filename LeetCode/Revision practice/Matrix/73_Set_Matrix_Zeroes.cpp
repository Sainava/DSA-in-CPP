/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include<iostream>
#include<vector>
using namespace std;

//SOlution 1: Brute Force Solution
class Solution {
public:
    void makerow(vector<vector<int>>& matrix , int row){

        for(int col= 0 ; col < matrix[0].size() ; col++){
            if(matrix[row][col]!=0){
                matrix[row][col] = -1;
            }
        }
    }

    void makecol(vector<vector<int>>& matrix , int col){

        for(int row= 0 ; row < matrix.size() ; row++){
            if(matrix[row][col]!=0){
                matrix[row][col] = -1;
            }
        }
    }


    void setZeroes(vector<vector<int>>& matrix) {
        
        // Brute force 

        //TC : O(n x m) outer two loops without considering function calls
        for(int i = 0 ; i < matrix.size() ; i++){

            for(int j = 0 ; j < matrix[0].size() ; j++){

                if(matrix[i][j] == 0){
                    makerow(matrix , i); //TC:O(m)
                    makecol(matrix , j); //TCO(n)
                }
            }
        }

        //TC:O(nxm)
        for(int i = 0 ; i < matrix.size() ; i++){

            for(int j = 0 ; j < matrix[0].size() ; j++){

                if(matrix[i][j] == -1){
                    matrix[i][j] = 0 ;
                }
            }
        }

        //TC:O( (nxm)*(n+m) + (nxm)) = approx TC:O(n^3)
        //SC:O(1)
        return ;
        //The above has extremely high TC and fails when matix has -1 elements already present 
    }
};

// Solution 2: Better Solution using Extra Space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Better solution using extra space 

        vector<int> cols(matrix[0].size() , 0);
        vector<int> rows(matrix.size() , 0);

        //TC:O(nxm)
        for(int i = 0 ; i < matrix.size() ; i++){

            for(int j = 0 ; j < matrix[0].size() ; j++){

                if(matrix[i][j] == 0){
                    cols[j] = -1;
                    rows[i] = -1;
                }
            }
        }

        //TC:O(nxm)
        for(int i = 0 ; i < matrix.size() ; i++){

            for(int j = 0 ; j < matrix[0].size() ; j++){

                if(rows[i] == -1 || cols[j]==-1){
                    matrix[i][j] = 0 ;
                }
            }
        }

        //TC:O(nxm) and SC:O(n+m)
        return ;
    }
};

//Solution 3: Optimised Space using Constant Space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Optimised space using constant space

        // We use the first row and first col as the required spaces instead of new vectors ( see the previous solution to see )

        // vector<int> cols(matrix[0].size() , 0); // matrix[0][....] will do this work
        // vector<int> rows(matrix.size() , 0); // matrix[....][0]  will do this work 

        int col0 = 1 ; // Since element [0][0] will be in both rows and cols check so we deal with it separately

        //TC:O(nxm)
        for(int i = 0 ; i < matrix.size() ; i++){

            for(int j = 0 ; j < matrix[0].size() ; j++){

                if(matrix[i][j] == 0){
                    // Need to mark the ith row 
                    matrix[i][0] = 0 ;

                    if(j!=0){
                        // mark the jth row 
                        matrix[0][j] = 0;
                    }else{
                        col0 = 0;
                    }
                }
            }
        }

        //TC:O(nxm)
        for(int i = 1 ; i < matrix.size() ; i++){

            for(int j = 1 ; j < matrix[0].size() ; j++){

                if(matrix[i][j] != 0){
                    
                    if(matrix[i][0] == 0 || matrix[0][j] == 0 ) {
                        matrix[i][j] = 0;
                    }

                
                }
            }
        }

        // TC:O(m)
        if(matrix[0][0] == 0){
            // Everyone in first row will be zero 
            for(int j = 1 ; j < matrix[0].size() ; j++) matrix[0][j] = 0;
        }

        //TC:O(n)
        if(col0==0){
            // Everyone in first col will be zero 
            for(int i = 0 ; i < matrix.size() ; i++){
                matrix[i][0] = 0;
            }
        }

        //TC:O(2(nxm) + (n+m)) and SC:(1)
        return ;


    }
};