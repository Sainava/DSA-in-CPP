/*
Problem statement
You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.



You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.



Note:
The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.


For example:
'N' = 3, Start = [1, 3, 6], End = [4, 8, 7].

You can organize a maximum of 2 meetings. Meeting number 1 from 1 to 4, Meeting number 3 from 6 to 7.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
1 3 0 5 8 5
2 4 6 7 9 9
Sample Output 1:
4
Explanation For Sample Input 1:
You can organize a maximum of 4 meetings: 

Meeting number 1 from 1 to 2.
Meeting number 2 from 3 to 4.
Meeting number 4 from 5 to 7.
Meeting number 5 from 8 to 9.
Sample Input 2:
5
0 7 1 4 8
2 9 5 9 10
Sample Output 2:
2 
Constraints:
1 <= 'N' <= 10^5
0 <= 'Start[i]' < 'End[i]' <= 10^9

Time Limit: 1 sec
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


bool cmp( vector<int> meeting1 , vector<int> meeting2){
    return meeting1[1] < meeting2[1];
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{   
    int n = start.size() ;     

    //SC:O(n)
    vector<vector<int>> meetings;
    
    // TC:O(n)
    for(int i = 0 ; i < n ; i++){
        meetings.push_back({ start[i] , end[i] , i }); // { start , end , index }
    }

    // sort by the end time 
    //TC:O(nlogn)
    sort(meetings.begin() , meetings.end() , cmp );

    int freeTime = 0 ; // Time at which the meeting room will be free
    int cnt = 0 ;
    vector<int> order ; // This is not asked in this question but maybe asked in an interview
    //TC:O(n)
    for(int i = 0. ; i < n ; i++){
        int startTime = meetings[i][0];
        int endTime = meetings[i][1] ;
        int index = meetings[i][2];

        if( startTime > freeTime){
            cnt++ ;
            freeTime = endTime;
            order.push_back(index);
        }
    }

    //TC:O(nlogn)
    // SC:O(3n) +  SC:(logn) which is required for STL sorting 
    // if order is also asked , add + SC:O(n) to the above 
    return cnt ;
}