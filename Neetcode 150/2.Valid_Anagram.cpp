/*
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char ,int> mp1;
        // unordered_map<char,int> mp2;

        // //TC:O(n1)
        // for(char c:s ){
        //     mp1[c]++;
        // }

        // //TC:O(n2)
        // for(char c:t){
        //     mp2[c]++;
        // }

        // //TC:O( n1 + n2) and SC:O( n1 + n2)
        // return mp1==mp2;


        // Solution 2

        if( s.size() != t.size()){
            return false ;
        }

        //SC:O(1)
        vector<int> cnt(26,0);

        //TC:O(n)
        for( char c : s){
            cnt[c-'a']++;
        }

        //TC:O(n)
        for( char c : t){
            cnt[c-'a']--;

            if(cnt[c-'a'] < 0){
                return false;
            }
        }

        //TC:O(n) and SC:O(1)
        return true ;

    }
};
