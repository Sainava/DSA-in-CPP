/*
Given a string s, return the longest substring of s that is a palindrome.

A palindrome is a string that reads the same forward and backward.

If there are multiple palindromic substrings that have the same length, return any one of them.

Example 1:

Input: s = "ababd"

Output: "bab"
Explanation: Both "aba" and "bab" are valid answers.

Example 2:

Input: s = "abbc"

Output: "bb"
Constraints:

1 <= s.length <= 1000
s contains only digits and English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

//Solution 1 : Expand from centre
class Solution {
public:
    void checkPalindrome(int l ,int r ,int n , string &s ,int &maxLen , int &startIndex ){
         while(l>=0 && r< n && s[l]==s[r]){
                if( r - l + 1 > maxLen){
                    maxLen = r - l + 1;
                    startIndex = l ;
                }
                l-- ;
                r++;

            }

    }

    string longestPalindrome(string s) {
        // For subsequence 
        // longest common subsequence of (s , reverse of s ) gives longest common palindrome as well
        // But for substring this does not work as it needs to be contiguos 
        // Think for subsequence when it is not required to be contiguous , if a string starts with a , it will find a in reverse as well and can consider it no matter what lies before a in reverse string, this will be true for all letters 
        // But for substirng that will not work 

        //brute force : find all substrings ,  check if palindrome 
        // this would be O(n^3) as n^2 to find all substrings and n to check if palindrome for each

        // We improve it to n^2
        // So for substring we consider every letter to be centre of palindrome ,and store the maxLength ;
        // That we take very character that takes n and expanding both sides takes another n so total TC:O(n^2)
        int n = s.size();

        int maxLen = 0 ; 
        int startIndex =-1 ; 
        for(int i = 0 ; i < n ; i++){
            // for odd -> has a centre 
            int l = i ;
            int r = i ; 

            checkPalindrome(l,r,n,s ,maxLen,startIndex);

            // for even no centre 
            l = i ; 
            r = i + 1;

            checkPalindrome(l,r,n,s ,maxLen,startIndex);

        }

        //TC:O(n^2) and SC:O(1)
        return s.substr(startIndex,maxLen);
    }
};

// Solution 2 : DP
class Solution {
public:
    string longestPalindrome(string s) {
        // dp solution , for all substrings check if they are substrings 
        // But we save the extra check for palindrome of O(n) by using dp 

        int n = s.size();
        
        vector<vector<bool>> dp (n , vector<bool>(n,false));
        // dp[i][j] = true means s[i] to s[j] is a palindrome

        // make all one length substring true as they are palindromes

        int maxLen = 0;
        int startIndex = 0 ;
        // Outer loop -> creates all possible lengths that are possible 
        for(int len = 1 ; len <= n ;len++){
            // Inner loop generate all possible substrings of that length 

            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;
                // dp condition 
                if(s[i] == s[j] && (len<=2 || dp[i+1][j-1])){
                    // then it a palindrome 
                    dp[i][j] = true ; 
                    if(len > maxLen){
                        maxLen = len;
                        startIndex = i;
                    }
                    // len =1 always palindrome (eg : a)
                    // len = 2 and s[i] = s[j] always palindrome ( eg:aa)
                }
            }
        }

        //TC:O(n^2) and SC:O(n^2)
        return s.substr(startIndex , maxLen);

        
    }
};
