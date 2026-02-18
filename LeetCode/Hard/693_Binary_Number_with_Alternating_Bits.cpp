/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 

Constraints:

1 <= n <= 231 - 1
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 1. XOR n with itself shifted right by 1.
        // If bits alternate, this creates a number 'x' consisting of all 1s.
        // Example: n = 5 (101) -> n >> 1 = 2 (010) -> x = 111 (7)
        unsigned int x = n ^ (n >> 1);
        
        // 2. Check if x is all 1s.
        // If x is all 1s (e.g., 111), then x + 1 is a power of 2 (e.g., 1000).
        // The bitwise AND of x and x+1 should be 0.
        // We use 'long' to prevent overflow in case x is INT_MAX.
        return (long(x) & (long(x) + 1)) == 0;
    }
};