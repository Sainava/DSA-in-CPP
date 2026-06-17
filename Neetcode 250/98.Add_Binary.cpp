/*
You are given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "101", b = "10"

Output: "111"
Example 2:

Input: a = "10010", b = "111"

Output: "11001"
Constraints:

1 <= a.length, b.length <= 10,000
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "" ;
        int carry = 0 ;

        reverse(a.begin() , a.end());
        reverse(b.begin() , b.end());

        int m = a.size() ;
        int n = b.size() ;

        for(int i = 0 ; i < max(m,n) ; i++){
            
            int digitA = (i < m)? a[i]-'0' : 0 ;
            int digitB = (i < n)? b[i]-'0' : 0 ;

            int total = digitA + digitB + carry ;

            // The only difference here is base is 2 . All else is same as simple addition 
            char ch = (total % 2) + '0' ;
            res =  ch + res ; // This helps us make answer in the correct order ,prevents us from having to reverse at the end 
            carry = total / 2 ;
        }

        if( carry){
            res = '1' + res ;
        }

        // TC:O(max(m , n)) and SC:O(1)
        return res ; 
    }
};