/*
Pow(x, n) is a mathematical function to calculate the value of x raised to the power of n (i.e., x^n).

Given a floating-point value x and an integer value n, implement the myPow(x, n) function, which calculates x raised to the power n.

You may not use any built-in library functions.

Example 1:

Input: x = 2.00000, n = 5

Output: 32.00000
Example 2:

Input: x = 1.10000, n = 10

Output: 2.59374
Example 3:

Input: x = 2.00000, n = -3

Output: 0.12500
Constraints:

-100.0 < x < 100.0
-1000 <= n <= 1000
n is an integer.
If x = 0, then n will be positive.
*/
#include <iostream>
using namespace std;    


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1 ; 
        long long m = abs(n) ;  // handles the case when n = -31 , say 2^(-31) postive is 2^(31) which is out of range

        while(m){
            if(m % 2 == 1){
                // odd 
                // Separate one x and reduce n by 1 
                // Eg (4)^7 = 4 x (4)^6
                ans = ans * x ;
                m-- ;
            }else{
                //even power 
                // Eg : (4 ^2)^6/2 = (16)^3
                x = x*x;
                m = m /2 ;
            }
        }

        if( n < 0) return 1.0/ans;

        // TC:O(log2n) as we divide by 2 in most cases 
        // SC:O(1)
        return ans ; 
    }
};
