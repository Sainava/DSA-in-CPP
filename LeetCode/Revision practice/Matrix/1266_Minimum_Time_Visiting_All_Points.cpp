/*
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 

Example 1:


Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // Break this time into simpler steps 
        // The basic problem is 
        // for i = 0 to n-2:
        //     calculate time from points[i] to points[i+1]
        //     add to total 


        // General Strategy for Problems Like This

        // When you see 2D points:

        // Step 1 — Is order fixed?
        // Yes → simple accumulation problem
        // No → graph/search problem

        // Step 2 — Are there obstacles?
        // No → pure math
        // Yes → BFS/DFS/Dijkstra

        // Step 3 — Can you move diagonally?
        // Yes → think in terms of reducing both dx and dy

        // Ideally I should move diagonally 
        // For say x1,y1 to x2,y2
        // dx= | x2 - x1 | and dy = | y2 - y1 |
        // Key here is one diagonal move reduces both dx and dy by 1
        // SO say (1,1) to (3,4)
        // (1,1) to (2,2) to (3,3) , now no more dx left so we move up 

        // So move diagonally as Much as possible that is min(dx,dy) then the remaining can be left,right,up or down ( that is dy - dx)


        int ans = 0 ;

        for(int i = 0 ; i < points.size() - 1 ; i++){
            int dx = abs(points[i+1][0] - points[i][0]);
            int dy = abs(points[i+1][1] - points[i][1]);

            int diagonal = min(dx,dy);
            int rest = abs(dy - dx);

            ans += diagonal + rest ;
        }

        //TC:O(n) and SC:O(1)
        return ans;
    }
};