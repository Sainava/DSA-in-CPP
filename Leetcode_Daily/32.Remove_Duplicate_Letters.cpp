// 19 July 2026 

// 316. Remove Duplicate Letters


/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size() ;

        // SC:O(1) for all , even for stack as we only store distinct lower case letters so worst case :O(26)
        stack<char> st ;
        vector<int> lastIndex(26 , 0);
        vector<int> inStack(26 , 0);


        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            lastIndex[s[i] - 'a'] = i ; 
        }

        //TC:O(n) as all characters pushed and popped atmost once 
        for(int i = 0 ; i < n ; i++){
            char ch = s[i] ; 
            // First I need to see if it is already in stack ,if yes , move on 
            if( !inStack[ ch - 'a']){
                // Now we know we will push a unique character onto the stack 

                // If it is lexicographically smaller than the top of stack and character at top stack is seen later too , we can pop the top of stack 

                while( !st.empty() && ch < st.top() && lastIndex[st.top()-'a'] > i){
                        inStack[st.top()-'a'] = 0 ; 
                        st.pop() ;
                        
                } 

                st.push(ch) ;
                inStack[ch - 'a'] = 1 ; 
            }
        }

        string ans = "" ;

        // TC: O(26) = O(1)
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop() ; 
        }

        // TC: O(26) = O(1)
        reverse(ans.begin() , ans.end()) ;

        //TC:O(n) and SC:O(1)
        return ans ; 
    }
};