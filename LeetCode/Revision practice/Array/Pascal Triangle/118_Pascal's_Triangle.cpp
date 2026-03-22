/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/
#include<iostream>
#include<vector>
using namespace std ;


class Solution {
public:

    long long nCr(int n , int r){
        // This function essentailly calculates nCr efficiently

        long long  res= 1;
        
        for(int i = 0 ; i < r ; i++){
            res = res * (n-i);
            res = res / (i + 1);
        }

        //TC:O(r) and SC:O(1)
        return res;

    }

    vector<int> getRow (int row){

        int col = row ; // Each each row has the same number of columns ;

        vector<int> res;
        int ans = 1 ;
        res.push_back(ans); // Since first element is always 1 in each row 

        // If m columns in this row , we consider number from 0 to m-1 , so secodn column has index 1 
        for(int i = 1 ; i < col ; i++ ){
            ans = ans * ( row - i);
            ans = ans / i ;
            res.push_back( ans );
        }

        //TC:O(row) and SC:O(1)
        return res ; 

    }

    vector<vector<int>> generate(int numRows) {

        // Problem 1  - Print the element in row r and col r.
        //In pascal's triangle  , any number I in row "r" amd column "c" is given by (r-1)C(c-1) where C is combination .
        // In the above r and c start from 1 so first row has r = 1 and not r = 0 

        // First question , Given r and c find the element 

        // element = n! / (r!)*(n-r)! 
        // but do not do this directly as factorial can take big TC so we do the simplified ( the ones remianing after cancelling the terms we can cancel)

        // Required ans = nCr(row - 1 , col - 1)

        // Problem 2 - Print the entire row r

        // return getRow(r)

        // Problem 3 - Print the entire pascal traingle till numRooms , i.e , the current question 

        vector<vector<int>> ans ;
        for(int i = 1 ; i <= numRows ; i++){
            ans.push_back( getRow(i) );
        }

        //TC:O(n^2) as getRow has complexity n and it is called n times , n being the number of rows 
        //SC:O(1) extra space excluding the one needed to return ans 
        return ans ;

    }
};