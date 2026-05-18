/*
You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.

The pair [0, 1], indicates that must take course 1 before taking course 0.

There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.

Return true if it is possible to finish all courses, otherwise return false.

Example 1:

Input: numCourses = 2, prerequisites = [[0,1]]

Output: true
Explanation: First take course 1 (no prerequisites) and then take course 0.

Example 2:

Input: numCourses = 2, prerequisites = [[0,1],[1,0]]

Output: false
Explanation: In order to take course 1 you must take course 0, and to take course 0 you must take course 1. So it is impossible.

Constraints:

1 <= numCourses <= 1000
0 <= prerequisites.length <= 1000
prerequisites[i].length == 2
0 <= a[i], b[i] < numCourses
All prerequisite pairs are unique.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // We basically use Kahn's Algorithm (for topological sort )here

        //SC:O(V+E)
        unordered_map<int,vector<int>> adj ;

        //SC:O(V)
        vector<int> indegree(numCourses , 0);

        //TC:O(E)
        for(auto p : prerequisites){
            int u = p[1];
            int v = p[0];

            indegree[v]++;
            adj[u].push_back(v);
        }

        //SC:O(V)
        queue<int> q;

        // TC:O(V)
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i]==0) q.push(i);
        }

        //SC:O(V)
        vector<int> check ;

        //TC:O(V)
        while(!q.empty()){
            int course = q.front();
            q.pop();

            check.push_back(course);

            for(int neighbour:adj[course]){
                indegree[neighbour]--;

                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }


        //TC:O(V+E) and SC:O(V+E)
        return check.size()==numCourses;


    }
};
