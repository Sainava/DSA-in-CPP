/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

#include<iostream>
using namespace std ;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Given in question 
        
        if ( dividend == divisor ) return 1;

        bool sign = true ; // positive ans 

        if(dividend >= 0 && divisor < 0 ) sign = false; // negative ans
        if(dividend < 0 && divisor > 0 ) sign = false; // negative ans

        // We will divide assuming both are postive
        long long  n = llabs((long long)dividend) ; // For if dividend or divisor is -2^31
        long long  d = llabs((long long) divisor) ;

        long long ans = 0;

        while( n >= d){
            int count = 0 ; // we can remove 2^0 from n

            while ( n >= (d * (1LL <<(count+1)))){ // can we do n - d*2^count
                count++;
            }

            ans += (1LL << count); // Add 2^count to the ans ;
            n = n - ( d * ( 1LL<<count));
        }

        //TC:O(nlogn * nlogn) = TC:O((nlogn)^2)
        //SC:O(1)
        return sign ? ans : (-1 * ans);
    }
};