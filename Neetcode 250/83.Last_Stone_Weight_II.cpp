/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,4,1,5,6,3]

Output: 1
Explanation:

We smash 2 and 1 which makes the array [1,4,5,6,3].
We smash 4 and 3 which makes the array [1,1,5,6].
We smash 5 and 6 which makes the array [1,1,1].
We smash 1 and 1 which makes the array [1].
Example 2:

Input: stones = [4,4,1,7,10]

Output: 2
Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve( int index , int sum , int target ,int total ,vector<int>& stones ,vector<vector<int >> &dp){
        // BASE CASE VERY IMPORTANT
        // if we reach target or exceed it for the first time . We stop 
        if( sum >= target || index == stones.size()){
            // Return the answer that is difference between the two piles 
            return abs(sum - (total - sum)) ; // One portion - the remaining portion 
        }

        if( dp[index][sum] != -1) return dp[index][sum] ; 

        // Can choose to take this or not 
        int notTake = solve( index + 1 , sum , target , total , stones , dp);

        int take =solve( index + 1 , sum + stones[index] , target , total , stones , dp);


        return dp[index][sum] = min ( notTake , take ) ; 
    }

    int lastStoneWeightII(vector<int>& stones) {
        // In last stone 1 we were always choosing the heaviest stones . So we used heap and we are required to give the final stone if any is left 
        // But here we can choose any two stones  and that is why it is different -> We need to miimise the weight of stone remaining if any 

        // Now here consider this . At the end we want to be left with the minimum weight 

        // Say Total sum is 23  If we can divide into two halfs one is 12 and other is 11 . We will get final answer as 1 
        // If total sum is 24 then we can try to divide into two halfs of 12 each. We will get answer as 0 .
        // We may not be able to divide so perfecty so we will just try to get as close to total(sum)/2 as possible


        // This essentially becomes a target sum or bouded knapsack problem 
        int n = stones.size() ; 
        int index = 0 ; 
        int total = 0 ; 

        for(int stone : stones){
            total += stone ; 
        }

        int target = total / 2; // ceil ( total / 2) or just total + 2 - 1 /2 also works 

        int sum = 0 ; 
        vector<vector<int >> dp( n, vector<int>(target + 1  , -1 )) ;

        // TC:O(n * target ) = TC:O(n * total/2 ) = TC:O(n* total)
        // SC:O(n * total )
        return solve(index, sum ,target , total ,stones , dp);
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size() ; 

        int total = 0 ; 

        for(int stone : stones){
            total += stone ; 
        }

        int target = total / 2; // ceil ( total / 2) or just total + 2 - 1 /2 also works 

 
        vector<vector<int >> dp( n + 1, vector<int>(target + 1  , 0 )) ;
        // dp[index][sum] = minimum possible final difference
        // using stones from index onward
        // with current subset sum = sum

        for(int sum = 0; sum <= target; sum++){
            dp[n][sum] = abs(sum - (total - sum));
        }

        for(int index = n - 1; index >= 0; index--){

            for(int sum = target; sum >= 0; sum--){

                int notTake = dp[index + 1][sum];

                int take = INT_MAX;

                if(sum + stones[index] >= target){
                    take = abs(
                        (sum + stones[index])
                        - (total - (sum + stones[index]))
                    );
                }
                else{
                    take = dp[index + 1][sum + stones[index]];
                }

                dp[index][sum] = min(notTake, take);
            }
        }

        // TC:O(n * target ) = TC:O(n * total/2 ) = TC:O(n* total)
        // SC:O(n * total )
        return dp[0][0];

    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
         int n = stones.size() ; 

        int total = 0 ; 

        for(int stone : stones){
            total += stone ; 
        }

        int target = total / 2; // ceil ( total / 2) or just total + 2 - 1 /2 also works 

 
        vector<int> curr(target + 1  , 0 ) ;
        vector<int> next(target + 1  , 0 ) ;

        for(int sum = 0; sum <= target; sum++){
            next[sum] = abs(sum - (total - sum));
        }

        for(int index = n - 1; index >= 0; index--){

            for(int sum = target; sum >= 0; sum--){

                int notTake = next[sum];

                int take = INT_MAX;

                if(sum + stones[index] >= target){
                    take = abs(
                        (sum + stones[index])
                        - (total - (sum + stones[index]))
                    );
                }
                else{
                    take = next[sum + stones[index]];
                }

                curr[sum] = min(notTake, take);
            }
            next = curr ;
        }

        // TC:O(n * target ) = TC:O(n * total/2 ) = TC:O(n* total)
        // SC:O(total )
        return next[0];
    }
};