/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

Output:
true
Example 2:

Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

Output:
false
Note:

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
Constraints:

1 <= n <= 100
0 <= edges.length <= n * (n - 1) / 2
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj ,vector<bool> &visited , int node , int parent){
        
        visited[node] = true ; 
        bool isTree = true ;

        for(int neighbour : adj[node]){
            if (!visited[neighbour]){
                isTree = dfs(adj , visited , neighbour, node);
            }else{
                //already visited 
                if( parent != neighbour) return false ;
            }

            if(isTree == false ) return false ;
        }

        return isTree ;

    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // An acyclic graph is a tree , so we need to check if cycles exist 
        // Undirected cycle check 
        // A tree is acyclic and connected 

        unordered_map<int,vector<int>> adj ;

        for(auto p:edges){
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        // Run dfs for 0 
        bool isTree = dfs(adj , visited , 0 , -1) ;

        // Check if any is unvisited , if any components exist or we can say not connected graph ,so not a tree 
        for(int i = 0 ; i < n ; i++){
            if(visited[i]==false ) return false ;
        }

        //TC:O(V+E) and SC:O(V+E) for adj and SC:O(V) for recusrion stack and visited
        return isTree ; // or return isTree same 
    }
};
