// 22 June 2026

//1189. Maximum Number of Balloons

/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:

Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
 

Note: This question is the same as 2287: Rearrange Characters to Make Target String.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // For example:

        // b = 5
        // a = 3
        // l = 8
        // o = 6
        // n = 4

        // Then:

        // b allows 5 balloons
        // a allows 3 balloons
        // l allows 8/2 = 4 balloons
        // o allows 6/2 = 3 balloons
        // n allows 4 balloons

        // So the answer is:

        // min(5, 3, 4, 3, 4) = 3

        vector<int> freq(26) ;

        for(char ch :text ){
            freq[ch - 'a']++;
        }

        return min ({
            freq['b' - 'a'] ,
            freq['a' - 'a'] ,
            freq['l' - 'a'] /2,
            freq['o' - 'a'] /2 ,
            freq['n' - 'a'] ,
            }) ;

        //TC:O(n) and SC:O(26) or SC: O(1)
    }
};