/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of rooms required to schedule all meetings without any conflicts.

Note: (0,8),(8,10) is NOT considered a conflict at 8.

Example 1:

Input: intervals = [(0,40),(5,10),(15,20)]

Output: 2
Explanation:
room1: (0,40)
room2: (5,10),(15,20)

Example 2:

Input: intervals = [(4,9)]

Output: 1
Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000
*/



//Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Basically use two pointer approach 
        // Visulaise by drawing or see neetcode video 
        // Find the maximum no of simulataneous meetings at a time

        int n = intervals.size() ;

        vector<int> st ; // Stores all start 
        vector<int> nd ; // Stores all end 

        for(int i = 0 ; i < n ; i++){

            st.push_back(intervals[i].start);
            nd.push_back(intervals[i].end);
        }

        // Sort both 
        sort(st.begin() , st.end()) ;
        sort(nd.begin() , nd.end()) ;

        int i = 0 ;
        int j = 0 ;
        int cnt = 0 ; // Counts simualtaneous meetings at that time
        int maxi = 0 ; // Counts maximum simultaneous at a time
        while(i < n ){
            // Only start matters as end will obviously remain as max(end) > max(start)
            // But end only reduces cnt , so remaining ends do not matter 

            if( st[i] < nd[j]){
                cnt++ ;
                i++;
                maxi = max(maxi , cnt);

            }
            else{
                // nd[j] < st[i] 
                // Or when st[i] == nd[j]
                // Process nd first as if same st and nd we consider it non overlapping 
                cnt-- ; 
                j++ ; 
            }
        }

        //TC:O(nlogn) and SC:O(n)
        return maxi ;
    }
};
