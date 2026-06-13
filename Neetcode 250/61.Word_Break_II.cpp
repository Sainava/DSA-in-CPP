/*
You are given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "neetcode", wordDict = ["neet","code"]

Output: ["neet code"]
Example 2:

Input: s = "racecariscar", wordDict = ["racecar","race","car","is"]

Output: ["racecar is car","race car is car"]
Example 3:

Input: s = "catsincars", wordDict = ["cats","cat","sin","in","car"]

Output: []
Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 100,000.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Solution 1 : Backtracking
class Solution {
public:
    void solve( int index , int n , string &s ,unordered_set<string> &st ,vector<string> &temp ,vector<string> &ans){
        if( index == n){
            // Now temp contains the words but we need to add space between them 
            string toPush = "";
            for(string w : temp ){
                toPush += w + " ";
            }
            // remove the last unnecessary space 
            toPush.pop_back();
            ans.push_back(toPush);
            return ;
        }

        // See if there is any word starting from this index
        string word = "";
        for(int i = index ; i < n ; i++){
            word.push_back(s[i]);

            if( st.count(word)){
                temp.push_back(word);
                solve( i + 1 , n , s , st , temp , ans) ; 
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ; 

        unordered_set<string> st ; 

        for(string s : wordDict){
            st.insert(s);
        }
        vector<string> ans ;
        vector<string> temp ; 
        int index = 0 ; 

        
        solve( index , n , s , st , temp ,ans) ;

        //TC:O(2^n) like we are asking at each index can we add a space to it or no 
        // SC:O(n)
        return ans ; 
        
        
    }
};

// Solution 2 : Backtracking + Memoization
class Solution {
public:
    vector<string> solve( int index , int n , string &s ,unordered_set<string> &st,vector<bool> &computed ,vector<vector<string>> &dp){
        if( index == n){
            return {""} ; // A vector with only one element -> An empty string 
        }

        if(computed[index]) return dp[index];

        // See if there is any word starting from this index
        string word = "";
        vector<string> ans = {} ; // For when we cannot complete a valid solution
        // Example say s = "catdogabc" but set only has {cat , dog , dogabc}
        // SO when we break into cat dog we no longer have abc to have valid solution so we return empty vector of strings
        // ELSE IT WILL CONTAIN THE VALID ANSWER
        for(int i = index ; i < n ; i++){
            word.push_back(s[i]);

            if( !st.count(word)){
               // If not in the set just go to next iteration 
               continue ; 
            }
            
            // We are here means word does exist in set 
            vector<string> str = solve( i + 1 , n , s , st , computed , dp);

            if(str.empty()){
                // It did not lead to a valid solution -> Remember {""} our base case DOES NOT satisfy this 
                continue ;
            }

            // Now since it is not empty we did get a solution 
            for(string substr : str){
                string sentence = word ; // Now we build the actual sentence 

                if (!substr.empty()){
                    sentence = sentence + " " + substr ;
                }

                ans.push_back(sentence);
            }
        }

        computed[index] = true;
        dp[index] = ans;
        return dp[index];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ; 

        unordered_set<string> st ; 

        for(string s : wordDict){
            st.insert(s);
        }

        int index = 0 ; 

        // returns ""Give me all valid sentences that can be formed from s[index...n-1]""
        vector<vector<string>> dp(n);
        vector<bool> computed(n,false);

        // TC:O(2^n) so no asymptotic improvement but it makes some cases much faster
        return solve( index , n , s , st ,computed , dp) ;

        // Let:
// n = length of the string
// R = total number of valid sentences returned in the final answer

// Time Complexity:
//
// There are only n possible DP states:
// solve(0), solve(1), ..., solve(n-1)
//
// Due to memoization, each state is computed only once.
//
// For each state 'index', we try all ending positions:
//
//     for(int i = index; i < n; i++)
//
// which contributes O(n²) total substring exploration work
// across all states.
//
// However, this is not the dominant cost.
//
// The dominant cost is constructing the actual answer strings.
// If there are R valid sentences and each sentence can have
// length O(n), then generating and copying all of them costs:
//
//     O(R * n)
//
// Therefore:
//
// Time Complexity:
// O(n² + R * n)
//
// Since the output itself may contain O(R * n) characters,
// this is asymptotically optimal.
//
// ----------------------------------------------------------
//
// Space Complexity:
//
// DP stores:
//
//     dp[index] = all valid sentences starting from index
//
// Therefore the DP table eventually stores all generated
// sentences across all states.
//
// Total memory used by stored sentences:
//
//     O(R * n)
//
// Recursion stack depth:
//
//     O(n)
//
// because at most n characters can be consumed before
// reaching the base case.
//
// Additional containers:
//
//     unordered_set<string> dictionary
//
// stores the dictionary words and is independent of the
// recursion complexity.
//
// Auxiliary Space:
// O(n) recursion stack
//
// Total Space (including memoized answers):
// O(R * n)
//
// ----------------------------------------------------------
//
// Worst Case Example:
//
// s = "aaaaaaaaaa..."
//
// dict = {"a","aa","aaa","aaaa",...}
//
// Number of valid sentences becomes exponential,
// so R itself is exponential.
//
// In that case:
//
// Time  = O(R * n)
// Space = O(R * n)
    }
};