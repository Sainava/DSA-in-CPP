/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/
#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.size() ;

        // for(int len = 1 ; len <= n/2 ; len++){
        //     if ( n % len != 0) continue ;

        //     string pattern = s.substr(0 , len );
        //     string constructed = "";

        //     int times = n / len ;

        //     for(int  i = 0 ; i < times ; i++){
        //         constructed += pattern;
        //     }

        //     if ( constructed == s) return true ; 

        // }

        // //TC:TC:O(n^2) and SC:O(n) 
        // return false ;


        // Approach 2 
        string t = s + s;

        t = t.substr( 1 , t.length() - 2);

        //TC:O(n) and SC:O(n)
        return t.find(s) != string ::npos ;
    }
};