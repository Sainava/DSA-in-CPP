/*
You have a lock with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:

Input: deadends = ["1111","0120","2020","3333"], target = "5555"

Output: 20
Example 2:

Input: deadends = ["4443","4445","4434","4454","4344","4544","3444","5444"], target = "4444"

Output: -1
Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> children( string lock){
        vector<string> child ; 

        for(int i = 0 ;  i < 4 ;i++){
            string temp = lock ; 
            int c = lock[i] - '0';

            int inc = (c + 1 ) % 10 ; 
            int dec = (c - 1 + 10) % 10 ;

            // Now make strings ;

            temp[i] = inc + '0';

            child.push_back(temp);

            temp[i] = dec + '0' ;

            child.push_back(temp) ; 

        }

        return child ; 
    }

    int openLock(vector<string>& deadends, string target) {
        // We need minimum turns and we start with "0000"
        // So we can think of this as minimum distance so BFS 
        // This would guarantee that when we first reach target , we do so in the minimum turns

        unordered_set<string> visited ; 

        // We push to visited so we do not visit them when doing bfs 
        for(string str : deadends){
            visited.insert(str);
        }

        if( visited.count("0000")) return -1 ; // starting point is deadend 

        queue< pair <string , int>> q ; // lock and turns taken to reach it 

        q.push({"0000" , 0});

        while( !q.empty()){
            string lock = q.front().first ;
            int turns = q.front().second ; 
            q.pop();

            if( lock == target ) return turns  ; 

            // Now insert its children into the queue 
            // For children for each index -> increment by and decrease by 1
            // Eg for "0000" = {1000 , 9000 , 0100 , 0900 , 0010 , 0090 , 0001 , 0009}

            for(const string &child : children(lock)){
                if( !visited.count(child)){
                    visited.insert(child);
                    q.push({ child , turns + 1}) ; 
                }
            }
        }

        // There are only 10^4 possible lock states: 0000 -> 9999

        // Time Complexity:
        // O(10^4)
        // Each state is visited at most once.
        // Generating children takes O(8).

        // Space Complexity:
        // O(10^4)
        // visited set + BFS queue.

        //char participates in arithmetic as its integer ASCII value.
        // '7' - '0'   -> 7
        // 7 + '0'     -> '7'

        // '3' - '0'   -> 3
        // 3 + '0'     -> '3'
        return -1 ; 

    }
};