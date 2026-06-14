/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

Example 1:

Input: numCourses = 4, prerequisites = [[1,0],[2,1],[3,2]], queries = [[0,1],[3,1]]

Output: [false,true]
Example 2:

Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1]]

Output: [false]
Constraints:

2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= numCourses - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 10,000
0 <= ui, vi <= numCourses - 1
ui != vi
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<int> indegree(numCourses , 0);

        unordered_map<int,vector<int>> adj ; 

        for(auto p:prerequisites){
            int u = p[0];
            int v = p[1];

            indegree[v]++;

            adj[u].push_back(v);
        }

        queue<int> q ; 

        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i]==0) q.push(i);
        }

        // IMPORTANT 
        vector<unordered_set<int>> prereq(numCourses);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for( auto neighbour : adj[node]){
                // Continue kahn -> The idea is if we follow kahn we can build prereq correctly 
                // Because for u->v we need to have processed u before and kahn's allow that 
                indegree[neighbour]--;
                if(indegree[neighbour] == 0 ) q.push(neighbour) ; 

                // The way we made the graph 
                // node is a prerequsite for neighbour so we need to take node before taking neighbour 
                // But prereq[node] contains all courses we need to take before taking node 
                // So we also need to take these courses before we can take neighbour 
                prereq[neighbour].insert(node);

                for(int p : prereq[node]){
                    prereq[neighbour].insert(p);
                }
            }

        }

        // Now we can answer the queries 
        vector<bool> ans ; 

        for(int i = 0 ; i < queries.size() ; i++){

            int u = queries[i][0];
            int v = queries[i][1];

            // We need to answer if u is a direct or indirect prerequisite of v
            ans.push_back( prereq[v].count(u));
        }

        return ans ; 

        // Time Complexity:
// O(E * V + Q)
//
// E = number of prerequisite relations
// V = number of courses
// Q = number of queries
//
// For each edge u -> v, we propagate all prerequisites
// of u into v. A prerequisite set can contain up to V
// courses, giving O(E * V) total work.
//
// Query answering is O(1) average per query.

// Space Complexity:
// O(V² + E)
//
// The prerequisite sets may collectively store
// O(V²) prerequisite relationships in the worst case.
// The adjacency list requires O(E) space.
       
    }
};