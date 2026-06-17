/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:

Input: ratings = [4,3,5]

Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: ratings = [2,3,3]

Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:

1 <= ratings.length <= 20,000
0 <= ratings[i] <= 20,000

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size() ; 
        vector<int> res(n, 1) ;

        // We will do 2 passes . One from left to right and other from right to left 

        //First pass 
        for(int i = 1 ; i < n ; i++){
            if( ratings[i] > ratings[i - 1]){
                res[i] = res[i-1] + 1 ; 
            }
        }

        // Second pass
        for(int i = n - 2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                // If res already not higher only then we increment it 
                res[i] = max ( res[i] , res[i+1] + 1);
            }
        }

        // Now get all the candies 
        int ans = 0 ; 

        for(int cnd : res){
            ans += cnd ; 
        }

        //TC:O(n) and SC:O(1)
        return ans ; 
    }
};