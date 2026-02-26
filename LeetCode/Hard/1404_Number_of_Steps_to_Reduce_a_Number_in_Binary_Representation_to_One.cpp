/*
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0
 

Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // We iterate from the last character up to the second character (index 1).
        // The first character (index 0) is handled at the very end.
        for (int i = s.length() - 1; i > 0; --i) {
            int digit = s[i] - '0';
            
            if (digit + carry == 1) {
                // It's odd: Add 1 (1 step) + Divide by 2 (1 step) = 2 steps
                steps += 2;
                carry = 1;
            } else {
                // It's even (0+0 or 1+1): Just divide by 2 (1 step)
                // Note: if it was 1+1, carry remains 1. If 0+0, carry remains 0.
                steps += 1;
            }
        }
        
        // Final check for the leftmost bit (s[0])
        // If there's a carry, the "1" becomes "10", requiring one more division.
        return steps + carry;
    }
};