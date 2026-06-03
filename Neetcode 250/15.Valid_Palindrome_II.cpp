/*
You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

A palindrome is a string that reads the same forward and backward.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Example 1:

Input: s = "aca"

Output: true
Explanation: "aca" is already a palindrome.

Example 2:

Input: s = "abbadc"

Output: false
Explanation: "abbadc" is not a palindrome and can't be made a palindrome after deleting at most one character.

Example 3:

Input: s = "abbda"

Output: true
Explanation: "We can delete the character 'd'.

Constraints:

1 <= s.length <= 100,000
s is made up of only lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome( string &s , int i , int j){

        while(i < j){
            if( s[i++] != s[j--]) return false ; 
        }
        return true ;
    }

    bool validPalindrome(string s) {
        // I am only allowed one deletion 

        int i = 0 ; 
        int j = s.size() -1 ;

        while ( i < j){
            if( s[i]== s[j]){
                i++ ; 
                j--;
            }
            else{
                // Use the deletion now 
                // MOve s[i] or s[j]
                // Also since only deletion we cannot recursively call the same function we need to call a simple function 

                return isPalindrome(s , i+1 , j) || isPalindrome(s , i , j-1);
            }
        }

        //TC:O(n) as outer function is O(n) and inner function is O(n) and is called only twice 
        //SC:O(1)
        return true ;
    }
};