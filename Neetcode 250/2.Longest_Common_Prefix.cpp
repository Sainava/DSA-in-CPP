/*
You are given an array of strings strs. Return the longest common prefix of all the strings.

If there is no longest common prefix, return an empty string "".

Example 1:

Input: strs = ["bat","bag","bank","band"]

Output: "ba"
Example 2:

Input: strs = ["dance","dag","danger","damage"]

Output: "da"
Example 3:

Input: strs = ["neet","feet"]

Output: ""
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] is made up of lowercase English letters if it is non-empty.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty()) return "" ;

        string prefix = "";

        int m = strs[0].size() ;
        int n = strs.size() ; 

        // Take each character from the first string and see if that character is in that position for the rest of the strings 
        for(int i = 0 ; i < m ; i++){
            char curr = strs[0][i] ;

            for(int j = 1 ; j < n ; j++){
                if( i >= strs[j].size() || strs[j][i] != curr){
                    return prefix ; 
                }
            }
            prefix.push_back(curr);
        }   

        //TC:O(m x n) and SC:O(1) extra space , SC:O(n) to return answer
        return prefix ; 
    }
};