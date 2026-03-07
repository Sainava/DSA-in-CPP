/*
Input: N = 12  
Output: 8  
Explanation:  The rightmost set bit in the binary representation of 12 (1100) is at index 2 (from the right). After removing this bit, the updated number is 8 (binary: 1000).

Input: N = 25  
Output: 24  
Explanation:  The binary representation of 25 is 11001. The rightmost set bit is at index 0 (from the right). After removing this bit, the updated number is 24, which in binary is 11000.
*/
#include<iostream>
using namespace std ;

int removeLastSetBit(int n) {
    // n & (n-1) removes the last set bit from n 

    return n & (n-1);

    //TC:O(1) and SC:O(1)
}