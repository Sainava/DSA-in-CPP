/*
You are given an 2-D array points where points[i] = [xi, yi] represents the coordinates of a point on an X-Y axis plane. You are also given an integer k.

Return the k closest points to the origin (0, 0).

The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).

You may return the answer in any order.

Example 1:



Input: points = [[0,2],[2,2]], k = 1

Output: [[0,2]]
Explanation : The distance between (0, 2) and the origin (0, 0) is 2. The distance between (2, 2) and the origin is sqrt(2^2 + 2^2) = 2.82842. So the closest point to the origin is (0, 2).

Example 2:

Input: points = [[0,2],[2,0],[2,2]], k = 2

Output: [[0,2],[2,0]]
Explanation: The output [2,0],[0,2] would also be accepted.

Constraints:

1 <= k <= points.length <= 1000
-100 <= points[i][0], points[i][1] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //if I use a max heap on distance . And keep size k Then at all times i have the k closesr elements , from (0,0) and if size increases the (k+1) farthest element is deleted
        // pq.top() cotains the k closest element , if size increases , the k+1 closest element is deleted

        //SC:O(k)
        priority_queue<vector<int>> pq ;  // { distance , x , y} 

        //TC:O(nlogk)
        for(int i = 0 ; i < points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y; // need not do sqrt if this is greater sqrt will also be greater

            pq.push({dist,x,y});

            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> ans ;

        // At worst //TC:O(nlogk)
        while(!pq.empty()){
            ans.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }

        //TC:O(nlogk) and SC:O(k)
        return ans ;
    }
};
