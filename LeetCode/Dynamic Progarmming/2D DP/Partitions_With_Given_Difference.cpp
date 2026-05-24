/*
Problem statement
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains two space-separated integers, ‘N’ and ‘D,’ denoting the number of elements in the array and the desired difference.

The following line contains N integers denoting the space-separated integers ‘ARR’.
Output Format :
For each test case, find the number of partitions satisfying the above conditions modulo 10^9 + 7.
Output for each test case will be printed on a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 50
0 ≤ D ≤ 2500
0 ≤ ARR[i] ≤ 50

Time limit: 1 sec
Sample Input 1 :
2
4 3
5 2 6 4
4 0
1 1 1 1
Sample Output 1 :
1
6
Explanation For Sample Input 1 :
For test case 1:
We will print 1 because :
There is only one possible partition of this array.
Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3

For test case 2:
We will print 6 because :
The partition {1, 1}, {1, 1} is repeated 6 times:
Partition 1 : {ARR[0], ARR[1]}, {ARR[2], ARR[3]}
Partition 2 : {ARR[0], ARR[2]}, {ARR[1], ARR[3]}
Partition 3 : {ARR[0], ARR[3]}, {ARR[1], ARR[2]}
Partition 4 : {ARR[1], ARR[2]}, {ARR[0], ARR[3]}
Partition 5 : {ARR[1], ARR[3]}, {ARR[0], ARR[2]}
Partition 6 : {ARR[2], ARR[3]}, {ARR[0], ARR[1]}
The difference is in the indices chosen for the subset S1(or S2).
Sample Input 2 :
3
3 1
4 6 3
5 0
3 1 1 2 1
5 1
3 2 2 5 1
Sample Output 2 :
1
6
3
*/
#include <iostream>
#include <vector>
using namespace std; 


int mod = (int)(1e9 + 7) ;
int func(int index , int remaining , int n ,vector<int> &arr , vector<vector<int>> &dp){

    // Base Case 
    if(index == 0 ){
        if (remaining == 0 && arr[0] == 0 ) return 2 ; // As we can take or not take and it will not make a difference
        if( remaining == 0 ||  arr[0] == remaining) return 1 ; // Arr[0] is not 0
        return 0 ;
    }

    if(dp[index][remaining] != -1 ) return dp[index][remaining] ;

    int notTake = func(index - 1 , remaining , n , arr , dp) % mod;

    int take = 0 ; 
    if( arr[index]<= remaining){
        take = func(index - 1 , remaining - arr[index] , n , arr ,dp) % mod;
    }
     

    return dp[index][remaining] = (notTake % mod + take % mod) % mod ; 

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
        
    //         dp[index][remaining] = (notTake % mod + take % mod) % mod ;
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
        
            curr[remaining] = (notTake % mod + take % mod) % mod ;
        }

        prev = curr ;
    }

    return prev[target] ; 

}


