/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are fully processed and no carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            // Add digit from string a if available
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            
            // Add digit from string b if available
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            
            // If sum is 1 or 3 -> bit is 1. If sum is 0 or 2 -> bit is 0.
            result += to_string(sum % 2);
            
            // If sum is 2 or 3 -> carry is 1. Otherwise 0.
            carry = sum / 2;
        }

        // The result is currently LSB -> MSB (backwards), so reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};