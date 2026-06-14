/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

You are given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [a[i], b[i]] indicates that there is an undirected edge between the two nodes a[i] and b[i] in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h)) are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Example 1:

Input: n = 5, edges = [[0,1],[3,1],[2,3],[4,1]]

Output: [3,1]
Explanation: As shown, the trees with root labels [3,1] are MHT's with height of 2.

Example 2:

Input: n = 4, edges = [[1,0],[2,0],[3,0]]

Output: [0]
Explanation: As shown, the tree with root label [0] is MHT with height of 1.

Constraints:

1 <= n <= 20,000
edges.length == n - 1
0 <= a[i], b[i] < n
a[i] != b[i]
All the pairs (a[i], b[i]) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // WATCH NEETCODE VIDEO 
        // MOST IMPORTANT OBSERVATION 
        // ROOT WILL BE NON LEAF AND THERE CAN ON;LY BE TWO NODES THAT SATISY MINHEIGHT 
        // Try making tree of 3 or 4 nodes and see why that is the case 

        // Edge case 
        if( n == 1) return {0} ; // Only one node 

        vector<vector<int>> adj(n); adj ;

        for(auto p : edges){
            int u = p[0]; 
            int v = p[1] ; 

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // We will start at the outer most nodes or leaves 

        // Count no of edges for every single node 
        vector<int> edgeCount(n) ; 

        queue<int> leaves  ; // We will push the leaf edges here 
        
        for(int node = 0 ; node < n ; node++){
            if( adj[node].size() == 1 ){
                leaves.push(node);
            }
            edgeCount[node] = adj[node].size() ; 
        }

        int remNodes = n ; // Remaining nodes 
        vector<int> ans ;

        while(!leaves.empty()){
            // We will go layer by layer 
            if( remNodes <= 2) {
                while(!leaves.empty()){
                    ans.push_back(leaves.front());
                    leaves.pop();
                }

                return ans ; 
            }
            int len = leaves.size() ; 

            for(int i = 0 ; i < len ; i++){
                int node = leaves.front() ; 
                leaves.pop() ; 
                remNodes-- ;

                for( auto neighbour :adj[node] ){
                    // Equivalent of removing node from the graph 
                    edgeCount[neighbour]-- ; 

                    if(edgeCount[neighbour] == 1){
                        // New leaf node 
                        leaves.push(neighbour) ; 
                    }
                }
            }
        }

        // Time Complexity: O(V + E)
        //
        // Each node becomes a leaf at most once.
        // Each edge is examined at most twice.
        //
        // Space Complexity: O(V + E)
        //
        // Adjacency list: O(V + E)
        // Queue: O(V)
        // Degree array: O(V)
        return {};
    }
};