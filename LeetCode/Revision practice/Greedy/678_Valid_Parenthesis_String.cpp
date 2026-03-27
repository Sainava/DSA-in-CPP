/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/
#include<iostream>
#include<string>
using namespace std ;

class Solution {
public:

    bool isValid(int index , int cnt , string s){
        // base cases 
        if( cnt < 0 ){
            // A closing bracket does not have a corresponding opening bracket , return false
            return false ;
        }

        if ( index == s.size()){
            // reached the end , check if it is valid or not 
            return cnt==0;
        }
        // Now go character by character , onyl 3 possible -> ( , * , )
        if ( s[index]=='('){
            return isValid(index + 1 , cnt + 1 , s);
        }else if( s[index] == ')'){
            return isValid(index + 1 , cnt - 1 , s);
        }else{
            // This is where we try all possible cases , treat * as (,) and blank
            bool first = isValid(index + 1 , cnt + 1 , s); // '('
            bool second = isValid(index + 1 , cnt - 1 , s); // ')'
            bool third = isValid(index + 1 , cnt  , s); // ' '

            return first || second || third ;

        }
    }

    bool checkValidString(string s) {
        // TC :O(3^n) as for recursive solutions you see no of branches and here it is 3 because * can be changed to 3
        // SC:(n) recursive stack 
        //return isValid(0,0,s);

        // Can improve with DP , two variables index and count both can go from 0 to n 
        // so we can make DP of size n x n
        // TC:O(n^2) and SC:O(n^2)


        // Optimised solution - Instead of count keep 2 min and max , if by the end min is 0 , it is valid 
        int min = 0 , max = 0 ;

        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                min = min + 1;
                max = max + 1;
            }
            else if( s[i] == ')'){
                min = min - 1 ;
                max = max - 1;
            }
            else {
                // * case 
                min = min - 1;
                max = max + 1;
            }

            if (min < 0) min = 0 ;

            if (max < 0) return false ;
        }
        
        //TC:O(n) and SC:O(1)
        return min == 0 ;
    }
};