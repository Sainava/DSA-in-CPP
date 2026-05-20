/*
There is a foreign language which uses the latin alphabet, but the order among letters is not "a", "b", "c" ... "z" as in English.

You receive a list of non-empty strings words from the dictionary, where the words are sorted lexicographically based on the rules of this new language.

Derive the order of letters in this language. If the order is invalid, return an empty string. If there are multiple valid order of letters, return any of them.

A string a is lexicographically smaller than a string b if either of the following is true:

The first letter where they differ is smaller in a than in b.
a is a prefix of b and a.length < b.length.
Example 1:

Input: ["z","o"]

Output: "zo"
Explanation:
From "z" and "o", we know 'z' < 'o', so return "zo".

Example 2:

Input: ["hrn","hrf","er","enn","rfnn"]

Output: "hernf"
Explanation:

from "hrn" and "hrf", we know 'n' < 'f'
from "hrf" and "er", we know 'h' < 'e'
from "er" and "enn", we know 'r' < 'n'
from "enn" and "rfnn" we know 'e' < 'r'
so one possible solution is "hernf"
Constraints:

The input words will contain characters only from lowercase 'a' to 'z'.
1 <= words.length <= 100
1 <= words[i].length <= 100
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs( int node ,vector<bool> &visited,unordered_map<int,vector<int>> &adj ,stack<int> &st ){
        visited[node] = true ; 

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, visited , adj ,st) ;
            }
        }

        st.push(node);
    }
    string foreignDictionary(vector<string>& words) {
        // We need to find oredering of letters 
        // If we treat all letters as nodes of a graph. We essentially need to find the topological sort 
        int n = words.size();
        // First build the adjacency list from the words given 
        // We treat a as 0 ; b as 1 ; c as 2 ; d as 3 and so on till z as 25

        unordered_map<int , unordered_set<int>> adj; // set to avoid non duplicate insertions 
        vector<bool> mask(26 , false); // To keep track of what letters appear in our question 
        vector<int> indegree( 26 , 0);

        //TC:O(C) where C is total characters appearing in word 
        for( string word : words){
            for( char ch : word){
                if( !mask[ch-'a']){
                    mask[ch-'a'] = true ;
                }
            }
        }

        // Basically compare until different words are found 
        // Worst case : TC:O(C)
        for(int i = 0 ; i < n-1 ; i++){
            // We compare pair wise 
            string &s1 = words[i];
            string &s2 = words[i+1];

            // Now compare for the first point of difference 
            int len = min ( s1.size() , s2.size());

            bool foundDifference = false ;         

            for(int j = 0 ; j < len ; j++){
                if( s1[j]!=s2[j]){
                    foundDifference = true ; 
                    // s1 comes before s2 in words so s1[j] smaller than s2[j] so edge from s1[j] to s2[j]
                    auto p = adj[s1[j]-'a'].insert(s2[j] - 'a');// insertion returns{iterator,true } if it is not duplicate
                    if(p.second){
                        indegree[s2[j] - 'a']++;  
                    }
                    
                    break ;
                }

                if( foundDifference == false && s1.size() > s2.size()){
                    // invalid input 
                    return "" ; 
                }
            }
            // If one string is prefix and shorter than the other , there is no useful information we can get. from there so ignore       
        }

        // We do topological sort using kahn's algorithm 
        //TC:O(U + E) where U nodes and E edges  and U is unique characters 
        // Since less than U <= 26 effectively constant 
        queue<int> q ;

        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0 && mask[i]==true){
                q.push(i);
            }
        }
        
        string ans = "";
        while( ! q.empty()){
            int node = q.front();
            q.pop();

            char ch = node + 'a';
            ans.push_back(ch);

            for(auto neighbour: adj[node]){
                indegree[neighbour]--;

                if( indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        // Optional check if it is even valid 
        int cnt = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if ( mask[i]) cnt ++ ; 
        }

        if(ans.size()!=cnt) return "" ; // cycle exists 

        // TC:O(C) 
        // SC:O(1) as each data structure stores unique lowercase letters 
        return ans ; 

    }
};
