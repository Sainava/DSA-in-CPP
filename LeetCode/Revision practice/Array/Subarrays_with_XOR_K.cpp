/*
Problem statement
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.



A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.



Example:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 2
1 2 3 2
Sample Output 1 :
3
Explanation Of Sample Input 1:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
Sample Input 2:
4 3
1 2 3 3
Sample Output 2:
4
Sample Input 3:
5 6
1 3 3 3 5 
Sample Output 3:
2
Constraints:
1 <= N <= 10^3
1 <= A[i], B <= 10^9

Time Limit: 1-sec

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int subarraysWithSumK(vector < int > a, int b) {

    int n = a.size();
    // //Brute force 
    // int cnt = 0 ;
    // for(int i = 0 ; i < n ; i++){
    //     int Xor = 0 ;
    //     for(int j = i ; j < n ; j++){
    //         Xor = Xor ^ a[j];
    //         if(Xor == b){
    //             cnt++;
    //         }
    //     }
    // }

    // //TC:O(n^2) and SC:(1)
    // return cnt;

    // Optimised 
    unordered_map<int,int> mp ;

    int prefix = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        prefix = prefix ^ a[i];

        if(prefix == b){
            cnt++;
        }

        int required = prefix ^ b;

        if(mp.find(required)!=mp.end()){
            cnt += mp[required];
        }

        mp[prefix]++;
    }
    //TC:O(n) and SC:O(n)
    return cnt ;
}