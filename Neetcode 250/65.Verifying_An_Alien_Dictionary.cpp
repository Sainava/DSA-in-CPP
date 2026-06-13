/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabets, return true if and only if the given words are sorted lexicographically in this alien language.

Example 1:

Input: words = ["dag","disk","dog"], order = "hlabcdefgijkmnopqrstuvwxyz"

Output: true
Explanation: The first character of the strings are same ('d'). 'a', 'i', 'o' follows the given ordering, which makes the given strings follow the sorted lexicographical order.

Example 2:

Input: words = ["neetcode","neet"], order = "worldabcefghijkmnpqstuvxyz"

Output: false
Explanation: The first 4 characters of both the strings match. But size of "neet" is less than that of "neetcode", so "neet" should come before "neetcode".

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size() ; 

        unordered_map<char ,int > mp ;

        for(int i = 0 ; i < order.size() ; i++){
            mp[order[i]] = i ; 
        }

        for(int i = 1 ;  i < words.size() ; i++){
            string &s1 = words[i-1];
            string &s2 = words[i];

            int len = min( s1.size() , s2.size());

            bool foundDifference = false ; 

            for(int j = 0 ; j < len ; j++){
                if( s2[j] != s1[j]){
                    // First differing word 
                    foundDifference = true ; 
                    if( mp[s2[j]] < mp[s1[j]]){
                        return false ; 
                    }
                    // If valid check for this is done 
                    break ; 
                }
            }

            //Only reaches here if for len characters both words[i] and words[i-1] are same 
            if(foundDifference == false && s1.size() > s2.size()) return false ; 
        }

        // Time Complexity: O(C)
        // C = total number of characters examined while comparing adjacent words.
        // Worst case : C is the total number of characters in all words.
        // Each character is visited at most once during lexicographical comparisons.
        //
        // Space Complexity: O(1)
        // Alien rank map stores only 26 lowercase letters.
        return true ; 
    }
};