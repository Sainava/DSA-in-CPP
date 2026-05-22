/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of dictionary words.

You are allowed to reuse words in the dictionary an unlimited number of times. You may assume all dictionary words are unique.

Example 1:

Input: s = "neetcode", wordDict = ["neet","code"]

Output: true
Explanation: Return true because "neetcode" can be split into "neet" and "code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen","ape"]

Output: true
Explanation: Return true because "applepenapple" can be split into "apple", "pen" and "apple". Notice that we can reuse words and also not use all the words.

Example 3:

Input: s = "catsincars", wordDict = ["cats","cat","sin","in","car"]

Output: false
Constraints:

1 <= s.length <= 200
1 <= wordDict.length <= 100
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool solve(int index , string &s ,unordered_map<string,bool> &mp ,int n ,vector<int> &dp ){
        if( index == n){
           return true ;
        } 

        if(dp[index]!= -1 ) return dp[index];

        string temp = "";
        bool isPossible = false ;
        for(int i = index ; i < n ;i++){
            temp.push_back(s[i]);

            if(mp[temp]){
                isPossible = solve(i+1 , s , mp , n ,dp) ;
            }
            if(isPossible){
                return dp[index] = true  ; 
            }
        }

        dp[index] = false ;
        return  dp[index];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string,bool> mp ;
        for(int i = 0 ; i < wordDict.size() ; i++){
            mp[wordDict[i]] = true ;
        }

        

        //Top - Down 
        //vector<int> dp(n,-1) ; // Is there a word in the dict starting from this index 
        // Now starting at every index , ask if a valid word can be made from this index 
        //TC:O(n^2) as at every index , extend substring to n  
        //and SC:O(n)
        //return solve(0 , s , mp , n , dp);

        // Bottom up 
        vector<bool> dp(n+1,false) ;

        dp[n] = true ; 

        for(int i = n-1 ; i >= 0 ; i--){
            string temp = "";
            for(int j = i ; j < n ;j++){
                temp.push_back(s[j]);

                if(mp[temp] && dp[j+1] ){
                    dp[i] = true ; 
                    break ; 
                }
            }
        }
        //TC:O(n^2) as at every index , extend substring to n  
        //and SC:O(n)
        return dp[0];

    }
};
