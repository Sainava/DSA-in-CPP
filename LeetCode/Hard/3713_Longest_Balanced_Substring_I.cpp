/*
You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

 

Example 1:

Input: s = "abbac"

Output: 4

Explanation:

The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Example 2:

Input: s = "zzabccy"

Output: 4

Explanation:

The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​

Example 3:

Input: s = "aba"

Output: 2

Explanation:

​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {

                int idx = s[j] - 'a';

                if (freq[idx] == 0) distinct++;

                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                if (len == distinct * maxFreq) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
