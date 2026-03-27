/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() ;

        vector<vector<int>> ans ;

        // first find all the intervals that are less then the newInternal and insert them to answer
        int idx = 0 ;

        while( idx<n && intervals[idx][1] < newInterval[0]  ){
            ans.push_back(intervals[idx]);
            idx++;
        }

        // Now insert the newInterval and merge the overlapping intervals 
        while( idx<n && intervals[idx][0] <= newInterval[1] ){
            newInterval[0] = min( newInterval[0] , intervals[idx][0]);
            newInterval[1] = max( newInterval[1] , intervals[idx][1]);
            idx++;
        }

        ans.push_back(newInterval);

        // Now push the rest of the intervals into the answer 
        while(idx < n){
            ans.push_back(intervals[idx]);
            idx++;
        }

        //TC :O(n) and SC:(1) extra space and SC:O(n) to return the answer 
        return ans ;


    }
};