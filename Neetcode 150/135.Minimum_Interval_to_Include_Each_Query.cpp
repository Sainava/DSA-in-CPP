/*
You are given a 2D integer array intervals, where intervals[i] = [left_i, right_i] represents the ith interval starting at left_i and ending at right_i (inclusive).

You are also given an integer array of query points queries. The result of query[j] is the length of the shortest interval i such that left_i <= queries[j] <= right_i. If no such interval exists, the result of this query is -1.

Return an array output where output[j] is the result of query[j].

Note: The length of an interval is calculated as right_i - left_i + 1.

Example 1:

Input: intervals = [[1,3],[2,3],[3,7],[6,6]], queries = [2,3,1,7,6,8]

Output: [2,2,3,5,1,-1]
Explanation:

Query = 2: The interval [2,3] is the smallest one containing 2, it's length is 2.
Query = 3: The interval [2,3] is the smallest one containing 3, it's length is 2.
Query = 1: The interval [1,3] is the smallest one containing 1, it's length is 3.
Query = 7: The interval [3,7] is the smallest one containing 7, it's length is 5.
Query = 6: The interval [6,6] is the smallest one containing 6, it's length is 1.
Query = 8: There is no interval containing 8.
Constraints:

1 <= intervals.length <= 1000
1 <= queries.length <= 1000
1 <= left_i <= right_i <= 10000
1 <= queries[j] <= 10000
*/
# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Watch neetcode's video -> This question has edge cases but is doable once understood

        int n = intervals.size() ;
        int m = queries.size() ; 

        // We need to sort indices but we also need to keep track of original indices 
        vector<pair<int,int>> q ; // {query , original indesx }

        for(int i = 0 ; i < m ; i++){
            q.push_back({queries[i] , i});
        }

        sort(intervals.begin() , intervals.end()) ;
        sort(q.begin() , q.end()) ;

        priority_queue<
            pair<int,int> ,
            vector<pair<int,int>> ,
            greater<pair<int,int>>
        > pq ; // stores size of interval and end pos of interval

        vector<int>  ans(m ,-1);

        int i = 0 ; 

        for(int j = 0 ; j < m ; j++){
            
            // Insert all intervals that may be an answer
            while( i < n && intervals[i][0]  <= q[j].first){
                int len = intervals[i][1] - intervals[i][0] + 1 ;
                pq.push( {len , intervals[i][1]});
                i++;
            }

            // Now delete all the intervals who end before this query 
            // We can pop them out as we sorted the query so if this interval ended before this query it is not valid for the next query too
            while ( !pq.empty() && pq.top().second < q[j].first){
                pq.pop() ;
            }

            // Now only valid intervals for this query remain in the pq 
            if(!pq.empty()){
                auto top = pq.top() ;
                ans[q[j].second] = top.first ; 
            }
           
        }

        //TC:O(nlogn + mlogm) for sorting 
        // TCO(nlogn) as each interval pushed only once and popped atmost once 
        //TC:O(m) for traversal 
        //SC:O(m)
        return ans ;
    }
};
