/*
You are given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Example 1:

Input: x = 9

Output: 3
Example 2:

Input: x = 13

Output: 3
Constraints:

0 <= x <= ((2^31)-1)
*/
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if( x == 0) return 0 ;

        int start = 1 ; 
        int end = x/2 ; 

        int ans ; 
        while(start <= end){
            int mid = start + ( end - start) / 2 ; 

            if(mid <= INT_MAX/mid && mid*mid <= x){
                ans = mid ; 
                start = mid + 1 ;
            }else{
                end = mid - 1 ; 
            }
        }

        //TC:O(logn) and SC:O(1)
        return ans ; 
    }
};