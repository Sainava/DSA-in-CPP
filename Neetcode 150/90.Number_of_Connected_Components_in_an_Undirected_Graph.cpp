/*
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [aᵢ, bᵢ] indicates that there is an edge between aᵢ and bᵢ in the graph.

Return the number of connected components in the graph.

Example 1:



Input:
n = 5, edges = [[0,1],[1,2],[3,4]]

Output: 2
Example 2:



Input:
n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]

Output: 1
Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= aᵢ <= bᵢ < n
aᵢ != bᵢ
There are no repeated edges.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj ,vector<bool> &visited , int node){
        visited[node] = true ; 

        for(int neighbour : adj[node] ){
            if(!visited[neighbour]){
                dfs(adj,visited,neighbour);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj ;

        for(auto p:edges){
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);        

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,visited,i);
            }
        }

        //TC:O(V+E) and SC:O(V+E)
        return cnt ;
    }
};
