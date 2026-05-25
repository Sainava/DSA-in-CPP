/*
There are n gas stations along a circular route. You are given two integer arrays gas and cost where:

gas[i] is the amount of gas at the ith station.
cost[i] is the amount of gas needed to travel from the ith station to the (i + 1)th station. (The last station is connected to the first station)
You have a car that can store an unlimited amount of gas, but you begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index such that you can travel around the circuit once in the clockwise direction. If it's impossible, then return -1.

It's guaranteed that at most one solution exists.

Example 1:

Input: gas = [1,2,3,4], cost = [2,2,4,1]

Output: 3
Explanation: Start at station 3 and fill up with gas[3] = 4, so tank = 4.
Travel from station 3 to station 0, spending cost[3] = 1, then fill gas[0] = 1, so tank = 4 - 1 + 1 = 4.
Travel from station 0 to station 1, spending cost[0] = 2, then fill gas[1] = 2, so tank = 4 - 2 + 2 = 4.
Travel from station 1 to station 2, spending cost[1] = 2, then fill gas[2] = 3, so tank = 4 - 2 + 3 = 5.
Travel from station 2 back to station 3, spending cost[2] = 4, so tank = 5 - 4 = 1.
The circuit is complete, so return 3.

Example 2:

Input: gas = [1,2,3], cost = [2,3,2]

Output: -1
Explanation:
You cannot start at station 0 or 1 because neither has enough gas to travel to the next station.
If you start at station 2, fill gas[2] = 3, so tank = 3.
Travel from station 2 to station 0, spending cost[2] = 2, then fill gas[0] = 1, so tank = 3 - 2 + 1 = 2.
Travel from station 0 to station 1, spending cost[0] = 2, then fill gas[1] = 2, so tank = 2 - 2 + 2 = 2.
To travel from station 1 to station 2, you need cost[1] = 3 gas, but the tank only has 2.
So no starting station can complete the circuit, and the answer is -1.

Constraints:

1 <= gas.length == cost.length <= 1000
0 <= gas[i], cost[i] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Few things to keep in mind 
        // It is stated that AT MOST ONE ANSWER EXISTS 
        // So either no answer or exactly one index is the starting index and others will fail 

        // Lets analyse the case with no answer 
        // At first , we start we zero , we need to give sum(cost array) to complete the path 
        // So lets assume like this , we spend cost we are given sum(gas array) 
        // If cost > what we receive , no answer can exist 
        int  n = gas.size() ;
        int costSum = 0 ;
        int gasSum = 0 ;

        for(int cst : cost) costSum += cst ;
        for(int gs : gas) gasSum += gs ;

        if( costSum > gasSum ) return -1 ;

        // When we reach this section , we are sure an answer exists 
        int startId = 0 , currGas = 0; 

        for(int i = 0 ; i < n ; i++){
            currGas = currGas + gas[i] - cost[i] ;

            if( currGas < 0){
                startId = i + 1 ;
                currGas = 0 ;
            }
            
        }

        //TC:O(n) and SC:O(1)
        return startId ; 
        // Why do we only check from startId to n-1 
        //say sum(gas) >= sum(cost) so answer exist 
        //Say sum(gas) =  a + b 
        //and sum(cost) = c + d
        //Now we know sum(gas[0 - startId] ) < sum(cost[0 - startId] = a < c 
        //Now we know sum(gas[startId - n] ) > sum(cost[startId - n] = b > d 
        //Now we know a + b > c + d => b - d > c - a 
        //So we have gas remaining after n is greater than gas needed to reach back startID
        // Hence proves if we can reach past n-1 we can reach baxk startId and question says only one answer so it is it

        // We can optimise but doing the sum of cost and gas in one loop and before returning we check if( costSum > gasSum ) return -1 ; 
    }
};
