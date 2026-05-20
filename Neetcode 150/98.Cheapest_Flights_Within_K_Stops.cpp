/*
There are n airports, labeled from 0 to n - 1, which are connected by some flights. You are given an array flights where flights[i] = [from_i, to_i, price_i] represents a one-way flight from airport from_i to airport to_i with cost price_i. You may assume there are no duplicate flights and no flights from an airport to itself.

You are also given three integers src, dst, and k where:

src is the starting airport
dst is the destination airport
src != dst
k is the maximum number of stops you can make (not including src and dst)
Return the cheapest price from src to dst with at most k stops, or return -1 if it is impossible.

Example 1:



Input: n = 4, flights = [[0,1,200],[1,2,100],[1,3,300],[2,3,100]], src = 0, dst = 3, k = 1

Output: 500
Explanation:
The optimal path with at most 1 stop from airport 0 to 3 is shown in red, with total cost 200 + 300 = 500.
Note that the path [0 -> 1 -> 2 -> 3] costs only 400, and thus is cheaper, but it requires 2 stops, which is more than k.

Example 2:



Input: n = 3, flights = [[1,0,100],[1,2,200],[0,2,100]], src = 1, dst = 2, k = 1

Output: 200
Explanation:
The optimal path with at most 1 stop from airport 1 to 2 is shown in red and has cost 200.

Constraints:

1 <= n <= 100
fromi != toi
1 <= pricei <= 1000
0 <= src, dst, k < n
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Here we need the minimum cost( shortest distance equivalent ) ,      
        // BUT we also need to keep track of stops as atmost k stops 
        // stops are the nodes beetween src and dst 
        // We allow k+1 stops ( k+1 only when it reaches the dest so we consider the k +1 stop to be the destination)

        // Do dijkstra but keep stops as the major constraint 

        unordered_map<int,vector<pair<int,int>>> adj ; 

        for(auto p : flights ){
            int u = p[0];
            int v = p[1];
            int wt = p[2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n , INT_MAX);

        dist[src] = 0 ; 

        // We will use a queue here and not priority queue as we push stops in descending order so we do not actually need sorting 
        queue< vector<int> > q ; // stops , node , dist 

        q.push( {0 , src , dist[src] });

        // We do not stop when we reach dest, as there may be an answer where greater stops but cheaper 
        while( !q.empty()){
            auto top = q.front();
            q.pop();

            int stops = top[0];
            int node = top[1];
            int key = top[2];

            if( stops == k+1 ) continue ; // As cannot take anymore 

            for(auto p : adj[node]){
                int neighbour = p.first ; 
                int distance = p.second ; 

                if( key + distance < dist[neighbour]){

                    if( stops + 1 <= k+1 ){
                        dist[neighbour] = key + distance ; 
                        q.push({stops+1 , neighbour ,dist[neighbour]});
                    }
                    
                }
            }
        }

        if( dist[dst] == INT_MAX) return -1 ;

        //TC:O(E*k) as dijkstra's takes O(E) as E dominates V but here each V can be added k times 
        // That would mean all edges can be traversed k times 
        // SO TC:O(E*k)

        // SC:O(V+E) for adjacency list 
        // SC:O(V*k) for the queue 
        // So total SC:O(V+E+ V*k) = S:O( E + V*k)
        return dist[dst];
    }
};
