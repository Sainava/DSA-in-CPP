/*
Problem statement
You are given an array 'a' of size 'n' and an integer 'k'.



Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
7 3
1 2 3 1 1 1 1


Sample Output 1 :
3


Explanation Of Sample Input 1 :
Subarrays whose sum = ‘3’ are:
[1, 2], [3], [1, 1, 1] and [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.


Sample Input 2 :
4 2
1 2 1 3


Sample Output 2 :
1


Sample Input 3 :
5 2
2 2 4 1 2 


Sample Output 3 :
1


Expected time complexity :
The expected time complexity is O(n).


Constraints :
1 <= 'n' <= 5 * 10 ^ 6
1 <= 'k' <= 10^18
0 <= 'a[i]' <= 10 ^ 9

Time Limit: 1-second
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

//Solution 1- Brute Force and Better Solution using Prefix Sum
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // // Brute force 
    // // Find all subarrays , return the one with sum k and longest length 

    // int maxLength = 0 ;

    // for(int i = 0 ; i < a.size() ; i++){
    //     long long sum = 0 ; 

    //     for(int j = i ; j < a.size() ; j++){
    //         sum += a[j];

    //         if(sum == k){
    //             maxLength = max(maxLength , j - i + 1);
    //         }else if( sum > k){
    //             break ;
    //         }
    //     }
    // }

    // //TC:O(n^2) and SC:O(1)
    // return maxLength;

    // Better solution - Use prefix Sum 

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
    return maxLength;
    // This works when array has positive , negative and zero as elements 
}

// Solution 2 - Optimised solution with two pointer when array has only positive and zeroes as elements
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int l = 0 ;
    int r = 0 ;
    int maxLength = 0 ;
    long long sum = 0;
    while( r < a.size()){
        // For the new window 
        sum += a[r];

        // make the window valid if invalid
        // The following is why it is important that array contains only positve and negative

        while(sum > k){
            sum -= a[l];
            l++;
        }

        // // The followig is WRONG HERE here 
        // if(sum > k){
        //     sum -= a[l];
        //     l++;
        // } 

        // If the constraint involves SUM ? always use while.
        // If the constraint involves COUNT / DISTINCT / FREQUENCY ? sometimes if works.

        // But the more fundamental rule is:
        // If the window must always stay valid ? use while.
        // If temporary invalid windows are allowed ? if may work.

        if(sum == k){
            maxLength=max(maxLength,r - l + 1);
        }

        r++;
    }

    //TC:O(n) and SC:O(1)
    return maxLength;
}