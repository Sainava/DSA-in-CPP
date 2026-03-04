/*
Problem statement
Ninja and his friend are playing a game of subarrays. They have an array ‘NUMS’ of length ‘N’. Ninja’s friend gives him an arbitrary integer ‘K’ and asks him to find the length of the longest subarray in which the sum of elements is equal to ‘K’.

Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to ‘K’.

If there is no subarray whose sum is ‘K’ then you should return 0.

Example:
Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]

Output: 4

There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^5
-10^6 <= NUMS[ i ] <= 10^6
-10^6 <= K <= 10^6

Sum of N Over all the Test cases <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
3 5
2 3 5
3 1
-1 1 1
Sample Output 1 :
2
3
Explanation Of Sample Input 1 :
For the first case:
There are two subarrays with sum = 5, [2, 3] and [5]. Hence the length of the longest subarray is 2.

For the second case:
Longest subarray with sum = 1 is [1, -1, 1].
Sample Input 2 :
2
3 4
1 1 1
3 2
-50 0 52
Sample Output 2 :
0 
3

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;


int getLongestSubarray(vector<int>& a, int k){
    // Prefix - Cumulative sum till the current element 

    int maxLength = 0 ;
    long long prefixSum = 0 ;

    // Hasp map to store indices of prefix sum that will help us to find length of required subarrays 
    unordered_map<long long , int > mp ; // <prefixSum , index till this sum >

    for(int i =0 ; i < a.size() ; i++){
        prefixSum += a[i];

        // Case 1 - If prefix sum is equal to required sum k
        if(prefixSum == k){
            maxLength = max(maxLength , i + 1);
        } 

        // Case 2 : Say PrefixSum is s , required sum is k , we see if there exist subarray with sum x - k
        long long required = prefixSum - k ;

        // TC of mp.find is O(1) average , the worst case if O(n) but that is only in case of collisions and bad hashing function which is rare 
        if(mp.find(required)!= mp.end()){
            // Till prefixSum , index is i 
            int length = i - mp[required];
            maxLength = max(maxLength , length); 
        }
        
        // Now only add to map if the prefixSum was not there previously 
        // Index changes but sum does not chnages means there are zeroes , since we need longest , we only store the leftmost index 
        if(mp.find(prefixSum)== mp.end()){
            mp[prefixSum] = i ;
        }


    }

    //TC:O(n) and SC:O(n)
    // For Ordered_map ; TC:O(n logn) always as no collisions
    // For unordered_map : TC:O(n) as average but worst O(n^2) when collisions happen
    return maxLength;
    // This works when array has positive , negative and zero as elements and is the most Optimised 
}