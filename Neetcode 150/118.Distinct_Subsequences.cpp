/*
You are given two strings s and t, both consisting of english letters.

Return the number of distinct subsequences of s which are equal to t.

Example 1:

Input: s = "caaat", t = "cat"

Output: 3
Explanation: There are 3 ways you can generate "cat" from s.

(c)aa(at)
(c)a(a)a(t)
(ca)aa(t)
Example 2:

Input: s = "xxyxy", t = "xy"

Output: 5
Explanation: There are 5 ways you can generate "xy" from s.

(x)x(y)xy
(x)xyx(y)
x(x)(y)xy
x(x)yx(y)
xxy(x)(y)
Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int i , int j ,int m ,int n , string s , string t , vector<vector<int>> &dp){
        if( j == n ) return 1 ;

        if( i == m ) return 0 ; 

        if(dp[i][j]!= -1 ) return dp[i][j] ;

        if( s[i] == t[j]){
            // We can either choose to take it or no 

            int take = func(i+1 , j+1 , m , n , s , t , dp);
            int notTake = func(i+1 , j , m , n , s , t ,dp);

            return dp[i][j] = take + notTake ;
        }

        // Not equal , we have no choice but to not take 
        return dp[i][j] = func(i+1 , j , m , n , s , t ,dp);

    }
    int numDistinct(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ; 

        vector<vector<int>> dp(m, vector<int> (n , -1));
        // TC:O(m*n) and SC:O(m*n)
        return func(0 , 0  , m ,n , s , t,dp ) ;
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ; 

        vector<vector<int>> dp(m+1, vector<int> (n+1 , 0));
        // Base cases 
        for(int i = 0 ; i <= m ; i++ ){
            dp[i][n] = 1;
        }
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j>= 0 ; j--){

                if( s[i] == t[j]){
                    // We can either choose to take it or no 
                    int take = dp[i+1][j+1];
                    int notTake = dp[i+1][j];

                    dp[i][j] = take + notTake ;
                }else{
                    // Not equal , we have no choice but to not take 
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        // TC:O(m*n) and SC:O(m*n)
        return dp[0][0] ;
        
       
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ; 

        vector<int> next(n+1 , 0);
        vector<int> curr(n+1 , 0);

        // Base cases 
        next[n] = 1;
        curr[n] = 1;
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j>= 0 ; j--){
                
                if( s[i] == t[j]){
                    // We can either choose to take it or no 
                    int take = next[j+1];
                    int notTake = next[j];

                    curr[j] = take + notTake ;
                }else{
                    // Not equal , we have no choice but to not take 
                    curr[j] = next[j];
                }
            }
            next = curr ;
        }
        // TC:O(m*n) and SC:O(n)
        return next[0] ;
    }
};
