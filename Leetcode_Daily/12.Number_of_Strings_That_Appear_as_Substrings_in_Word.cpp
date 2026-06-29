// 29 June 2026

//1967. Number of Strings That Appear as Substrings in Word

/*
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
Example 3:

Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
 

Constraints:

1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &pattern : patterns) {
            if (word.find(pattern) != string::npos)
                ans++;
        }

        // Complexity

        // Suppose:

        // n = patterns.size()
        // m = word.length()
        // k = average pattern length

        // The worst-case complexity of find() is implementation-dependent, but you can think of it as roughly:

        // O(m * k)

        // For this problem:

        // patterns.length <= 100
        // word.length <= 100
        // pattern.length <= 100

        // So at most about

        // 100 × 100 × 100 = 10^6

        // character comparisons, which is perfectly acceptable.

        // For larger string-matching problems, you'd learn algorithms like KMP, Rabin–Karp, Z-algorithm, or Aho–Corasick, but for this Easy problem, find() is the intended and cleanest solution.
        
        return ans;
    }
};