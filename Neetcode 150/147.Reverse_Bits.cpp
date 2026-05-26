/*
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.

Example 1:

Input: n = 00000000000000000000000000010101

Output:    2818572288 (10101000000000000000000000000000)
Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21, gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Similar to sting 
        // take last character , add the beginning of the ans 

        uint32_t ans = 0 ; 

        for(int i = 0 ; i < 32 ; i++){
            // Take last digit from n 
            uint32_t digit = n & 1 ;
            n = n >> 1 ;

            // Add this character to ans 
            ans = ans << 1; 
            ans = ans | digit ; 
            
        }

        //TC:O(1) and SC:O(1)
        return ans ;
    }
};
