/*
You are given an encoded string s, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. There will not be input like 3a, 2[4], a[a] or a[2].

The test cases are generated so that the length of the output will never exceed 100,000.

Example 1:

Input: s = "2[a3[b]]c"

Output: "abbbabbbc"
Example 2:

Input: s = "axb3[z]4[c]"

Output: "axbzzzcccc"
Example 3:

Input: s = "ab2[c]3[d]1[x]"

Output: "abccdddx"
Constraints:

1 <= s.length <= 30
s is made up of lowercase English letters, digits, and square brackets '[]'.
All the integers in s are in the range [1, 300].
s is guaranteed to be a valid input.
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size() ;

        stack<char> st ; 

        for(int i = 0 ; i < n ; i++){
            if(s[i]== ']'){
                
                // Make the string that needs to be repeated 
                string word = "";

                // Pop from stack while we get opening bracket
                while(st.top()!= '['){
                    word.push_back(st.top());
                    st.pop();
                }

                // Word is in reverse since we got it from stack 
                reverse(word.begin() , word.end());

                // Now st.top == [ and before it is the number of times it will be repeated , We need to get that number
                st.pop() ; // Pop out the [
                int rep = 0 ;
                int mul = 1;
                while(!st.empty() && isdigit(st.top())){
                    int digit = st.top() - '0';
                    st.pop();
                    rep = rep + digit*mul ;
                    mul = mul*10;
                }

                // Now push the word back into stack rep times ;

                for(int i = 1 ; i <= rep ; i++){
                    
                    for(char c:word){
                        st.push(c);
                    }  
                }

            }
            else{
                st.push(s[i]);
            }
        }

        // Now stack has our answer. 

        string ans ;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin()  , ans.end());

        // Here the TC and SC depend not on the input as mush on the ouput 

        // Let m = length of the decoded string.
        //
        // TC: O(m)
        // SC: O(m)
        //
        // Every character in the decoded output is pushed and popped
        // from the stack at most a constant number of times.


        return ans ; 
    }
};