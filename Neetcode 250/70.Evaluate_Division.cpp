/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

Example 1:

Input: equations = [["a","b"],["b","c"],["ab","bc"]], values = [4.0,1.0,3.25], queries = [["a","c"],["b","a"],["c","c"],["ab","a"],["d","d"]]

Output: [4.00000,0.25000,1.00000,-1.00000,-1.00000]
Example 2:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"]]

Output: [0.50000,2.00000]
Constraints:

1 <= equations.length, queries.length <= 20
equations[i].length == queries[i].length == 2
1 <= Ai.length, Bi.length, Cj.length, Dj.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    double bfs(string start , string target , unordered_map<string,vector<pair<string,double>>> &adj){
        if(!adj.count(start) || !adj.count(target)) return -1;

        queue<pair<string,double>> q ; 
        
        q.push({start,1.0});
        unordered_map<string,bool> visited;
        visited[start] = true ; 

        while(!q.empty()){
            auto top = q.front() ; 
            q.pop() ;

            string node = top.first;
            double div = top.second ;

            if( node == target) return div ; 

            for(auto it  : adj[node]){
                string neighbour = it.first ; 
                double d = it.second; 

                if(!visited[neighbour]){
                    q.push({neighbour , div*d});
                    visited[neighbour] = true ;
                }
                
            }
        }

        return -1 ; 
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // WATCH NEETCODE's VIDEO 
        // This question is not very intuitive but basically we can use a graph to solve this 
        // We make edges a->b basicallu from numerator to denominator so a/b
        // If we were given a/b and we needed to find b/c -> We would multiply the two , b gets cancelled and we get a/c
        // Now think in terms of edges 
        // a->b for a/ b and b-> c for b/c so graph has a->b->c . If the edges had their value 
        // so a->b edge has value (say a/b = 2) , likwise (b/c= 3). 
        // Then of we travel from a to c along edges a->b-> c we get 2*3 which gives us 6 which is the required answer 
        // Now a/c is not same as c/a but it is inverse so if we have doubly ended edges that are inverse of each othe it works 
        // Eg a->b = 2 ( a/b = 2) and b->a = 1/2 (b/a = 1/2) so it works
        //That is intuition behind graphs 

        int E = equations.size() ; 

        unordered_map<string,vector<pair<string,double>>> adj ; 

        //TC:O(E)
        for(int i = 0 ; i < E ; i++){
            string u = equations[i][0];
            string v = equations[i][1];

            double wt = values[i];

            adj[u].push_back({v,wt});

            adj[v].push_back({u , 1/wt});
        }

        // For each query we do bfs to see if we can reach 
        // BFS because we will reach in shortest path and it can help with cycle detection 
        vector<double> ans ;
        //TC:O(q*(V+E))
        for(int i = 0 ; i < queries.size() ; i++){
            string start = queries[i][0] ; 
            string target = queries[i][1];

            

            ans.push_back(bfs(start , target , adj ));
        }

        //TC:O(q*(V+E)) and SC:O(V+E)
        return ans; 
    }
};