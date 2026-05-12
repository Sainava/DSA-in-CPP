/*
You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example 1:

Input: n = 1

Output: ["()"]
Example 2:

Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]
You may return the answer in any order.

Constraints:

1 <= n <= 7
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int n , vector<string> &ans ,string &temp ,int openCnt , int closeCnt){
        if(temp.length()==2*n){
            // All brackets used -> so valid solution 
            ans.push_back(temp);
            return ; 
        }

        // Now we call for the two choices we have 
        if(openCnt < n){
            temp.push_back('(');
            solve(n,ans,temp,openCnt+1,closeCnt);
            temp.pop_back();
        }

        if(openCnt > closeCnt){
            temp.push_back(')');
            solve(n,ans,temp,openCnt,closeCnt+1);
            temp.pop_back();
        }

        return ;
    }
    vector<string> generateParenthesis(int n) {
        // At each point we have two branch 
        // One for the open bracket and the other for the close bracker
        // The condition for open bracket is simple : If we have remaining open brackets , go down that path
        // The condition for close bracket is noOfOpenBracket > noOfCloseBracket as close bracket needs a open bracker to close 

        vector<string> ans ;
        string temp = "";
        int openCnt = 0 ; 
        int closeCnt = 0 ;
        solve(n , ans , temp , openCnt,closeCnt);

        //TC:O(2^n*n) as at each point we have two choices and copying is another n(2*n) to be exact 
        // SC:O(n) for recursion stack and SC:O(2*n*x) x is no of solution and 2*n is size of each solution 
        return ans;
    }
};
