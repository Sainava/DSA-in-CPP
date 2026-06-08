/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). It is not allowed to load weight more than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [2,4,6,1,3,10], days = 4

Output: 10
Explanation:
1st day: [2]
2nd day: [4,6]
3rd day: [1,3]
4th day: [10]

Example 2:

Input: weights = [1,2,3,4,5], days = 5

Output: 5
Explanation:
1st day: [1]
2nd day: [2]
3rd day: [3]
4th day: [4]
5th day: [5]

Example 3:

Input: weights = [1,5,4,4,2,3], days = 3

Output: 8
Explanation:
1st day = [1,5]
2nd day = [4,4]
3rd day = [2,3]

Constraints:

1 <= days, weights.length <= 50,000
1 <= weights[i] <= 500
*/
#include <iostream>
#include <vector>       
#include <climits>
using namespace std;

class Solution {
public:
    bool isPossible(int size,vector<int>& weights, int days){
        // Here size means maximum weight capacity of the ship 

        int d = 1 ; 
        int wt = 0 ; // Current wieght in ship 

        //TC:O(n)
        for(int i = 0 ; i < weights.size() ; i++){
            if( wt + weights[i] <=size ){
                wt += weights [i];
            }else{
                wt  = weights[i] ;
                d++ ; 

                if( d > days){
                    return false ; 
                }
            }
        }

        return true ; 
        
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // We need to minimise the maximum size of ship 
        // So binaty search on the answer 

        int maxi = INT_MIN ; 
        int sum = 0 ;

        for(int weight : weights){
            maxi = max(maxi , weight);
            sum += weight ;
        }

        int start = maxi ; // Take the maximum weight package (as here we need to take entire packages we cannot take half or fraction of packages )
        int end = sum ; // Take all packages at once

        // Start is minimum size of ship and end is maximum size of ship 
        // We do binary search on size 
        // If size of ship increase , days needed to ship packages decreases and vice versa 

        int ans = end ; 

        //TC:O(n log(end - start))
        while( start <= end){
            int mid = start + (end - start)/2 ; 

            if(isPossible(mid , weights , days)){
                // It is possible then increasing size is also possible 
                // We need to see if decreasing size is possible 
                ans = mid ; 
                end = mid - 1;
            }else{
                // Need to increase the weight capacity of ship 
                start = mid + 1 ; 
            }
        }

        //TC:O(n log(end - start)) and SC:(1)
        // More accurately 
        // n = number of packages
        // S = sum(weights)
        // M = max(weights)
        //TC = O(n log(S - M + 1)) = approx TC:O(n log(S))
        return ans ;
    }
};