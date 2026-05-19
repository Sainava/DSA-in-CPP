/*
You are given a list of flight tickets tickets where tickets[i] = [from_i, to_i] represent the source airport and the destination airport.

Each from_i and to_i consists of three uppercase English letters.

Reconstruct the itinerary in order and return it.

All of the tickets belong to someone who originally departed from "JFK". Your objective is to reconstruct the flight path that this person took, assuming each ticket was used exactly once.

If there are multiple valid flight paths, return the lexicographically smallest one.

For example, the itinerary ["JFK", "SEA"] has a smaller lexical order than ["JFK", "SFO"].
You may assume all the tickets form at least one valid flight path.

Example 1:



Input: tickets = [["BUF","HOU"],["HOU","SEA"],["JFK","BUF"]]

Output: ["JFK","BUF","HOU","SEA"]
Example 2:



Input: tickets = [["HOU","JFK"],["SEA","JFK"],["JFK","SEA"],["JFK","HOU"]]

Output: ["JFK","HOU","JFK","SEA","JFK"]
Explanation: Another possible reconstruction is ["JFK","SEA","JFK","HOU","JFK"] but it is lexicographically larger.

Constraints:

1 <= tickets.length <= 300
from_i != to_i
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(string node ,unordered_map<string,multiset<string>> &adj ,vector<string> &ans){
        
        //  We visit all edges 

        while(adj[node].size()!=0){
            auto &st = adj[node];
            // call dfs iteratively for all edges 
            string neighbour = *(st.begin()); // This keeps care of lexicographic order
            st.erase(st.begin()) ; // Most imprtant : once traversed  , remove the edge 

            dfs(neighbour , adj , ans);
        }

        // Once all edges visited -> Add to answer 
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Each ticket contains a {source , destination} 
        // Basically each ticket is a edge and source and destionation are nodes
        // We need to use each ticket means we need to use or traverse each edge 
        // Hamiltonian = Traverse each vertex 
        // Eulerian = Traverse each edge
        // This is a find Eulerian path question starting from JFK
        // This uses the heilholzer's Algorithm 

        // Lets try to make an adjacency list 
        // from source  to all possible IMMEDIATE destinations

        // Step 1 : In this algorithm is to verify a eulerian path exists
        // Condition : 
            // (a) Atmost one node has edge(outgoing) - edge(incoming) == 1 -> This becomes starting node 
            // (b) Atmost one node has edge(ingoing) - edge(outcoming) == 1 -> This becomes ending node 
            // For all other nodes edge(ingoing) = edge(outcoming) 
        // Step 2 : Is to find out starting and ending node 

        // In this question step 1 and step are 2 not needed 

        // We need to outgoing edge adjacency list for each node 
        // Which is a basic adjacency list

        // We need to sort edges based on destination as answer needs lexicographic
        // This algo also needs removing edges so set is good option
        // The issue with set is it collapses duplicates to one but in questions like these src to dest may have more than one edge 
        // Two tickets with same endpoints are still two different tickets 
        // So we use multiset which is a set that allows duplicates 

        //SC:O(E) as stores all edges 
        unordered_map<string,multiset<string>>  adj ; 

        //TC:O(ElogE) as multiset operations are logE 
        for(auto &p : tickets){
            string u = p[0];
            string v = p[1];

            adj[u].insert(v);
        }

        // Now we do modified dfs
        vector<string> ans ;

        // Traverses all edges and delete so 

        // TC:O(ElogE)
        dfs("JFK" ,adj ,ans );

        // TC:(O(ans.size())) = approx (E + 1)
        reverse(ans.begin() , ans.end());

        //TC:O(ElogE + E) and SC:O(E)
        return ans ; 
    }
};
