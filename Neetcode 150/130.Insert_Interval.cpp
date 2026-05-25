/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents the start and the end time of the ith interval. intervals is initially sorted in ascending order by start_i.

You are given another interval newInterval = [start, end].

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and also intervals still does not have any overlapping intervals. You may merge the overlapping intervals if needed.

Return intervals after adding newInterval.

Note: Intervals are non-overlapping if they have no common point. For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.

Example 1:

Input: intervals = [[1,3],[4,6]], newInterval = [2,5]

Output: [[1,6]]
Explanation: [2,5] overlaps with [1,3] and [4,6], so all three are merged into [1,6].

Example 2:

Input: intervals = [[1,2],[3,5],[9,10]], newInterval = [6,7]

Output: [[1,2],[3,5],[6,7],[9,10]]
Explanation: [6,7] does not overlap with any existing interval, so it is simply inserted between [3,5] and [9,10].

Constraints:

0 <= intervals.length <= 1000
newInterval.length == intervals[i].length == 2
0 <= start <= end <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans ; 
        int n = intervals.size() ;
        // Step 1 : Find the index at which we need to insert 
        int i = 0 ; 
        while(i < n &&  intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // Now we know intervals[i][1] >= newInterval[0]
        // So we will either need to merge or insert directly 

        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max( newInterval[1] , intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // Now we know intervals[i][0] > newInterval[i]
        // So simply push the rest 

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        // Every interval is processed once so TC:O(n)
        // SC:O(n) to return the answer
        return ans ;
    }
};
