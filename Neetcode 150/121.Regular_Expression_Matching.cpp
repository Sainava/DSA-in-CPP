/*
You are given an input string s consisting of lowercase english letters, and a pattern p consisting of lowercase english letters, as well as '.', and '*' characters.

Return true if the pattern matches the entire input string, otherwise return false.

'.' Matches any single character
'*' Matches zero or more of the preceding element.
Example 1:

Input: s = "aa", p = ".b"

Output: false
Explanation: Regardless of which character we choose for the '.' in the pattern, we cannot match the second character in the input string.

Example 2:

Input: s = "nnn", p = "n*"

Output: true
Explanation: '*' means zero or more of the preceding element, 'n'. We choose 'n' to repeat three times.

Example 3:

Input: s = "xyz", p = ".*z"

Output: true
Explanation: The pattern ".*" means zero or more of any character, so we choose ".." to match "xy" and "z" to match "z".

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
Each appearance of '*', will be preceded by a valid character or '.'.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool func(int i , int j , string s, string p ,int m ,int n ,  vector<vector<int>> &dp){
        
        // Base Case 
        // Pattern exhausted -> string must also be exhausted
        if(j == n) return i == m;


        if(dp[i][j] != - 1) return dp[i][j] ; 
        // Current character matches if:
        // 1. i is within bounds
        // 2. exact match OR '.' wildcard
        bool match = (i < m) && 
                     (s[i] == p[j] || p[j] == '.');

        // CASE 1:
        // Next character in pattern is '*'
        // Example:
        // a*  -> "", "a", "aa", "aaa" ...
        if(j + 1 < n && p[j + 1] == '*'){

            // Two possibilities:

            // 1. Take zero occurrences
            // Skip current pattern character and '*'
            // Example:
            // s = "b"
            // p = "a*b"
            // Skip a*
            bool takeZero = func(i , j + 2 , s , p , m, n , dp);

            // 2. Take one occurrence
            // Only possible if current characters match
            // Stay at same pattern index because '*' can repeat again
            // Example:
            // s = "aaa"
            // p = "a*"
            // keep consuming a's
            bool takeOne = false;

            if(match){
                takeOne = func(i + 1 , j , s , p , m, n, dp);
            }

            return dp[i][j] = takeZero || takeOne;
        }

        // CASE 2:
        // No '*'
        // Then current characters must match
        // and both pointers move forward
        if(match){
            return dp[i][j] = func(i + 1 , j + 1 , s , p , m, n, dp);
        }

        // CASE 3:
        // Characters do not match
        // and no '*' exists to save us
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size() ; 
        int n = p.size() ; 
        // ab*c can be interpreted as:
        // ac , abc , abbc , abbbc ...
        // because '*' means:
        // zero or more occurrences of previous character

        // At every x* we have two choices:
        // 1. Take zero x
        // 2. Take one x and stay on same pattern

        // '.' matches any single character
        // '.*' matches any sequence
        vector<vector<int>> dp(m + 1 , vector<int> ( n + 1 , -1 )) ;
        // TC :O(m*n) and SC:O(m*n) + SC:O(m + n )
        return func(0 , 0 , s , p , m , n , dp);
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();

        // dp[i][j] =
        // can s starting from index i
        // match p starting from index j

        vector<vector<bool>> dp(m + 1 , vector<bool>(n + 1 , false));

        // Base case
        // Empty string matches empty pattern
        dp[m][n] = true;

        // Traverse backwards
        for(int i = m ; i >= 0 ; i--){

            for(int j = n - 1 ; j >= 0 ; j--){

                // Current characters match if:
                // 1. i is within bounds
                // 2. exact match OR '.' wildcard
                bool match =
                    (i < m) &&
                    (s[i] == p[j] || p[j] == '.');

                // CASE 1:
                // Next character is '*'
                // Example:
                // a* -> "", "a", "aa", ...
                if(j + 1 < n && p[j + 1] == '*'){

                    // Take zero occurrences
                    bool takeZero = dp[i][j + 2];

                    // Take one occurrence
                    // stay at same pattern index
                    bool takeOne = false;

                    if(match){
                        takeOne = dp[i + 1][j];
                    }

                    dp[i][j] = takeZero || takeOne;
                }

                // CASE 2:
                // No '*'
                // Characters must match
                else{

                    if(match){
                        dp[i][j] = dp[i + 1][j + 1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        // TC :O(m*n) and SC:O(m*n)
        return dp[0][0];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<bool> next (n + 1 , false);
        vector<bool> curr (n + 1 , false);

        // Base case
        // Empty string matches empty pattern
        next[n] = true;
        // Traverse backwards
        for(int i = m ; i >= 0 ; i--){
            
            for(int j = n - 1 ; j >= 0 ; j--){
                if ( i == m) {
                   curr[n] = true ;
                   
                }else{
                    curr[n] = false ; // Need to overwrite the previous value if it had been set to true 
                } 
                // Current characters match if:
                // 1. i is within bounds
                // 2. exact match OR '.' wildcard
                bool match =
                    (i < m) &&
                    (s[i] == p[j] || p[j] == '.');

                // CASE 1:
                // Next character is '*'
                // Example:
                // a* -> "", "a", "aa", ...
                if(j + 1 < n && p[j + 1] == '*'){

                    // Take zero occurrences
                    bool takeZero = curr[j + 2];

                    // Take one occurrence
                    // stay at same pattern index
                    bool takeOne = false;

                    if(match){
                        takeOne = next[j];
                    }

                    curr[j] = takeZero || takeOne;
                }

                // CASE 2:
                // No '*'
                // Characters must match
                else{

                    if(match){
                        curr[j] = next[j + 1];
                    }
                    else{
                        curr[j] = false;
                    }
                }
            }
            next = curr ; 
        }

        // TC :O(m*n) and SC:O(n)
        return next[0];
    }
};
