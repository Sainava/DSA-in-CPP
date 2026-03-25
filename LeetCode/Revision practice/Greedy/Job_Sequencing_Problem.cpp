/*
Problem statement
You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job, 'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.



You will make a particular profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.



Return the number of jobs to be done to get maximum profit.



Note :
If a particular job has a deadline 'x', it means that it needs to be completed at any time before 'x'.

Assume that the start time is 0.


For Example :
'N' = 3, Jobs = [[1, 1, 30], [2, 3, 40], [3, 2, 10]].

All the jobs have different deadlines. So we can complete all the jobs.

At time 0-1, Job 1 will complete.
At time 1-2, Job 3 will complete.
At time 2-3, Job 2 will complete.

So our answer is [3 80].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4
1 2 30
2 2 40
3 1 10
4 1 10
Sample Output 1 :
2 70
Explanation For Sample Input 1 :
At time 0-1, Job 1 will complete.

At time 1-2, Job 2 will complete.

The first and second jobs can be completed within the deadlines, and we earn a profit of 70 by doing so.
Sample Input 2 :
3
1 1 40
2 1 50
3 1 60
Sample Output 2 :
1 60
Constraints :
1 <= 'N' <= 10^5
1 <= jobs[i][0] <= 'N'
1 <= jobs[i][1] <= 'N'
1 <= jobs[i][2] <= 10^3

Time limit: 1 sec
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool cmp (vector<int> job1 , vector<int> job2){
    return job1[2] > job2[2];
}


vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // jobs[i][0] = job id 
    // jobs[i][1] = job deadline
    // jobs[i][2] = job profit 

    int n = jobs.size() ;

    // sort by the profit
     sort( jobs.begin() , jobs.end() , cmp);

    // need to get max deadline 
    int maxDeadline = 0 ;
    for(int i = 0 ; i < n ; i++){
        maxDeadline = max (maxDeadline , jobs[i][1]);
    }

    vector<int> days(maxDeadline + 1, -1); // To keep track of what days we have already sechduled a task 
    // + 1 since one based indexing based on day 
    int cnt = 0 ;
    int totalProfit = 0 ;
    for(int i = 0 ; i < n ; i++){

        for(int j = jobs[i][1] ; j>= 1 ; j--){
            if(days[j] == -1){
                cnt++ ;
                totalProfit += jobs[i][2];
                days[j] = jobs[i][0];
                break;
            }
        }
    }
    
    //TC : O(nlogn + n*maxDeadline) + SC:O(maxDeadline)
    return {cnt , totalProfit};
}