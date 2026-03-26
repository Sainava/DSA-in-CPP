/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std ;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size() ;
        
        //SC:O(n.m) after storing strings 
        unordered_map<string,vector<string>> mp;

        //TC:O(n*(mlogn))
        for(int i = 0 ; i < n ; i++){
            string temp = strs[i];
            sort(temp.begin() , temp.end());

            mp[temp].push_back(strs[i]);
        } 

        vector<vector<string>> ans;

        //TC:O(n)
        for(auto &p:mp){
            ans.push_back(p.second);
        }

        // TC(n + n(mlogm)) and SC:O(n.m)
        return ans;
    }
};