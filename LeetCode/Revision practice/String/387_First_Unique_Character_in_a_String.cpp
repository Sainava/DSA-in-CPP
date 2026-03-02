/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include<iostream>
#include<vector>
using namespace std ;

// SOultion 1 optimised using array instead of map since we know the input is only lowercase english letters

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);

        for(char &c:s){
            int index = c-'a';
            count[index]++;
        }

        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            int index = c - 'a';
            if(count[index]==1){
                return i;
            }
        }

        // TC :O(n) and SC:O(1)
        return -1 ;
    }
};

// Solution 2 using map
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int > count;

        for(char c:s){
            count[c]++;
        }

        for(int i=0;i<s.size();i++){
            if(count[s[i]]==1){
                return i;
            }
        }

        return -1;
    }
};
