// 28 July 2026

//3517. Smallest Palindromic Rearrangement I

/*
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.

 

Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency of every character
        for (char ch : s)
            freq[ch - 'a']++;

        string left = "";
        string middle = "";

        // Construct the left half
        for (int i = 0; i < 26; i++) {

            left.append(freq[i] / 2, char('a' + i));

            // If a character has odd frequency,
            // it must be the middle character.
            if (freq[i] % 2 == 1)
                middle = char('a' + i);
        }

        // Right half is the reverse of the left half
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;

        // TC: O(n)
        // - Count frequencies: O(n)
        // - Build palindrome: O(n)
        //
        // SC: O(n)
        // - Left half + right half + answer
        // - Frequency array uses O(26) = O(1)
    }
};