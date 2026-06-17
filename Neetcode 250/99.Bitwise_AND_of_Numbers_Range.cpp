/*
You are given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: left = 1, right = 5

Output: 0
Example 2:

Input: left = 10, right = 12

Output: 8
Constraints:

0 <= left <= right <= ((2^31)-1)
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        // // THIS GIVES TLE 
        // int res = left ; 
        // for(int i = left + 1 ; i<= right ; i++){
        //     res = res & i ;
        // }
        // //TC:O(n)
        // return res ;


        // // SOlution 2 : O(logn)
        // // And if all 1s then 1 if even 1 zero then zero
        // int res = 0 ; // 000...00 ( 32 zeroes as 32 but number)

        // for(int i = 0 ; i < 32 ; i++){
        //     int bit = left >> i & 1 ; // Gives us the ith bit 

        //     if( bit == 0 ) continue ; // ith bit will be zero in res 

        //     // Now bit == 1 , we need to see if in the range(right - left , we will get the number where this bit becomes zero for the first time )

        //     // Say we are at 2nd but of 1010 , so we want the last two bits 10 
        //     // The following helps us get that 
        //     // Basically 1010 mod 0100 ( we get 0100 by taking 1 and shifting it i + 1 times )

        //     int remain = left % ( 1 << (i+1)) ;
        //     // Now we have 10 
        //     // The first time ith bit will be zero will be 0100 - 10 
        //     int diff = ( 1 << (i+1)) - remain ;
        //     if( (right - left) < diff){
        //         // This bit will not be zero -> So make it 1 
        //         res = res | (1 << i) ;
        //     }
        // }

        // return res ; 

        // Solution 3  Best solution -> O(log(right)) and easy to understand 
        //The bitwise AND of a range only keeps the common prefix bits of left and right.
        //we keeps removing bits from the right hand side until only common prefix is left 
        //That means we've stripped away all the differing suffix bits and only the common prefix remains.
        int i = 0 ; 
        while( left != right ){
            left = left >> 1 ; 
            right = right >> 1 ; 
            i++;
        }
        //TC:(O(log(right))) Only the first bit may be same . We keep dividing right until only 1 reamins 
        return left << i ;

    }
};