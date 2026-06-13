/*
You are given a string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

Note that the same word in the dictionary may be reused multiple times.

Example 1:

Input: s = "neetcodes", dictionary = ["neet","code","neetcode"]

Output: 1
Explanation: The optimal way is to break s into two substrings: "neet" from index 0 to 3 and "code" from index 4 to 7. There is one character which is at index 8.

Example 2:

Input: s = "neetcodde", dictionary = ["neet","code","neetcode"]

Output: 5
Explanation: The optimal way is to break s into one substring: "neet" from index 0 to 3. The characters at indices from 4 to 8 are extra.

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
s and dictionary[i] consist of only lowercase English letters
dictionary contains distinct words

*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

//SOlution 1 : Backtracking + Memoization
class Solution {
public:
    int solve (int index , int n ,string &s,unordered_set<string> &st ,vector<int> &dp ){
        if(index == n ){
            return 0 ; 
        }

        if( dp[index] != -1 ) return dp[index];

        // At every index I have two choices . Either I take this char to form a word or I do not 

        // Skip 
        int res = 1 + solve(index + 1 , n , s , st,dp); // We add one becuase that is the 

        string word = "";
        for(int i = index ; i < n ; i++){
            word.push_back(s[i]);

            if( st.count(word)){
                res = min ( res ,solve(i + 1 , n , s , st,dp));
            }
        }

        return dp[index] = res ;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size() ;

        unordered_set<string> st ; 

        for(string str:dictionary){
            st.insert(str);
        }

        int index = 0 ; 

        //What is the minimum number of extra characters from index onward?
        vector<int> dp(n,-1);

        return solve(index , n , s ,st , dp);


// Time Complexity: O(n^3)
//
// Let n = s.length().
//
// DP State:
// dp[index] = minimum extra characters needed for suffix s[index...n-1].
//
// Since index can take values from 0 to n-1,
// there are O(n) unique DP states.
//
// ------------------------------------------------------------
//
// Work done in one DP state:
//
// For a fixed index:
//
//     for(int i = index; i < n; i++)
//
// generates all substrings that start at 'index':
//
// Lengths checked:
//
//     1, 2, 3, ..., (n - index)
//
// For each substring we perform:
//
//     st.count(word)
//
// Although unordered_set lookup is O(1) on average,
// the hash of the string must first be computed.
//
// To hash a string of length L,
// every character must be examined once.
//
// Therefore:
//
//     st.count(word) = O(L)
//
// where L is the current substring length.
//
// For one DP state, total hashing work is:
//
//     1 + 2 + 3 + ... + (n - index)
//
// = O((n - index)^2)
//
// ------------------------------------------------------------
//
// Summing across all DP states:
//
//     Σ O((n - index)^2)
//     for index = 0 to n-1
//
// = O(n^3)
//
// Therefore:
//
// Time Complexity = O(n^3)
//
// ------------------------------------------------------------
//
// Space Complexity: O(n)
//
// DP array:
//
//     vector<int> dp(n, -1)
//
// requires O(n) space.
//
// Recursion stack:
//
// Each recursive call moves forward in the string,
// so maximum recursion depth is O(n).
//
// Therefore:
//
// Auxiliary Space = O(n)
//
// ------------------------------------------------------------
//
// Total:
//
// Time Complexity  : O(n^3)
// Space Complexity : O(n)
    }
};





// SOLUTION 2 : Backtracking + Memoization + Trie

class TrieNode{
    // every node in trie
    // question says it uses lower case letter 
    public :

    char ch ;
    vector<TrieNode*> children;
    bool isTerminal ; // this helps in checking 

    TrieNode(char ch ){
        this -> ch = ch ;
        isTerminal = false ;

        for(int i = 0 ; i < 26 ; i++){
            this->children.push_back(NULL) ;
        }
    }
};

class PrefixTree {
public:
    
    // All functions are TC:O(l) and SC:O(l)
    // l ->length of the word 

    //Overall Trie storage:O(total inserted characters)
    TrieNode* root ;

    PrefixTree() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root ,string word , int index){
        // base case -> word fully traversed 
        if(index == word.length()){
            // Entire word has been inserted 
            root->isTerminal = true ;
            return ; 
        }
        int ind = word[index] - 'a' ; // which node to check 
        TrieNode* child ; 
        // Check if this letter already exists
        if( root->children[ind]!=NULL){
            child = root->children[ind] ;
        }else{
            // Create this node 
            child = new TrieNode(word[index]);
            root->children[ind] = child ;
        }

        // call for the next letter in the word 
        insertUtil( child ,word , index + 1);
    }
    
    void insert(string word) {
        insertUtil(root,word , 0);
    }
};


class Solution {
public:
       int solve (int index , int n ,string &s,vector<int> &dp , TrieNode * root){
        if(index == n ){
            return 0 ; 
        }

        if( dp[index] != -1 ) return dp[index];

        // At every index I have two choices . Either I take this char to form a word or I do not 

        // Skip 
        int res = 1 + solve(index + 1 , n , s , dp,root); // We add one becuase that is the 

        TrieNode* node = root ; 
        for(int i = index ; i < n ; i++){
            if( node->children[s[i] - 'a'] == NULL) break ;

            node = node->children[s[i] - 'a'];
            
            if(node->isTerminal){
                res = min ( res ,solve(i + 1 , n , s ,dp ,root));
            }
        
        }

        return dp[index] = res ;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // Same solution but instead of a set we use a PREFIX TREE or TRIE 

        PrefixTree* trie = new PrefixTree();

        for(string word : dictionary){
            trie->insert(word);
        }

        int n = s.size() ;

        int index = 0 ; 

        //What is the minimum number of extra characters from index onward?
        vector<int> dp(n,-1);

        return solve(index , n , s , dp , trie->root);
// Let:
//
// n = length of string s
// D = total number of characters across all dictionary words
//
// ------------------------------------------------------------
//
// Trie Construction:
//
// Each dictionary character is inserted exactly once.
//
// Time:  O(D)
// Space: O(D)
//
// ------------------------------------------------------------
//
// DP + Trie Search:
//
// dp[index] stores the minimum extra characters
// needed for suffix s[index...n-1].
//
// There are O(n) DP states.
//
// For each state, we walk forward through the Trie
// following characters of s.
//
// The walk can continue for at most (n-index) characters.
//
// Therefore:
//
// Work per state = O(n-index)
//
// Total DP work:
//
//     n + (n-1) + (n-2) + ... + 1
//
//   = O(n²)
//
// ------------------------------------------------------------
//
// Total Time Complexity:
//
// O(D + n²)
//
// ------------------------------------------------------------
//
// Space Complexity:
//
// Trie Storage:
// O(D)
//
// DP Array:
// O(n)
//
// Recursion Stack:
// O(n)
//
// Total Space:
//
// O(D + n)
    }
};