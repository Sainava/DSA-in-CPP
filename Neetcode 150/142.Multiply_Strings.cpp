/*
You are given two strings num1 and num2 that represent non-negative integers.

Return the product of num1 and num2 in the form of a string.

Assume that neither num1 nor num2 contain any leading zero, unless they are the number 0 itself.

Note: You can not use any built-in library to convert the inputs directly into integers.

Example 1:

Input: num1 = "3", num2 = "4"

Output: "12"
Example 2:

Input: num1 = "111", num2 = "222"

Output: "24642"
Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1 == "0" || num2 == "0") return "0" ;

        int m = num1.size() ; 
        int n = num2.size() ;

        // We know the size of the answer -> atmost ( m + n)
        // But that is ATMOST and we will make an answer from the back so we store in int first

        vector<int> mul(m+n , 0) ; 

        // Reverse - DO not think of traversing backwards directly , that will not work as we know the max suze of answer but not the exact size
        reverse(num1.begin() , num1.end()) ;
        reverse(num2.begin() , num2.end()) ;

        for(int i = 0 ;  i < m ; i++){ 
            for(int j = 0; j < n ; j++){

                int digit = (num1[i] - '0') * (num2[j] - '0');

                int sum  = mul[i + j] + digit ;

                mul[i + j] = sum % 10 ;
                mul[i+j+1] += sum  / 10 ; 
            }
        }

        // Now mul contains the answer we need but in reverse 
        reverse(mul.begin() , mul.end());

        // Now we build the answer in string as required 
        string ans = "";
        int i = 0 ; 
        while( mul[i] == 0 ) i++ ; // Ignore all leading zeroes 

        while(i < m+n){
            char digit = mul[i] + '0' ; 
            ans.push_back(digit);
            i++;
        }   

        //TC:O(m*n + m + n ) and SC:O(m+n) for auxillary array 
        return ans ;
    }
};
