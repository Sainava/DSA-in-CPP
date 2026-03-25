/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


class Solution {
public:
    static bool cmp( vector<int> interval1 , vector<int> interval2){
        return interval1[1] < interval2[1] ;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // This uses the same idea as n meetings in one room 

        int n = intervals.size() ;

        //TC:O(nlogn)
        sort(intervals.begin() , intervals.end() , cmp) ;

        int cnt = 1 ;
        int endTime = intervals[0][1] ;

        //TC:O(n)
        for(int i = 1 ; i < n ; i++){
            
            if(endTime <= intervals[i][0]){
                cnt++;
                endTime = intervals[i][1];
            }
        }

        //TC:O(nlogn + n ) and SC:O(logn) for sorting 
        return n - cnt ;
    }
};