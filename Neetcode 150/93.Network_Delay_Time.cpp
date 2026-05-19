/*
You are given a network of n directed nodes, labeled from 1 to n. You are also given times, a list of directed edges where times[i] = (ui, vi, ti).

ui is the source node (an integer from 1 to n)
vi is the target node (an integer from 1 to n)
ti is the time it takes for a signal to travel from the source to the target node (an integer greater than or equal to 0).
You are also given an integer k, representing the node that we will send a signal from.

Return the minimum time it takes for all of the n nodes to receive the signal. If it is impossible for all the nodes to receive the signal, return -1 instead.

Example 1:



Input: times = [[1,2,1],[2,3,1],[1,4,4],[3,4,1]], n = 4, k = 1

Output: 3
Example 2:

Input: times = [[1,2,1],[2,3,1]], n = 3, k = 2

Output: -1
Constraints:

1 <= k <= n <= 100
1 <= times.length <= 1000
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // This is shortest path in weighted graph .
        // No info says that it is a DAG 
        // So we Use Dijkstra's Algorithm 

        // First make the adjacency list 

        //SC:O(V+E)
        unordered_map<int , vector<pair<int,int>>> adj ;

        //TC:O(E)
        for(auto p : times){
            int u = p[0] ;
            int v = p[1] ; 
            int wt = p[2] ;

            adj[u].push_back({v,wt});
        }

        //SC:O(V) for both 
        vector<int> key(n+1 , INT_MAX);
        set<pair<int,int>> st ; // distance , node 

        st.insert({0 , k});
        key[k] = 0 ; 


        //SC:O(V+E) logV as size of set is V and all will be processed 
        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());

            int nodeKey = top.first;
            int node = top.second ;

            for(auto p : adj[node]){
                int neighbour = p.first ;
                int distance = p.second ; // here time between node and neighbour 

                if( nodeKey + distance < key[neighbour]){
                    if(st.count({key[neighbour] , neighbour})){
                        // We need to update its value so erase 
                        // We delete the older key value before adding another 
                        st.erase({key[neighbour] , neighbour});
                    }
                    key[neighbour] = nodeKey + distance ;
                    st.insert({key[neighbour] , neighbour});
                }
                
            }
        }

        // We need to find the max valu from key now as that is the max time we need 

        int maxTime = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(key[i]==INT_MAX) {
                // unreachable so 
                return -1 ;
            }
            maxTime =max(maxTime , key[i]);
        }

        //TC:O(V+E)logV and SC:O(V+E)
        return maxTime ;
    }
};
