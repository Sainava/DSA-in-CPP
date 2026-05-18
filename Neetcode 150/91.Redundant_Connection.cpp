/*
You are given a connected undirected graph with n nodes labeled from 1 to n. Initially, it contained no cycles and consisted of n-1 edges.

We have now added one additional edge to the graph. The edge has two different vertices chosen from 1 to n, and was not an edge that previously existed in the graph.

The graph is represented as an array edges of length n where edges[i] = [ai, bi] represents an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the graph is still a connected non-cyclical graph. If there are multiple answers, return the edge that appears last in the input edges.

Example 1:



Input: edges = [[1,2],[1,3],[3,4],[2,4]]

Output: [2,4]
Example 2:



Input: edges = [[1,2],[1,3],[1,4],[3,4],[4,5]]

Output: [3,4]
Constraints:

n == edges.length
3 <= n <= 100
1 <= edges[i][0] < edges[i][1] <= edges.length
There are no repeated edges and no self-loops in the input.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void makeset(vector<int> &parent ,int n){
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i ;
        }
    }

    int findParent(int node ,vector<int> &parent ){
        if(parent[node]==node){
            return node ; 
        }else{
            return parent[node] = findParent(parent[node] , parent);
        }
    }

    void unionSet(int u ,int v ,vector<int> &parent ,vector<int> &rank ){
        int U = findParent(u,parent);
        int V = findParent(v,parent);

        if( rank[U]<rank[V]){
            // attach U subtree to V 
            parent[U] = V ;
        }else if(rank[V]<rank[U]){
            parent[V] = U;
        }
        else{
            parent[V] = U;
            rank[U]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Use disjoint set as it tells if two vertices already belong to same component 
        // so if we add another edge and they are already in same component 
        // A cycle is formed and it becomes a redundant edge 

        // read question same no of edges and nodes 
        int n = edges.size() ;

        vector<int> parent(n+1 , 0 ) ; // n+1 since nodes start from 1
        vector<int> rank(n+1 , 0 ) ;

        makeset(parent,n);

        // Here due to constraints of question , there will only be one redundant edge so size of ans is essentially one 
        vector<vector<int>> ans ; 

        for(int i = 0 ; i< n ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(findParent(u,parent)!= findParent(v,parent)){
                unionSet(u,v,parent ,rank);
            }else{
                ans.push_back({u,v});
                
            }
        }

        // TC :O(E (alpha)V ) which is amortized and considered constant for Union set 
        // SC:O(n) for parent and rank 
        return ans.back();
    }
};
