/*
You are given an array of integers nums and an integer target.

For each number in the array, you can choose to either add or subtract it to a total sum.

For example, if nums = [1, 2], one possible sum would be "+1-2=-1".
If nums=[1,1], there are two different ways to sum the input numbers to get a sum of 0: "+1-1" and "-1+1".

Return the number of different ways that you can build the expression such that the total sum equals target.

Example 1:

Input: nums = [2,2,2], target = 2

Output: 3
Explanation: There are 3 different ways to sum the input numbers to get a sum of 2.
+2 +2 -2 = 2
+2 -2 +2 = 2
-2 +2 +2 = 2

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
-1000 <= target <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int func(int index , int remaining , int n ,vector<int> &arr , vector<vector<int>> &dp){

    // Base Case 
    if(index == 0 ){
        if (remaining == 0 && arr[0] == 0 ) return 2 ; // As we can take or not take and it will not make a difference
        if( remaining == 0 ||  arr[0] == remaining) return 1 ; // Arr[0] is not 0
        return 0 ;
    }

    if(dp[index][remaining] != -1 ) return dp[index][remaining] ;

    int notTake = func(index - 1 , remaining , n , arr , dp);

    int take = 0 ; 
    if( arr[index]<= remaining){
        take = func(index - 1 , remaining - arr[index] , n , arr ,dp);
    }
     

    return dp[index][remaining] = (notTake+ take ) ; 

}



int countPartitions(int n, int d, vector<int> &arr) {
   // Needed S1 - S2 = D
   // Also S1 + S2 = Total Sum 
   // So we have S1 = (Total Sum + D ) / 2
   // So basically find the no of subsets whose sum is sum is (Total Sum + D ) / 2

    int totalSum = 0 ; 

    for(int num:arr){
        totalSum+= num;
    }

     // Impossible cases
    if(totalSum < d)
        return 0;

    // It needs to be even or else dividing by half will give foating points and sum not possible 
    if((totalSum + d) % 2 != 0)
        return 0;

    int target = (totalSum + d ) / 2; 

    // // Top - Down 
    // vector<vector<int>> dp(n , vector<int> (target+1 , -1));
    // int index = n - 1;
    // // TC:O(n*target) and SC:O(n*target)
    // return func(index , target , n , arr ,dp) ;


    // // Bottom Up
    // vector<vector<int>> dp(n , vector<int> (target+1 , 0));
    
    // // Base cases 
    // if(arr[0] == 0 ) dp[0][0] = 2 ; //if (remaining == 0 && arr[0] == 0 )
    // else dp[0][0] = 1 ; // At index 0 and remaining is 0 but arr[0] so we do not take this , one way so 1 
    // if(arr[0]!= 0 && arr[0] <= target) dp[0][arr[0]] = 1;// like num[0] = 5 and remaining is 5 

    // for(int index = 1 ; index < n ; index++){
    //     for(int remaining = 0 ; remaining <= target ; remaining++){
    //         int notTake = dp[index - 1][remaining];

    //         int take = 0 ; 
    //         if( arr[index]<= remaining){
    //             take = dp[index - 1][remaining - arr[index]] ;
    //         }
        
    //         dp[index][remaining] = (notTake  + take )  ;
    //     }
    // }

    // return dp[n-1][target] ; 

    //Space Optimised 
    vector<int> prev(target+1 , 0) ; 
    vector<int> curr(target+1 , 0) ;

    if(arr[0] == 0 ) prev[0] = 2 ; //if (remaining == 0 && arr[0] == 0 )
    else prev[0] = 1 ; // At index 0 and remaining is 0 but arr[0] so we do not take this , one way so 1 
    if(arr[0]!= 0 && arr[0] <= target) prev[arr[0]] = 1;// like num[0] = 5 and remaining is 5 

    for(int index = 1 ; index < n ; index++){
        for(int remaining = 0 ; remaining <= target ; remaining++){
            int notTake = prev[remaining];

            int take = 0 ; 
            if( arr[index]<= remaining){
                take = prev[remaining - arr[index]] ;
            }
        
            curr[remaining] = (notTake + take) ;
        }

        prev = curr ;
    }

    return prev[target] ; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Basically what this question is asking 
        // Add plus sign to sum 
        // Add negative sign to sum 
        // Now say we add all positive signs = Say that sum is S1 
        // Now say we take negative sign of all negative and add = say we get -S2
        // So essentailly it becomes S1 - S2 = target 

        // This is basically the same as partition array into two subsets with difference target 
        int n = nums.size() ; 
        return countPartitions(n, target ,nums) ;
    }
};
