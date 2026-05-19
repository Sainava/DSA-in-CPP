/*
You are given a 2-D integer array points, where points[i] = [xi, yi]. Each points[i] represents a distinct point on a 2-D plane.

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between the two points, i.e. |xi - xj| + |yi - yj|.

Return the minimum cost to connect all points together, such that there exists exactly one path between each pair of points.

Example 1:



Input: points = [[0,0],[2,2],[3,3],[2,4],[4,2]]

Output: 10
Constraints:

1 <= points.length <= 1000
-1,000,000 <= xi, yi <= 1,000,000
All pairs (xi, yi) are distinct.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

   void makeset(vector<int> &parent , int n){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i ;
    }
   }

   int findParent(int node , vector<int> &parent){
    if(parent[node]==node){
        return node ;
    }else{
        return parent[node] = findParent(parent[node],parent);
    }
   }

   void unionSet(int u , int v ,vector<int> &parent,vector<int> &rank ){
        int U = findParent(u,parent);
        int V = findParent(v,parent);

        if(rank[U]<rank[V]){
            parent[U] = V;
        } else if(rank[V]<rank[U]){
            parent[V] = U;
        }else{
            parent[V] = U;
            rank[U]++;
        }
   }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //Basically they want mst 
        int n = points.size() ; // No of vertices 
        // We treat points as indices of the points vector
        // Since between every pair of vertices :No of edges : n(n-1)/2 = approx n^2
        // We need to make the edges firs t
        vector<vector<int>> edges ; // { distance , i , j}

        // Need this for all pair of points 
        //TC:O(n^2)
        for(int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                int xi = points[i][0];
                int yi = points[i][1];

                int xj = points[j][0];
                int yj = points[j][1];

                int dist = abs(xi - xj) + abs(yi - yj) ; 

                edges.push_back({dist , i , j});
            }
        }

        // Now that we have edges we do kruskal 
        //TC:O(n^2logn^2) = TC:O(n^2*2logn) ( log property ) = TC:O(n^2logn)
        sort( edges.begin() , edges.end());

        vector<int> parent(n , -1 );
        vector<int> rank(n , 0);

        makeset(parent,n);

        // Since between every pair of vertices :No of edges : n(n-1)/2
        int minMST = 0 ;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][1];
            int v = edges[i][2];

            if( findParent(u,parent)!= findParent(v,parent)){
                unionSet(u,v,parent,rank);
                minMST += edges[i][0];
            }
        }

        // TC:O(n^2logn) and SC:O(n^2)
        return minMST;

    }
};
