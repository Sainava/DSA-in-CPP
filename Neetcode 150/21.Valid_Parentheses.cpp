/*
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true
Example 3:

Input: s = "[(])"

Output: false
Explanation: The brackets are not closed in the correct order.

Constraints:

1 <= s.length <= 1000

*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            // closing bracket
            else{
                // check top of stack 
                if(!st.empty()){
                    if( (s[i]==')' && st.top()== '(') ||
                        (s[i]=='}' && st.top()== '{') ||
                        (s[i]==']' && st.top()== '[')
                    ){
                        st.pop();
                    }else{
                        return false;
                    }

                }else{
                    return false;
                }
            }
            
        }

        //TC:(n) and SC:O(n)
        return st.empty();
    }
};
