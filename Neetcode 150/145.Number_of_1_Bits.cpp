/*
You are given an unsigned integer n. Return the number of 1 bits in its binary representation.

You may assume n is a non-negative integer which fits within 32-bits.

Example 1:

Input: n = 00000000000000000000000000010111

Output: 4
Example 2:

Input: n = 01111111111111111111111111111101

Output: 30
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0 ; 

        // // Method 1 :
        // while(n) {
        //     if( (n & 1)== 1) cnt++;
        //     n = n>>1 ;
        // }

        // //TC:(32)  = TC:O(1) and SC:O(1)
        // return cnt ;

        while(n){
            n = n & ( n - 1) ; // This removes the lowest set bit 
            cnt++ ; 
        }

        //TC:O(no of set bits ) = TC:O(1) and SC:O(1)
        return cnt ; 
    }
};
