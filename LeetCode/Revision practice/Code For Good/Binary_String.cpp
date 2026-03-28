/*
Given a binary string s. You have to count the number of substrings that start and end with 1.

Examples:

Input: s = "1111"
Output: 6
Explanation: There are 6 substrings from the given string. They are "11", "11", "11", "111", "111", "1111".
Input: s = "01101"
Output: 3
Explanation: There are 3 substrings from the given string. They are "11", "101", "1101".
Constraints:
1 ≤ |s| ≤ 104
*/
#include<iostream>
#include<vector>
using namespace std ;


class Solution {
  public:
    int binarySubstring(string& s) {
        // code here
        // Basically  I just need to select two different indices of two 
        // This questions essentially becomes if there are k ones , how can i select two different ones 
        
        // That is kC2 = k!/2!*(k-2)! = k*k-1 / 2
        
        int cnt = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='1') cnt++;
        }
        
        //TC:O(n) and SC:O(1)
        return (cnt*(cnt -1 )) / 2;
        
    }
};