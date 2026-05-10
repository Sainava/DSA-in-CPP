/*
You are given an array of CPU tasks tasks, where tasks[i] is an uppercase english character from A to Z. You are also given an integer n.

Each CPU cycle allows the completion of a single task, and tasks may be completed in any order.

The only constraint is that identical tasks must be separated by at least n CPU cycles, to cooldown the CPU.

Return the minimum number of CPU cycles required to complete all tasks.

Example 1:

Input: tasks = ["X","X","Y","Y"], n = 2

Output: 5
Explanation: A possible sequence is: X -> Y -> idle -> X -> Y.

Example 2:

Input: tasks = ["A","A","A","B","C"], n = 3

Output: 9
Explanation: A possible sequence is: A -> B -> C -> Idle -> A -> Idle -> Idle -> Idle -> A.

Constraints:

1 <= tasks.length <= 1000
0 <= n <= 100
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//Solution 1 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Order of execution does not matter until the time gap is maintained 
        unordered_map<char ,int> mp ;
        for(char c:tasks ){
            mp[c]++;
        }

        priority_queue<int> pq ; // Frequency, the name of task does not matter 
        for(auto p:mp){
            pq.push(p.second);
        }

        queue<pair<int,int>> q ; // {freqRemaining , next time it can exeucte}

        int time = 0 ;
        while( !pq.empty() || !q.empty()){
            time++;
            
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                
                // Now push to queue
                if(freq){
                    q.push({freq , time+n});
                }

            }

            if(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        // TC:O(time or sum of frequency of tasks) and pq operations are log(26) here
        // So TC:O(tasks.length()) 
        //SC:O(1) = SC:O(26) because tasks are always uppercase letters 
        return time;
    }
};

// Solution 2 : Using formula
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Intuition:
        // The task with maximum frequency creates the "skeleton" of the schedule.
        //
        // Example:
        // [A,A,A,B,B,B,C,C], n = 2
        //
        // maxFreq = 3
        // countMax = 2 (A and B)
        //
        // First place the most frequent tasks:
        //
        // A _ _ A _ _ A
        //
        // There are (maxFreq - 1) gaps = 2 gaps.
        // Each gap needs size n = 2.
        //
        // But B also has max frequency, so the last row is not just "A":
        //
        // A B _ A B _ A B
        //
        // Now C can fill one idle:
        //
        // A B C A B idle A B
        //
        // Formula:
        // (maxFreq - 1) * (n + 1) + countMax
        //
        // Here:
        // (3 - 1) * (2 + 1) + 2
        // = 2 * 3 + 2
        // = 8
        //
        // ------------------------------------------------------------
        //
        // Why max(tasks.size(), formula)?
        //
        // Sometimes enough distinct tasks exist to fill all idle slots.
        //
        // Example:
        // [A,A,A,B,B,B,C,C,D,D], n = 2
        //
        // Formula gives:
        // (3 - 1) * (2 + 1) + 2
        // = 8
        //
        // But total tasks = 10
        //
        // We can schedule without idle:
        // A B C A B D A B C D
        //
        // So answer cannot be smaller than total tasks.
        //
        // Final Answer:
        // max(tasks.size(), formula)

        unordered_map<char,int> mp ;
        int maxFreq = INT_MIN;
        int maxCount = 0;
        for(char c:tasks){
            mp[c]++;
            maxFreq = max(maxFreq , mp[c]);
        }

        for( auto p : mp){
            if(p.second == maxFreq ){
                maxCount++;
            }
        }

        int formulaAns = ((maxFreq - 1)*(n+1)) + maxCount ;

        //TC:O(tasks.length()) and SC:O(26) as uppercase letters 
        return max(formulaAns , (int)tasks.size());
    }
};

