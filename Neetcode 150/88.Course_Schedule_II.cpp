/*
You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.

Return a valid ordering of courses you can take to finish all courses. If there are many valid answers, return any of them. If it's not possible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 3, prerequisites = [[1,0]]

Output: [0,1,2]
Explanation: We must ensure that course 0 is taken before course 1.

Example 2:

Input: numCourses = 3, prerequisites = [[0,1],[1,2],[2,0]]

Output: []
Explanation: It's impossible to finish all courses.

Constraints:

1 <= numCourses <= 1000
0 <= prerequisites.length <= 1000
All prerequisite pairs are unique.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(check.size()==numCourses){
            return check ;
        }else{
            return {};
        }


    }
};
