/*
You are given an integer array digits, where each digits[i] is the ith digit of a large integer. It is ordered from most significant to least significant digit, and it will not contain any leading zero.

Return the digits of the given integer after incrementing it by one.

Example 1:

Input: digits = [1,2,3,4]

Output: [1,2,3,5]
Explanation 1234 + 1 = 1235.

Example 2:

Input: digits = [9,9,9]

Output: [1,0,0,0]
Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int carry = 1 ;
        for(int i = n-1 ; i >=0 ; i--){
            if(!carry) break ;
            int num = digits[i] + carry;
            digits[i] = num % 10 ; 
            carry = num /10 ;
        }

        if( carry ) digits.insert(digits.begin() , 1); // carry = 1 so we need to insert carry
        
        //TC:O(n) and SC:(1)
        return digits ;
    }
};
