/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // // Solution 1 
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());

        // // TC:O(nlogn) and SC:O(logn)
        // return s==t;

        // SOlution 2
        unordered_map<char , int> first;
        unordered_map<char ,int > second ;

        for(auto ch:s){
            first[ch]++;
        }

        for(auto ch:t){
            second[ch]++;
        }

        //TC:O(n) and SC:O(n)
        return first == second ;

    }
};