/*
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

 

Example 1:

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
Example 2:

Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
 

Constraints:

tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std ;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Things I need to keep a track of 
        // What tasks are available at that time 
        // The one with the shortest arrival time at that moment 

       
        int n = tasks.size();

        // We need indexes as well when shortest time is same , so we need to kinda change tasks and add indexes as the third element
        //TC:(n)
        for(int i = 0 ; i < n ; i++){
            tasks[i].push_back(i);
        }

        //Now we sort tasks by enqueue time 
        //TC:O(nlogn)
        sort( tasks.begin() , tasks.end());
        // Now we have tasks by their arrival time

        // We push to priority queue based on enque time but keep in priority based on shortest burst time and then by index 
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;

        long long time = 0 ; // current CPU time 
        int i = 0 ; // pointer for the tasks
        vector<int> ans;

        //Either tasks are left or queue still has tasks that need to be executed 
        // The following loop runs n times overall as each task as each time is pused into queue exactly once 
        // So eventhough nested loop , will run n times overall
        // Each task pushed once and each push in heap is (nlogn)
        // Each task is popped once and each pop in heap is (nlogn)
        // SO overall 
        //TC:O( n + nlogn + nlogn) == TC:O(nlogn)

        while(i < n || !pq.empty()){

            // Case : 1 If cpu is idle , no tasks in queue to execute , move time forward to the arrival timeof the task 
            if( pq.empty() && time < tasks[i][0]){
                time = tasks[i][0];
            }

            // Now push all new tasks that are available at this time to the queue
            while( i < n && tasks[i][0] <=time){
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }

            // Now take the one with the shortest burst time and execute it 
            auto it = pq.top();
            pq.pop();         
            
            time += it.first;
            ans.push_back(it.second);

        }

        //TC:O(nlogn)
        // SC:O(n) extra for min heap and SC:O(n) to return the answer
        return ans;


    }
};