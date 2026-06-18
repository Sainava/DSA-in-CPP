// 18 June 2026

//1344. Angle Between Hands of a Clock

/*
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59*/
#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // So lets say at 12 :00 both are together so angle is 0 
        
        // Now every hour the hour hand moves 30 degress( The angle between each number on the clock )
        
        // So at 3 hours it moves 3 x 30 = 90 degress 

        // Now as it minutes pass it moves to the next number 

        // So at 3:00 it moves 90 degress but it keeps on moving and it is not exactly at 3 at 3:15 

        // So if it moves 30 degress in 60 minutes it moves 0.5 degress in 1 minute 

        // The minute hand moves 360 degress in 60 minutes so it moves 6 degrees in 1 minute 

        if( hour == 12 ) hour = 0 ; 

        double hourAngle = 30.0 * hour + 0.5 * minutes ;
        double minuteAngle = 6.0 * minutes ; 

        // We have each of their angles from 00 or 12 . Now to get the angle between them we subtract 

        double diff = abs( hourAngle - minuteAngle) ;

        // Now we report the smaller angle . Like if angle between them is 270 . The entire angle is 360 so the smaller angle between them is 360 - 270 = 90; 

        //TC:O(1) and SC:(1)
        return min(diff , 360.0 - diff) ; 
    }
};
