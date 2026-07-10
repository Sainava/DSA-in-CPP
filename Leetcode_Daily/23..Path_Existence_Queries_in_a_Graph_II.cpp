// 10 July 2026

// 3534. Path Existence Queries in a Graph II

/* 
You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

You are also given an integer array nums of length n and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.

Return an array answer, where answer[i] is the result of the ith query.

Note: The edges between the nodes are unweighted.

 

Example 1:

Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]

Output: [1,1]

Explanation:

The resulting graph is:



Query	Shortest Path	Minimum Distance
[0, 3]	0 → 3	1
[2, 4]	2 → 4	1
Thus, the output is [1, 1].

Example 2:

Input: n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]

Output: [1,2,-1,1]

Explanation:

The resulting graph is:



Query	Shortest Path	Minimum Distance
[0, 1]	0 → 1	1
[0, 2]	0 → 1 → 2	2
[2, 3]	None	-1
[4, 3]	3 → 4	1
Thus, the output is [1, 2, -1, 1].

Example 3:

Input: n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]

Output: [0,-1,-1]

Explanation:

There are no edges between any two nodes because:

Nodes 0 and 1: |nums[0] - nums[1]| = |3 - 6| = 3 > 1
Nodes 0 and 2: |nums[0] - nums[2]| = |3 - 1| = 2 > 1
Nodes 1 and 2: |nums[1] - nums[2]| = |6 - 1| = 5 > 1
Thus, no node can reach any other node, and the output is [0, -1, -1].

 

Constraints:

1 <= n == nums.length <= 105
0 <= nums[i] <= 105
0 <= maxDiff <= 105
1 <= queries.length <= 105
queries[i] == [ui, vi]
0 <= ui, vi < n
 
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        // (value, original index)
        vector<pair<int,int>> ord;
        for(int i = 0; i < n; i++)
            ord.push_back({nums[i], i});

        sort(ord.begin(), ord.end());

        // position of each original node in sorted order
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[ord[i].second] = i;

        //--------------------------------------------------------
        // next[i]:
        // Furthest position reachable in ONE step from i.
        //--------------------------------------------------------

        vector<int> nxt(n);

        int r = 0;
        for(int l = 0; l < n; l++){

            while(r + 1 < n &&
                  ord[r + 1].first - ord[l].first <= maxDiff)
                r++;

            nxt[l] = r;
        }

        //--------------------------------------------------------
        // Binary Lifting
        //--------------------------------------------------------

        const int LOG = 18;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++){

            for(int i = 0; i < n; i++){

                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        //--------------------------------------------------------
        // Answer Queries
        //--------------------------------------------------------

        vector<int> ans;

        for(auto &q : queries){

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v)
                swap(u,v);

            if(u == v){
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int dist = 0;

            for(int k = LOG-1; k >= 0; k--){

                if(up[k][cur] < v){

                    cur = up[k][cur];
                    dist += (1<<k);
                }
            }

            if(up[0][cur] < v)
                ans.push_back(-1);
            else
                ans.push_back(dist + 1);
        }

        return ans;
        // TC:
        // Sorting                : O(n log n)
        // Two pointers           : O(n)
        // Binary lifting table   : O(n log n)
        // Each query             : O(log n)
        //
        // Overall:
        // O((n + q) log n)
        //
        // SC:
        // O(n log n)
    }
};