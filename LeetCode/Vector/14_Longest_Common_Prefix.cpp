/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix="";

        // Check the character of first string with all the other strings 
        // Like a grid and check column wise 
        for(int i = 0 ; i < strs[0].size() ; i++){
            char c = strs[0][i];

            for( int j = 1 ; j < strs.size() ; j++ ){
                if(i >=strs[j].size() || strs[j][i] != c ){
                    return prefix ;
                }
            }

            prefix.push_back(c);
        }

        // TC:O(n x m) ( n strings , m = length of shortest subtring )
        //SC:O(1)
        return prefix ;
    }
};