/*
There are n cars traveling to the same destination on a one-lane highway.

You are given two arrays of integers position and speed, both of length n.

position[i] is the position of the ith car (in miles)
speed[i] is the speed of the ith car (in miles per hour)
The destination is at position target miles.

A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.

A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.

If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.

Return the number of different car fleets that will arrive at the destination.

Example 1:

Input: target = 10, position = [1,4], speed = [3,2]

Output: 1
Explanation: The cars starting at 1 (speed 3) and 4 (speed 2) become a fleet, meeting each other at 10, the destination.

Example 2:

Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]

Output: 3
Explanation: The cars starting at 4 and 7 become a fleet at position 10. The cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there are 3 car fleets that will arrive at the destination.

Constraints:

n == position.length == speed.length.
1 <= n <= 1000
0 < target <= 1000
0 < speed[i] <= 100
0 <= position[i] < target
All the values of position are unique.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Solution 1 : Sort and do not use stack approach
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        if(n==0) return 0;

        vector<vector<double>> combined; // combines position , speed and arrival time 

        for(int i = 0 ; i < n ; i++){
            double  arrivalTime = ((double)target - position[i])/ speed[i];
            combined.push_back({(double)position[i] , arrivalTime});
        }

        //TC:O(nlogn)
        sort(combined.begin(),combined.end());

        int fleets = 1;

        //TC:O(n)
        for(int i = n - 2 ; i>=0 ; i--){
            if( combined[i][1] <= combined[i+1][1]){
                combined[i][1] = combined[i+1][1];
            }else{
                fleets++;
            }
        }

        //TC:O(n + nlogn) + SC:O(n)
        return fleets;
    }
};


// Solution 2 : Sort and use stack approach
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Switching to pair to save memory! {position, arrival_time}
        std::vector<std::pair<int, double>> cars(n); 

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        // Sort ascending by position
        std::sort(cars.begin(), cars.end());

        std::stack<double> st;

        // Iterate backwards: from the car closest to the target, to the furthest
        for (int i = n - 1; i >= 0; i--) {
            double currentTime = cars[i].second;
            
            // If the stack is empty, OR this car takes LONGER than the fleet ahead of it,
            // it forms a new fleet.
            if (st.empty() || currentTime > st.top()) {
                st.push(currentTime);
            }
            // If it takes LESS OR EQUAL time, it catches up to st.top() and merges.
            // We do nothing, effectively ignoring it.
        }

        // The number of distinct fleets is just the number of items in the stack
        return st.size();
    }
};
