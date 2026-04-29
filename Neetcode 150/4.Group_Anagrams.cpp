/*
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
Constraints:

1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // TC:O(nxk)
        unordered_map<string,vector<string>> mp;

        // TC:O(nklogk)
        for(int i = 0 ; i < strs.size() ; i++){
            string temp = strs[i];
            sort( temp.begin() , temp.end());
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans ; 

        //TC:O(n)
        for(auto p : mp){
            ans.push_back(p.second);
        }

        //TC:O(n + nklogk) and SC:O(nk)
        return ans ;
    }
};
