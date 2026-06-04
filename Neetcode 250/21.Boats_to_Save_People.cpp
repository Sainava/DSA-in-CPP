/*
You are given an integer array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [5,1,4,2], limit = 6

Output: 2
Explanation:
First boat [5,1].
Second boat [4,2].

Example 2:

Input: people = [1,3,2,3,2], limit = 3

Output: 4
Explanation:
First boat [3].
Second boat [3].
Third boat [1,2].
Fourth boat [2].

Constraints:

1 <= people.length <= 50,000
1 <= people[i] <= limit <= 30,000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // This is like two sum 

        int i = 0 ; 
        int j = people.size() - 1 ;

        sort(people.begin() , people.end());

        int cnt = 0 ; 
        
        while(i < j){
            int totalWeight = people[i] + people[j] ; 

            if( totalWeight <= limit){
                // Take both people 
                cnt++ ; 
                i++;
                j--;
            }
            else if ( totalWeight > limit ){
                // The jth person is too heavy and needs to be taken alone (as if increase i total weight will increase)
                cnt++ ; 
                j--;
            }
        }

        // If there are odd number of people , the middle person will still be left .
        if( i == j ) cnt++;

        //TC:O(nlogn) and SC:O(1) SC:O(logn) for sorting 
        return cnt ;
    }
};