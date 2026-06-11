/*
You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the ith task will be available to process at enqueueTime[i] and will take processingTime[i] to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started to process, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

Example 1:

Input: tasks = [[1,4],[3,3],[2,1]]

Output: [0,2,1]
Example 2:

Input: tasks = [[5,2],[4,4],[4,1],[2,1],[3,3]]

Output: [3,4,2,0,1]
Constraints:

1 <= tasks.length <= 100,000
1 <= enqueueTime[i], processingTime[i] <= 1,000,000,000
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size() ; 

        //TC:O(n)
        for(int i = 0 ; i < tasks.size() ; i++){
            tasks[i].push_back(i) ;
        }

        //TC:O(nlogn)
        sort(tasks.begin() , tasks.end());

        long long time = 0 ; 

        priority_queue<
            pair<int, int> ,
            vector<pair<int,int>> ,
            greater<pair<int,int>>
        > pq ; 

        vector<int> ans ; 

        int i = 0 ; // index 

        //TC:O(nlogn) as pushed and popped to pq once each for each task 
        while( i < n || !pq.empty()){

            while(i < n && tasks[i][0] <= time){
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }

            if( !pq.empty()){
                auto tsk = pq.top();
                pq.pop(); 

                int processTime = tsk.first;
                int index = tsk.second ;

                ans.push_back(index);

                time += processTime ; 
            }else{
                time = tasks[i][0]; 
            }  

        }

        //TC:O(nlogn) and SC:O(n)
        return ans ; 
    }
};