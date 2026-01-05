/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
 

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // Effect on signs:

        // (+,+) → (-,-) → negatives +2

        // (-,-) → (+,+) → negatives −2

        // (+,-) → (-,+) → negatives unchanged

        // So if there are even number of negatives , we can make pairs and change to all positives at the end . SO max sum = abs value of all numbers 
        //But if there are odd number of negatives , even at the end atleast one negative number will remain (since odd= 2n + 1 ) , so we try to minimise the sum but keeping the number with least abs value as negative 

        long long sumAbs=0 ; 
        int negCount = 0;
        int minAbs = INT_MAX;

        for(auto &row : matrix ){
            for(int x:row){
                if(x < 0 )  negCount++;
                sumAbs+= abs(x);
                minAbs= min(minAbs , abs(x));
            }
        }

        //TC:O( n x n)
        //SC:O(1)
        if(negCount % 2 == 0 ){
            return sumAbs;
        }
        else{
            return sumAbs - 2LL * minAbs; 
        }

        // (basically sumAbs - 2 x minAbs) , -2 because it is counted once in sum so we remove it , and then we count its negative value to that ;
    }
};