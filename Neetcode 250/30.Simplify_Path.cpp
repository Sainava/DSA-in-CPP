/*
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

Example 1:

Input: path = "/neetcode/practice//...///../courses"

Output: "/neetcode/practice/courses"
Example 2:

Input: path = "/..//"

Output: "/"
Example 3:

Input: path = "/..//_home/a/b/..///"

Output: "/_home/a"
Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


//Solution 1 : Using Stack
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st ; 
        // We need to separate by /
        stringstream ss(path);
        string word;
        
        //TC:O(n)
        while(getline(ss , word , '/')){
            // Remember . means stay at this folder 
            // .. means move to parent

            if( word == "." || word == ""){
                continue ;
            }

            else if ( word == ".."){
                if(!st.empty()) st.pop();
                
            }
            else {
                // Anything else is valid folder(directory) name 
                st.push(word);
            }
        }

        // Rebuilding the answer 
        vector<string> dirs;

        while(!st.empty()){
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin() , dirs.end());

        // Now we need a single string for the answer

        string ans = "";

        for(string &dir : dirs ){
            ans += "/" + dir;
        }

        if(ans.empty()) return "/";

        //TC:O(n) and SC:O(n)
        // Here instead of stack , using vector from the get go becomes easier 
        return ans ; 
    }
};

// Solution 2 : Using Vector as Stack
class Solution {
public:
    string simplifyPath(string path) {
        
        // We will use vector instead of stack 
        vector<string> dirs;
        // We need to separate by /
        stringstream ss(path);
        string word;
        
        //TC:O(n)
        while(getline(ss , word , '/')){
            // Remember . means stay at this folder 
            // .. means move to parent

            if( word == "." || word == ""){
                continue ;
            }

            else if ( word == ".."){
                if(!dirs.empty()) dirs.pop_back();
                
            }
            else {
                // Anything else is valid folder(directory) name 
                dirs.push_back(word);
            }
        }

        // Now we need a single string for the answer

        string ans = "";

        for(string &dir : dirs ){
            ans += "/" + dir;
        }

        if(ans.empty()) return "/";

        //TC:O(n) and SC:O(n)
        // Here instead of stack , using vector from the get go becomes easier 
        return ans ; 
    }
};