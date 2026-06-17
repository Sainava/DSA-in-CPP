/*

You are given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
Example 1:

Input: columnNumber = 32

Output: "AF"
Example 2:

Input: columnNumber = 53

Output: "BA"
Constraints:

1 <= columnNumber <= ((2^31)-1)

*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        // The troubling part in this is 0 does not map to anything 
        // A -> 1 so we need to keep the off by one in mind 

        string res = "";

        while( columnNumber > 0){
            int remainder =(columnNumber - 1 ) % 26 ; // Say 26 so this give us 25 and we add A to 25 to get 26 (that is correct)

            res += 'A' + remainder ; 

            columnNumber = (columnNumber - 1) / 26 ; // If we do not minus 1 we get wrong answer
        }

        reverse(res.begin() , res.end());

        //TC:O(log base 26 of n ) as we divide by 26 at each step 
        return res ; 
    }
};