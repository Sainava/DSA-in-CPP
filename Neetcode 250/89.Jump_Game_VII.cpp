/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:

Input: s = "00110010", minJump = 2, maxJump = 4

Output: true
Explanation: The order of jumps is: indices 0 -> 4 -> 7.

Example 2:

Input: s = "0010", minJump = 1, maxJump = 1

Output: false
Constraints:

2 <= s.length <= 100,000
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // s[0] == 0 always GIVEN To us 
        // s[n-1] = 0 or 1 

        int n = s.size() ; 
        queue<int> q ; 
        q.push(0) ; 
        int farthest = 0 ; // Keeps track of farthest we have reached till now

        while(!q.empty()){
            int index = q.front() ; 
            q.pop() ; 

            int start = max( index + minJump , farthest + 1) ;// See where we can go to / We do not want to check same index again so we do max with farthest + 1
            // Remember farthest is the last index we have reached till now 

            int end = min(index + maxJump , n - 1);

            for(int i = start ; i <= end ; i++){
                if( s[i] == '0'){
                    // We can actually jump from here 
                    q.push(i) ; 

                    if ( i ==  n - 1) return true ; 
                }
            }

            farthest = end ; 
        }

        //TC:O(n) and SC:O(1)
        return false ; 
    }   
};