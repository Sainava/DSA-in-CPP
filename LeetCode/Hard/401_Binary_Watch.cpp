/*
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

For example, the below binary watch reads "4:51".


Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
 

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
Example 2:

Input: turnedOn = 9
Output: []
 

Constraints:

0 <= turnedOn <= 10
*/


#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // Iterate through all possible hours (0-11) and minutes (0-59)
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
                // Use bitset to count the number of set bits in both hour and minute.
                // We can combine them or count them separately.
                // bitset<10>((h << 6) | m) combines them into one 10-bit integer.
                if (bitset<10>((h << 6) | m).count() == turnedOn) {
                    
                    // Format the time string
                    string time = to_string(h) + ":";
                    
                    // Add leading zero for minutes if less than 10
                    if (m < 10) {
                        time += "0";
                    }
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};