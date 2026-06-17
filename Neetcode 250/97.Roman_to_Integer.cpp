/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
You are given a roman numeral as a string s, convert it to an integer.

Example 1:

Input: s = "III"

Output: 3
Example 2:

Input: s = "XLIX"

Output: 49
Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Read from LEFT to Right 
        // Large comes before smaller 
        //MXI -> 1000 + 10 + 1 = 1011

        // In the case where smaller comes before larger . It is negative 
        //Eg : IX -> -1 + 10 = 9 

        // Also there cannot be two negatives meaning we cannot have smaller smaller largest 
        // It will be smaller larger . We do not need to care about this so can ignore 
        // As question says input is always valid

        unordered_map<char , int > mp ;

        // 7 values so SC:O(1)
        mp['I'] = 1 ; 
        mp['V'] = 5 ;
        mp['X'] = 10 ; 
        mp['L'] = 50 ; 
        mp['C'] = 100 ;
        mp['D'] = 500 ;
        mp['M'] = 1000 ;

        int res = 0 ; 

        int n = s.size() ;

        for(int i= 0 ; i < n ; i++ ){
            if( i + 1 < n && mp[s[i]] < mp[s[i+1]]){
                res = res - mp[s[i]];
            }
            else {
                res = res + mp[s[i]] ; 
            }
        }

        //TC:O(n) and SC:O(1)
        return res ;
    }
};