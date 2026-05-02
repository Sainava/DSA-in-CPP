/*
You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.

Example 1:

Input: s1 = "abc", s2 = "lecabee"

Output: true
Explanation: The substring "cab" is a permutation of "abc" and is present in "lecabee".

Example 2:

Input: s1 = "abc", s2 = "lecaabee"

Output: false
Constraints:

1 <= s1.length, s2.length <= 1000

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Sliding window 
        int n = s2.size();
        int k = s1.size(); // Size of the sliding window 

        vector<int> f1(26);
        vector<int> f2(26);

        for(char c:s1){
            f1[c-'a']++;
            // We check against this always ;
        }

        // Now check for the first window 
        for(int i = 0 ; i < k ; i++){
            f2[s2[i] - 'a']++;
        }

        // check if they are permutations 
        if(f1==f2) return true ;

        // Now we check for the next window 
        for(int i = k ; i < n ;i++){
            // We remove one character from the window and add current one to the window 
            f2[s2[i-k] - 'a']--;
            f2[s2[i] - 'a']++;

            if(f1==f2) return true ;
        }

        //TC:O( n + k) and SC:O(1)
        return false ;
    }
};
