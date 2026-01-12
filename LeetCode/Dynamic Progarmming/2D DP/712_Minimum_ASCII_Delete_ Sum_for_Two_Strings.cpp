/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std ;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        // FInd all the LCS 
        // Take the maximum LCS in terms of ASCII value 
        // Subtract from the total sum we get the answer 
        // But we do not find all LCS , instead we directly find the highest value LCS 
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = maximum ASCII sum of common subsequence
        // using s1[i..n] and s2[j..m]
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

        // The following loop looks similar to dp in the sense that it has the same loops and conditions 
        // The code is same but logic is different 
        // Since we are not adding one but the ASCII value , the max chooses the one with the highest LCS value 
        // So the following code is sufficient 
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = s1[i] + dp[i+1][j+1]; // IN LCS it was 1 + dp[i+1][j+1]
                }else{
                    dp[i][j] = max( dp[i+1][j] , dp[i][j+1]);
                }

            }
        }

        int sum1= 0 , sum2=0;
        for(char c:s1) sum1+=c;
        for(char c:s2) sum2+=c;

        // TC :O(m x n )
        // SC:O(m x n )
        return sum1 + sum2 - 2*dp[0][0];
    }
};