/*
Given an array of intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note: Intervals are non-overlapping even if they have a common point. For example, [1, 3] and [2, 4] are overlapping, but [1, 2] and [2, 3] are non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,4],[1,4]]

Output: 1
Explanation: After [1,4] is removed, the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[2,4]]

Output: 0
Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
-50000 <= starti < endi <= 50000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> a , const vector<int> b){
        return a[1] < b[1] ;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Similar to n meetings in one room 
        // There we figure out the maximum meeting we can do in one room . 
        // That is basically the maximum non overlapping meetings 
        // So here also we find out the maximum overlapping intervals 
        // And then remove the remaining 
        // Remember if asked MAXIMUM NON OVERLAPPING INTERVALS , think of similar approach 

        int n = intervals.size() ;

        sort(intervals.begin() , intervals.end() , cmp ) ;

        int cnt = 1 ; 
        int lastEnd = intervals[0][1] ;

        for(int i = 1 ; i < n ; i++){
            if( intervals[i][0] >= lastEnd){
                cnt++ ; 
                lastEnd = intervals[i][1];
            }
        }

        //TC:O(nlogn + n) and SC:O(1) (logn to sort )
        return n - cnt ; 
    }

};
