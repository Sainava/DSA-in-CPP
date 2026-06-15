/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [above[i], below[i]], and
a 2D integer array colConditions of size m where colConditions[i] = [left[i], right[i]].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number above[i] should appear in a row that is strictly above the row at which the number below[i] appears for all i from 0 to n - 1.
The number left[i] should appear in a column that is strictly left of the column at which the number right[i] appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

Example 1:

Input: k = 3, rowConditions = [[2,1],[1,3]], colConditions = [[3,1],[2,3]]

Output: [[2,0,0],[0,0,1],[0,3,0]]
Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]

Output: []
Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 10,000
rowConditions[i].length == colConditions[i].length == 2
1 <= above[i], below[i], left[i], right[i] <= k
above[i] != below[i]
left[i] != right[i]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    
    vector<int> topologicalSort(vector<vector<int>> &edges , int k){

        // Make adjacency list
        vector<vector<int>> adj(k+1);

        vector<int> indegree(k+1 , 0);

        for(int i = 0 ; i < edges.size() ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;
            adj[u].push_back(v);
        }

        queue<int> q ; 

        for(int i = 1 ; i <= k ; i++){
            if(indegree[i] == 0 ) q.push(i);
        }

        vector<int> res ; 

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto neighbour: adj[node]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        if(res.size() != k) return {} ; // No valid orderning 

        return res ; 
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // basically make a toplogical sorting for rows and cols 
        // That way we get the ordering we need 


        vector<int> rowOrder = topologicalSort(rowConditions , k);
        vector<int> colOrder = topologicalSort(colConditions , k);    

        if(rowOrder.empty() || colOrder.empty()) return {} ; 

        // Now we need constant lookup so lets make a hash map to get the exact col for that element 

        unordered_map<int,int> row; // number and its row 
        unordered_map<int,int> col; // number and its row 

        for(int i = 0 ; i < k ; i++ ){
            // Since there are k elements 

            row[rowOrder[i]] = i ; 
            col[colOrder[i]] = i ;
        }

        vector<vector<int>> ans(k , vector<int> (k ,0));


        // Now lets the place the number in its correct position 

        for(int i = 1 ; i <=k ; i++){
            
            ans[ row[i]][col[i]] = i ;
        }

        // Time Complexity:
        // Topological sort for rows  : O(k + R)
        // Topological sort for cols  : O(k + C)
        // Construct k x k matrix     : O(k²)
        //
        // Total:
        // O(k² + R + C)
        //
        // where:
        // k = number of values (1..k)
        // R = rowConditions.size()
        // C = colConditions.size()

        // Space Complexity:
        // Matrix                     : O(k²)
        // Graphs + indegree arrays   : O(R + C + k)
        //
        // Total:
        // O(k² + R + C)
        return ans ; 
    }
};