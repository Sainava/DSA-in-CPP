/*
You are given two strings word1 and word2, each consisting of lowercase English letters.

You are allowed to perform three operations on word1 an unlimited number of times:

Insert a character at any position
Delete a character at any position
Replace a character at any position
Return the minimum number of operations to make word1 equal word2.

Example 1:

Input: word1 = "monkeys", word2 = "money"

Output: 2
Explanation:
monkeys -> monkey (remove s)
monkey -> money (remove k)

Example 2:

Input: word1 = "neatcdee", word2 = "neetcode"

Output: 3
Explanation:
neatcdee -> neetcdee (replace a with e)
neetcdee -> neetcde (remove last e)
neetcde -> neetcode (insert o)

Constraints:

0 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int i , int j , int m , int n ,string word1, string word2 ,vector<vector<int>> &dp){
        // Base case 
        if( j == n && i == m ) return 0 ;
        if( j == n && i!= m){
            // Delete remaining 
            // How many do we need to delete 
            return m - i ;
        }
        if( i == m && j!= n) {
            // Insert the rest 
            return n - j ;
        }

        if( dp[i][j] != -1 ) return dp[i][j];

        if(word1[i] == word2[j]){
            // Do not need to do anything , move forward 
            return dp[i][j] = func(i + 1 , j + 1 , m , n , word1 , word2 , dp) ;
        }else{

            // Insert a word 
            int insert = 1 + func( i , j + 1 , m , n , word1 , word2 , dp); // No need to move i forward as we just inserted the character we need

            // Delete this word 
            int del = 1 +  func( i + 1 , j , m , n , word1 , word2 , dp); 

            // Replace this character to match the characters
            int replace  = 1 +  func(i + 1 , j + 1 , m , n , word1 , word2 , dp) ;

            return dp[i][j] = min(insert , min(del , replace)) ;
        }


    }
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;

        vector<vector<int>> dp( m ,  vector<int> ( n , -1 ));
        // TC:O(m*n) and SC:O(m*n)
        return func( 0 , 0 ,m , n ,word1 ,word2 , dp) ;
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;

        vector<vector<int>> dp( m + 1 ,  vector<int> ( n +1  , 0 ));
        
        // Base cases 
        //dp[m][n] = 0 ; // Not needed as already zero 

        for(int i = 0 ; i < m ; i++){
            dp[i][n] = m - i ;
        }

        for(int j = 0 ; j < n ; j++){
            dp[m][j] = n - j ;
        }

        for(int i = m - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    // Do not need to do anything , move forward 
                    dp[i][j] = dp[i + 1][ j + 1 ] ;
                }else{

                    // Insert a word 
                    int insert = 1 + dp[i][ j + 1 ]; // No need to move i forward as we just inserted the character we need

                    // Delete this word 
                    int del = 1 +  dp[i + 1] [j] ; 

                    // Replace this character to match the characters
                    int replace  = 1 +  dp[i + 1][ j + 1];

                    dp[i][j] = min(insert , min(del , replace)) ;

                }
            }
        }
        // TC:O(m*n) and SC:O(m*n)
        return dp[0][0] ;
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;

        vector<int> curr( n + 1  , 0 );
        vector<int> next( n + 1  , 0 );
        
        // Base cases 
        //dp[m][n] = 0 ; // Not needed as already zero 

        for(int j = 0 ; j < n ; j++){
            next[j] = n - j ;
        }

        for(int i = m - 1 ; i >= 0 ; i--){
            curr[n] = m - i ; // Base case
            for(int j = n - 1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    // Do not need to do anything , move forward 
                    curr[j] = next[ j + 1 ] ;
                }else{

                    // Insert a word 
                    int insert = 1 + curr[ j + 1 ]; // No need to move i forward as we just inserted the character we need

                    // Delete this word 
                    int del = 1 +  next[j] ; 

                    // Replace this character to match the characters
                    int replace  = 1 +  next[ j + 1];

                    curr[j] = min(insert , min(del , replace)) ;

                }
            }
            next = curr ;
        }
        // TC:O(m*n) and SC:O(n)
        return next[0] ;
    }
};
