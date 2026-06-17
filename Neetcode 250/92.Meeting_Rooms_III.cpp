/*
There are n rooms numbered from 0 to n - 1. You are given a 2D integer array meetings where meetings[i] = [start[i], end[i]] means that a meeting will be held during the half-closed time interval [start[i], end[i]). All the values of start[i] are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

Example 1:

Input: n = 2, meetings = [[1,10],[2,10],[3,10],[4,10]]

Output: 0
Explanation:

At time 1, the room with number 0 is available, the first meeting is allocated to it.
At time 2, the room with number 1 is available, the second meeting is allocated to it.
At time 10, the rooms with numbers 0 and 1 becomes unused, the third meeting is allocated to room number 0 and fourth meeting is allocated to room number 1.
The room with most meetings held and have lowest number is 0.

Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[6,8],[4,9]]

Output: 1
Explanation:

At time 1, all three rooms are not being used. The first meeting starts in room 0.
At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
At time 3, only room 2 is not being used. The third meeting starts in room 2.
At time 4, all three rooms are being used. The fourth meeting is delayed.
At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
At time 6, all three rooms are being used. The fifth meeting is delayed.
At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1 as it is lowest.

Constraints:

1 <= n <= 100
1 <= meetings.length <= 100,000
meetings[i].length == 2
0 <= start[i] < end[i] <= 500,000
All the values of start[i] are unique.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size() ; 

        sort(meetings.begin() , meetings.end()) ;

        // SC:O(n)
        priority_queue<int , vector<int> , greater<int> > available ;

        // Initially all rooms are available 
        // We use the lowest numbered available room 
        for(int i = 0 ; i < n ; i++){
            available.push(i) ; 
        } 

        priority_queue <
            pair<int,int> , 
            vector<pair<int,int> > , 
            greater<pair<int,int> >
        > used ; // ( end time , room no)

        vector<int> count( n , 0) ; // Keeps track of the no of meetings in each room , We need rto return the max here 

        for(int i = 0 ; i < m ; i++){
            int start = meetings[i][0] ;
            int end = meetings[i][1] ;

            //Free the used rooms that should be free by now 
            while( ! used.empty() && used.top().first <= start){
                available.push( used.top().second);// That room is now available
                used.pop() ; 
            }

            // If no room is available , we need this meeting to wait 
            if(available.empty()){
                // Take the one from used that will end the soonest 
                auto top = used.top() ;
                used.pop() ;  
                int end_time = top.first;
                int room_no = top.second ; 

                // Now this meeting will take place at the earliest time when one room becomes available 
                // Say all rooms are occupied . We find out the earliest would be free
                // Skip time 
                // So that is why we popped that room because we assume time has passed and that room is now available

                end = end_time + ( end - start ); // New end time for this meeting ; basically (new start time) + duration 

                // Make the room available again 
                available.push(room_no) ;  
            }

            // If a room is available -> From the above we make sure one is always available
            // Schedule a meeting in that room 
            int room = available.top() ; 
            available.pop() ;
            count[room]++ ; 
            used.push( { end , room});
            
        }

        // For returning the answer 

        int max = * max_element(count.begin() , count.end());

        for(int i = 0 ; i < n ; i++){
            // if there is a tie we return the lower number 
            if( count[i] == max){
                return i ; 
            }
        }

        //TC:O(mlogm) for sorting the meetings 
        // The size of used and available can be n 
        // All the m meetings are pushed and popped a constant number of times 
        // So for running simulation -> TC:O( mlogn)
        // Total TC:O( mlogm + mlogn)

        // SC:O(n) for the heaps and SC:O(logm) for sorting 
        return -1 ; 
    }
};