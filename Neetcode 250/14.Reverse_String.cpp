/*
You are given an array of characters which represents a string s. Write a function which reverses a string.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["n","e","e","t"]

Output: ["t","e","e","n"]
Example 2:

Input: s = ["r","a","c","e","c","a","r"]

Output: ["r","a","c","e","c","a","r"]
Constraints:

1 <= s.length < 100,000
s[i] is a printable ascii character.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i = 0 ; 
        int j = s.size() - 1 ;

        while( i < j){
            swap(s[i++] , s[j--]);
        }

        //TC:O(n) and SC:O(1)
    }
};