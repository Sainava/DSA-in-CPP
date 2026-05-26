/* 
You are given a signed 32-bit integer x.

Return x after reversing each of its digits. After reversing, if x goes outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0 instead.

Solve the problem without using integers that are outside the signed 32-bit integer range.

Example 1:

Input: x = 1234

Output: 4321
Example 2:

Input: x = -1234

Output: -4321
Example 3:

Input: x = 1234236467

Output: 0
Constraints:

-2^31 <= x <= 2^31 - 1
*/
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int maxi = INT_MAX ; 
        int mini = INT_MIN ;
        int res = 0 ; 
        while( x){
            int lastBit = x % 10 ;
            x = x / 10 ;    

            // We need to check if it will overflow or underflow
            if( res > (maxi / 10) || ( res == (maxi /10) && lastBit > (maxi % 10))){
                // it will overflow
                return 0 ; 
            }

            if( res < (mini / 10) || ( res == (mini/10) && lastBit < (mini % 10))){
                // It will underflow 
                return 0;
            }

            // Now we know it is safe to do 
            res = res * 10 + lastBit ; 

        }

        //TC:O(1) and SC:O(1) as we know x range is INT_MIN to INT_MAX
        return res; 
    }
};
