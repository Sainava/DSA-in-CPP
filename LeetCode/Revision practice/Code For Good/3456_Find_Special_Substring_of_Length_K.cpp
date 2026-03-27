/*
You are given a string s and an integer k.

Determine if there exists a substring of length exactly k in s that satisfies the following conditions:

The substring consists of only one distinct character (e.g., "aaa" or "bbb").
If there is a character immediately before the substring, it must be different from the character in the substring.
If there is a character immediately after the substring, it must also be different from the character in the substring.
Return true if such a substring exists. Otherwise, return false.

 

Example 1:

Input: s = "aaabaaa", k = 3

Output: true

Explanation:

The substring s[4..6] == "aaa" satisfies the conditions.

It has a length of 3.
All characters are the same.
The character before "aaa" is 'b', which is different from 'a'.
There is no character after "aaa".
Example 2:

Input: s = "abc", k = 2

Output: false

Explanation:

There is no substring of length 2 that consists of one distinct character and satisfies the conditions.

 

Constraints:

1 <= k <= s.length <= 100
s consists of lowercase English letters only.
*/
#include<iostream>
#include<string>
using namespace std ;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        // int l = 0 ;
        // int r = 0 ;

        // int n = s.size() ;
        
        

        // while( r < n ){
        //     // if valid 
        //     if(s[r] == s[l]){
        //         int length = r - l + 1;
        //         if( (l==0 || s[l]!= s[l-1] ) &&( r == n-1 || s[r]!=s[r+1]) && (length == k ) )return true ;
        //     }else{
        //         // check the next substring
        //         l = r ;
        //     }

        //     r++;
        // }

        // //TC:O(n) and SC:(1)
        // return false;

        // The above fails some of the test cases so sliding window is not best approach for this 
        
        int n = s.size() ;
        int cnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]){
                cnt++;
            }else{
                if(cnt == k) return true;
                cnt = 1;
            }
        }
        // check last group 
        if( cnt == k) return true ;

        // TC :O(n) and SC:(1)
        return false;
    }
};