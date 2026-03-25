/*
Problem statement
You have to implement the shortest job first scheduling algorithm.



Shortest Job First is an algorithm in which the process having the smallest execution(burst) time is chosen for the next execution. Here, you will implement a non - preemptive version (a process will wait till process(es) with shorter burst time executes). You have to return the average waiting for the given number of processes.



Completion Time: Time at which process completes its execution.


Example:

SJF will schedule the job which is having least burst time.

Hence, Average waiting time = (5 + 0 + 2) / 3 = 2.33

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
0 3
0 1
0 2
Sample Output 1 :
1.33
Explanation For Sample Input 1:
The table for the given number of processes is 

Therefore, the average waiting for the given process is 1.33.
Sample Input 2 :
2
1 4
1 3
Sample Output 2 :
1.50
Constraints:
1 <= N <= 10^2
1 <= at, bt <= 10^3

Where 'N' denotes the number of processes, 'at' and 'bt' represents the arrival time and burst time of any process.

Time Limit: 1 sec.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{   
    vector<pair<int ,int>> tasks;

    // {arrival, burst}
    for(int i = 0 ; i < n ; i++){
        tasks.push_back({arrivalTime[i], burstTime[i]});
    }

    // sort by arrival time
    sort(tasks.begin(), tasks.end());

    // min heap ? {burstTime, arrivalTime}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    long long time = 0;
    int i = 0;
    float wt = 0;

    while(i < n || !pq.empty()){

        // If CPU idle ? jump to next arrival
        if(pq.empty() && time < tasks[i].first){
            time = tasks[i].first;
        }

        // Push all available tasks
        while(i < n && tasks[i].first <= time){
            pq.push({tasks[i].second, tasks[i].first}); // {burst, arrival}
            i++;
        }

        // Process shortest job
        auto it = pq.top();
        pq.pop();

        int burst = it.first;
        int arrival = it.second;

        // Waiting time = start - arrival
        wt += (time - arrival);

        // Execute
        time += burst;
    }
    

     //TC:O(nlogn)
     // SC:O(n) extra for min heap 
    return wt / n;
}