// 08 August 2026

// 3302. Find the Lexicographically Smallest Valid Sequence

/*
You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character
in x to make it identical to y.

A sequence of indices seq is called valid if:

The indices are sorted in ascending order.
Concatenating the characters at these indices in word1 in the same order results
in a string that is almost equal to word2. Return an array of size word2.length
representing the lexicographically smallest valid sequence of indices. If no
such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not
the corresponding string formed by those indices.



Example 1:

Input: word1 = "vbcca", word2 = "abc"

Output: [0,1,2]

Explanation:

The lexicographically smallest valid sequence of indices is [0, 1, 2]:

Change word1[0] to 'a'.
word1[1] is already 'b'.
word1[2] is already 'c'.
Example 2:

Input: word1 = "bacdc", word2 = "abc"

Output: [1,2,4]

Explanation:

The lexicographically smallest valid sequence of indices is [1, 2, 4]:

word1[1] is already 'a'.
Change word1[2] to 'b'.
word1[4] is already 'c'.
Example 3:

Input: word1 = "aaaaaa", word2 = "aaabc"

Output: []

Explanation:

There is no valid sequence of indices.

Example 4:

Input: word1 = "abc", word2 = "ab"

Output: [0,1]



Constraints:

1 <= word2.length < word1.length <= 3 * 105
word1 and word2 consist only of lowercase English letters.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> validSequence(string word1, string word2) {

    int n1 = word1.size();
    int n2 = word2.size();

    // suf[i] tells us how much of word2 cannot be matched
    // using the suffix word1[i...].
    //
    // More precisely:
    // suf[i] = first index in word2 that is NOT matched
    // when we greedily match word2 from right to left.
    vector<int> suf(n1 + 1);

    // If there are no characters in word1,
    // we have matched nothing from word2.
    suf[n1] = n2;

    int j = n2 - 1;

    // Match word2 from right to left.
    for (int i = n1 - 1; i >= 0; i--) {

      if (j >= 0 && word1[i] == word2[j]) {
        j--;
      }

      suf[i] = j + 1;
    }

    vector<int> ans;

    int j2 = 0;

    // Whether we have already used our one allowed mismatch.
    bool usedMismatch = false;

    // Greedily choose the earliest possible index.
    for (int i = 0; i < n1 && j2 < n2; i++) {

      // Case 1:
      // Current character already matches word2[j2].
      if (word1[i] == word2[j2]) {

        ans.push_back(i);
        j2++;
      }

      // Case 2:
      // Current character does not match.
      //
      // We can use this as our ONE mismatch only if
      // the remaining suffix can match the remaining
      // characters of word2.
      else if (!usedMismatch && suf[i + 1] <= j2 + 1) {

        usedMismatch = true;

        // We "change" word1[i] into word2[j2].
        ans.push_back(i);
        j2++;
      }
    }

    // We successfully matched all of word2.
    if (j2 == n2)
      return ans;

    // Otherwise no valid sequence exists.
    return {};
  }
};