/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and a integer array trips where trips[i] = [numPassengers[i], from[i], to[i]] indicates that the ith trip has numPassengers[i] passengers and the locations to pick them up and drop them off are from[i] and to[i] respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Example 1:

Input: trips = [[4,1,2],[3,2,4]], capacity = 4

Output: true
Example 2:

Input: trips = [[2,1,3],[3,2,4]], capacity = 4

Output: false
Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengers[i] <= 100
0 <= from[i] < to[i] <= 1000
1 <= capacity <= 100,000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size() ; 

        vector<pair<int , int >> start ; // from location and passengers 

        vector<pair<int , int >> dest ; // to location and passengers 


        for (int i = 0 ; i < n ; i++){
            start.push_back( {trips[i][1] , trips[i][0] });
            dest.push_back( {trips[i][2] , trips[i][0]});
        }

        sort(start.begin() , start.end());
        sort( dest.begin() , dest.end());

        int cnt = 0 ; // Count no of passengers 
        
        int i = 0 ;
        int j = 0 ; 

        while( i < n){
            if( start[i].first < dest[j].first){
                cnt += start[i++].second;

                if( cnt > capacity) return false ; 
            }
            else{
                cnt -= dest[j++].second;
            }
        }

        //TC:O(nlogn) and SC:O(n)
        return true ; 
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Given 0 <= from[i] < to[i] <= 1000

        vector<int> diff(1001 , 0) ; 

        for( auto &trip : trips){

            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            diff[from] += passengers ; 
            diff[to] -= passengers ; 
        }

        int currPassengers = 0;

        // This is essentially simulation too but since we know only 1000 locations 
        for(int location = 0; location <= 1000; location++) {
            currPassengers += diff[location];

            if(currPassengers > capacity)
                return false;
        }

        //TC:O(n + 10001) and SC:O(1000)
        // SO TC:O(n) and SC:O(1)
        return true ; 


    }
};