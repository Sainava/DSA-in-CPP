/*
You are given a string s consisting only of the characters 'a', 'b', and 'c'.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

 

Example 1:

Input: s = "abbac"

Output: 4

Explanation:

The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Example 2:

Input: s = "aabcc"

Output: 3

Explanation:

The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.

Example 3:

Input: s = "aba"

Output: 2

Explanation:

One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

Constraints:

1 <= s.length <= 105
s contains only the characters 'a', 'b', and 'c'.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        // Case 1: Longest substring with 1 distinct character (e.g., "aaaa")
        // We simply look for the longest contiguous segment of identical characters.
        int currentRun = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currentRun++;
            } else {
                currentRun = 1;
            }
            ans = max(ans, currentRun);
        }

        // Case 2: Longest substring with exactly 2 distinct characters
        // We solve this for all 3 pairs: (a,b), (b,c), (a,c).
        // The third character acts as a "forbidden" delimiter that resets the count.
        ans = max(ans, solveTwo(s, 'a', 'b', 'c'));
        ans = max(ans, solveTwo(s, 'b', 'c', 'a'));
        ans = max(ans, solveTwo(s, 'a', 'c', 'b'));

        // Case 3: Longest substring with exactly 3 distinct characters (a, b, c)
        ans = max(ans, solveThree(s));

        return ans;
    }

private:
    // Helper to find longest balanced substring containing ONLY c1 and c2
    int solveTwo(const string& s, char c1, char c2, char forbidden) {
        int maxLen = 0;
        int balance = 0; // Represents count(c1) - count(c2)
        
        // Map stores the first index where a specific balance was seen.
        // Initialized with balance 0 at index -1.
        unordered_map<int, int> firstOccurrence;
        firstOccurrence[0] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == forbidden) {
                // If we hit the forbidden char, the chain breaks. Reset.
                balance = 0;
                firstOccurrence.clear();
                firstOccurrence[0] = i;
            } else {
                if (s[i] == c1) balance++;
                else if (s[i] == c2) balance--;
                
                // If we have seen this balance before, the substring between
                // the previous index and current index has equal numbers of c1 and c2.
                if (firstOccurrence.count(balance)) {
                    maxLen = max(maxLen, i - firstOccurrence[balance]);
                } else {
                    firstOccurrence[balance] = i;
                }
            }
        }
        return maxLen;
    }

    // Helper to find longest balanced substring containing a, b, and c
    int solveThree(const string& s) {
        int maxLen = 0;
        // We need count(a) == count(b) == count(c).
        // This is satisfied if (count(a) - count(b) == 0) AND (count(b) - count(c) == 0).
        int diff1 = 0; // count(a) - count(b)
        int diff2 = 0; // count(b) - count(c)
        
        // Map stores the first index where the tuple {diff1, diff2} was seen.
        map<pair<int, int>, int> firstOccurrence;
        firstOccurrence[{0, 0}] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                diff1++;
            } else if (s[i] == 'b') {
                diff1--;
                diff2++;
            } else if (s[i] == 'c') {
                diff2--;
            }

            if (firstOccurrence.count({diff1, diff2})) {
                maxLen = max(maxLen, i - firstOccurrence[{diff1, diff2}]);
            } else {
                firstOccurrence[{diff1, diff2}] = i;
            }
        }
        return maxLen;
    }
};