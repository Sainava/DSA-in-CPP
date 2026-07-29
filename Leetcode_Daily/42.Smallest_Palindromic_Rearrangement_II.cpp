// 29 July 2026 

// 3518. Smallest Palindromic Rearrangement II

/*
You are given a palindromic string s and an integer k.

Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.

Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.

 

Example 1:

Input: s = "abba", k = 2

Output: "baab"

Explanation:

The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
Example 2:

Input: s = "aa", k = 2

Output: ""

Explanation:

There is only one palindromic rearrangement: "aa".
The output is an empty string since k = 2 exceeds the number of possible rearrangements.
Example 3:

Input: s = "bacab", k = 1

Output: "abcba"

Explanation:

The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
s is guaranteed to be palindromic.
1 <= k <= 106
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static const long long LIMIT = 1000001;

    // Compute nCr, but stop if it exceeds LIMIT.
    long long combination(int n, int r) {

        if (r > n) return 0;

        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {

            ans = ans * (n - r + i) / i;

            if (ans > LIMIT)
                return LIMIT;
        }

        return ans;
    }

    // Number of distinct permutations of the multiset.
    //
    // Example:
    // a=2,b=1,c=1
    //
    // total = 4
    //
    // 4!/(2!1!1!)
    //
    // We compute this as
    //
    // C(4,2) * C(2,1) * C(1,1)
    //
    long long countWays(vector<int>& freq) {

        int remaining = 0;

        for (int x : freq)
            remaining += x;

        long long ways = 1;

        for (int x : freq) {

            if (x == 0)
                continue;

            ways *= combination(remaining, x);

            if (ways > LIMIT)
                return LIMIT;

            remaining -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        // Build frequency of left half.
        vector<int> half(26);

        string middle = "";

        for (int i = 0; i < 26; i++) {

            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                middle.push_back(char('a' + i));
        }

        // Not enough palindromes.
        if (countWays(half) < k)
            return "";

        int halfLength = 0;

        for (int x : half)
            halfLength += x;

        string left = "";

        for (int pos = 0; pos < halfLength; pos++) {

            // Try every character in lexicographic order.
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long cnt = countWays(half);

                if (cnt >= k) {

                    // This character belongs here.
                    left.push_back(char('a' + c));

                    break;
                }

                // Skip all palindromes beginning
                // with this character.
                k -= cnt;

                half[c]++;
            }
        }

        string right = left;

        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};