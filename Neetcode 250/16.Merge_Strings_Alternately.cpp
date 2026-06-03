/*
You are given two strings, word1 and word2. Construct a new string by merging them in alternating order, starting with word1 — take one character from word1, then one from word2, and repeat this process.

If one string is longer than the other, append the remaining characters from the longer string to the end of the merged result.

Return the final merged string.

Example 1:

Input: word1 = "abc", word2 = "xyz"

Output: "axbycz"
Example 2:

Input: word1 = "ab", word2 = "abbxxc"

Output: "aabbbxxc"
Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;

        string ans ;

        int i = 0 ;
        int j = 0 ;

        while( i < m && j < n){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }

        while(i < m){
            ans.push_back(word1[i++]);
        }
        while( j < n){
            ans.push_back(word2[j++]);
        }

        //TC:O(m + n ) and TC:O(1)
        return ans ; 
    }
};