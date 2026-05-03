/*
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.
Example 1:

Input: tokens = ["1","2","+","3","*","4","-"]

Output: 5

Explanation: ((1 + 2) * 3) - 4 = 5
Constraints:

1 <= tokens.length <= 1000.
tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int eval(int a ,int b , string op){
        if(op == "+"){
            return b + a;
        }
        else if (op == "-"){
            return b - a;
        }
        else if (op == "*"){
            return b * a;
        }
        else{
            return b / a;
        }
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            
            if( st.size()>=2 && (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" )){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(eval(a,b,tokens[i]));

            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        //TC :O(n) and SC:O(n)
        return st.top();
    }
};
