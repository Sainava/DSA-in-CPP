/*
Given a string s, split s into substrings where every substring is a palindrome. Return all possible lists of palindromic substrings.

You may return the solution in any order.

Example 1:

Input: s = "aab"

Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"

Output: [["a"]]
Constraints:

1 <= s.length <= 20
s contains only lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int start , int end , string s){
        while(start < end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true ;
    }
    void solve(string s ,vector<vector<string>> &ans ,vector<string> &temp , int index ){
        if( index >= s.length()){
            ans.push_back(temp);
            return ;
        }

        // So we look for all ways we can have a valid partition starting from this index 
        // like if index = 0 
        // palindrme check for [0..0][0..1][0..2] and so on 
        for(int i = index ; i < s.length() ; i++){
            if(isPalindrome(index,i,s)){
                temp.push_back(s.substr(index , i - index+1));
                solve(s,ans,temp,i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> temp ;
        int index = 0 ; 

        solve(s ,ans , temp , index );

        //TC:O(n*2^n) as at every index you cut or dont cut  
        // SC:O(n) recursion stack and SC(n*x) to return where n is size of answer and x is no of answer
        return ans ;
    }
};
