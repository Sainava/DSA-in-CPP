/*
You are given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [a[i], b[i], weight[i]] represents a bidirectional and weighted edge between nodes a[i] and b[i]. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:

Input: n = 4, edges = [[0,3,2],[0,2,5],[1,2,4]]

Output: [[0,2,1],[]]
Example 2:

Input: n = 5, edges = [[0,3,2],[0,4,2],[1,3,2],[3,4,2],[2,3,1],[1,2,3],[0,1,1]]

Output: [[4,6],[0,1,2,3]]
Constraints:

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= a[i] < b[i] < n
1 <= weight[i] <= 1000
All pairs (a[i], b[i]) are distinct.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionSet(int u , int v){

        u = findParent(u);
        v = findParent(v);

        if(u == v) return;

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution {
public:

    static bool cmp(const vector<int> &a , const vector<int> &b){
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges
    ) {

        // We need the original indices of the edges when we return so we append it

        for(int i = 0 ; i < edges.size() ; i++){
            edges[i].push_back(i); // {u , v , wt , original_index}
        }

        // We will use kruskal so let us sort the edges
        sort(edges.begin(), edges.end(), cmp);

        int mstWeight = 0;

        {
            DSU dsu(n);

            // Find the mst
            for(int i = 0 ; i < edges.size() ; i++){

                int u = edges[i][0];
                int v = edges[i][1];

                if(dsu.findParent(u) != dsu.findParent(v)){
                    dsu.unionSet(u,v);
                    mstWeight += edges[i][2];
                }
            }
        }

        vector<int> critical;
        vector<int> pseudo;

        // Brute force
        // Try to find the mst again but this time one by one force ourselves
        // to not include that edge(imagine we delete the edge from the graph)
        // If in doing so it increases the mstWeight -> It is a critical edge

        for(int index = 0 ; index < edges.size() ; index++){

            // ----------------------------------------------------
            // CRITICAL CHECK
            // ----------------------------------------------------

            DSU dsu(n);

            int weight = 0;
            int edgesUsed = 0;

            // Find the mst without current edge
            for(int i = 0 ; i < edges.size() ; i++){

                if(i == index) continue;

                int u = edges[i][0];
                int v = edges[i][1];

                if(dsu.findParent(u) != dsu.findParent(v)){
                    dsu.unionSet(u,v);
                    weight += edges[i][2];
                    edgesUsed++;
                }
            }

            // See if this was a critical edge
            // If MST cannot be formed OR weight increases

            if(edgesUsed != n - 1 || weight > mstWeight){
                critical.push_back(edges[index][3]); // Push original index
                continue; // Critical cannot be pseudo-critical
            }

            // ----------------------------------------------------
            // PSEUDO CRITICAL CHECK
            // ----------------------------------------------------

            DSU dsu2(n);

            weight = edges[index][2];
            edgesUsed = 1;

            // Forcibly include this edge

            dsu2.unionSet(edges[index][0], edges[index][1]);

            // Find the mst

            for(int i = 0 ; i < edges.size() ; i++){

                if(i == index) continue; // Already included 

                int u = edges[i][0];
                int v = edges[i][1];

                if(dsu2.findParent(u) != dsu2.findParent(v)){
                    dsu2.unionSet(u,v);
                    weight += edges[i][2];
                    edgesUsed++;
                }
            }

            if(edgesUsed == n - 1 && weight == mstWeight){
                pseudo.push_back(edges[index][3]);
            }
        }

        vector<vector<int>> ans;

        ans.push_back(critical);
        ans.push_back(pseudo);

        return ans;

        // Time Complexity:
        //
        // Sorting edges:
        // O(m log m)
        //
        // Original MST:
        // O(m * α(n))
        //
        // For each edge:
        //   1. Rebuild MST excluding it  -> O(m * α(n))
        //   2. Rebuild MST including it  -> O(m * α(n))
        //
        // Done for all m edges:
        //
        // O(m * (m * α(n)))
        // = O(m² * α(n))
        //
        // Overall:
        // O(m² * α(n))
        // ≈ O(m²)
        //
        // where:
        // n = number of vertices
        // m = number of edges




        // Space Complexity:
        //
        // edges array            -> O(m)
        // DSU (parent + rank)    -> O(n)
        // critical + pseudo      -> O(m)
        //
        // Total:
        // O(m + n)
        //
        // where:
        // n = number of vertices
        // m = number of edges
    }
};