/*
You are given three strings s1, s2, and s3. Return true if s3 is formed by interleaving s1 and s2 together or false otherwise.

Interleaving two strings s and t is done by dividing s and t into n and m substrings respectively, where the following conditions are met

|n - m| <= 1, i.e. the difference between the number of substrings of s and t is at most 1.
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
Interleaving s and t is s1 + t1 + s2 + t2 + ... or t1 + s1 + t2 + s2 + ...
You may assume that s1, s2 and s3 consist of lowercase English letters.

Example 1:



Input: s1 = "aaaa", s2 = "bbbb", s3 = "aabbbbaa"

Output: true
Explanation: We can split s1 into ["aa", "aa"], s2 can remain as "bbbb" and s3 is formed by interleaving ["aa", "aa"] and "bbbb".

Example 2:

Input: s1 = "", s2 = "", s3 = ""

Output: true
Example 3:

Input: s1 = "abc", s2 = "xyz", s3 = "abxzcy"

Output: false
Explanation: We can't split s3 into ["ab", "xz", "cy"] as the order of characters is not maintained.

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool func(int i , int j ,string s1, string s2, string s3 , vector<vector<int>> &dp){
        // Base case 
        if( i == s1.size() && j == s2.size()) return true ; // i = m and j = n and we know m + n = N

        if( dp[i][j] != -1 ) return dp[i][j] ;

        // Now we take the character from s1 or s2 
        bool take1 = false ; 
        bool take2 = false ;

        if(i < s1.size() && s1[i] == s3[i+j]){
            take1 = func(i+1 , j , s1,s2,s3 ,dp);
        }

        if(j < s2.size() && s2[j] == s3[i+j]){
            take2 = func(i , j+1 , s1 ,s2,s3 ,dp) ;
        }

        return dp[i][j] = take1 || take2 ;

    }
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] = meaning :
        // can s3 starting at index [i+j]
        // be made from
        // s1 starting at index[i] and 
        // s2 starting at index[j]

        int m = s1.size() ; 
        int n = s2.size() ;
        int N = s3.size() ;

        if( m + n != N) return false ; // as every character of each string has to be used 

        vector<vector<int>> dp(m+1 , vector<int> ( n+1 , -1));
        // TC:O(m*n) and SC:O(m*n) + SC:O(m+n) recursion stack 
        return func( 0 , 0 , s1 , s2 , s3 , dp ) ; 
        
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Bottom Up 
        int m = s1.size() ; 
        int n = s2.size() ;
        int N = s3.size() ;

        if( m + n != N) return false ; // as every character of each string has to be used 

        vector<vector<bool>> dp(m+1 , vector<bool> ( n+1 , 0));
        dp[m][n] = 1 ; 
        
        for(int i = m ;  i >= 0 ;i--){
            for(int j = n ; j>= 0 ; j--){
                // Now we take the character from s1 or s2 
                    if( i== m && j == n ) continue ; 
                    bool take1 = false ; 
                    bool take2 = false ;

                    if(i < s1.size() && s1[i] == s3[i+j]){
                        take1 = dp[i+1][j];
                    }

                    if(j < s2.size() && s2[j] == s3[i+j]){
                        take2 = dp[i][j+1] ;
                    }

                    dp[i][j] = take1 || take2 ;
            }
        }   
        //TC:O(m*n) and SC:O(m*n)
        return dp[0][0] ; 
    }

    
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Space Optimised  
        int m = s1.size() ; 
        int n = s2.size() ;
        int N = s3.size() ;

        if( m + n != N) return false ; // as every character of each string has to be used 

        vector<bool> next( n+1 , 0);
        vector<bool> curr( n+1 , 0);

        next[n] = 1 ; 
        curr[n] = 1;
        
        for(int i = m ;  i >= 0 ;i--){
            for(int j = n ; j>= 0 ; j--){
                // Now we take the character from s1 or s2 
                    if( i== m && j == n ) continue ; 
                    bool take1 = false ; 
                    bool take2 = false ;

                    if(i < s1.size() && s1[i] == s3[i+j]){
                        take1 = next[j];
                    }

                    if(j < s2.size() && s2[j] == s3[i+j]){
                        take2 = curr[j+1] ;
                    }

                    curr[j] = take1 || take2 ;
            }
            next = curr ; 
        }   
        //TC:O(m*n) and SC:On)
        return next[0] ; 
    }
};

