/*
You are given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
Example 1:

Input: arr = [2,4,5,8], k = 2, x = 6

Output: [4,5]
Example 2:

Input: arr = [2,3,4], k = 3, x = 1

Output: [2,3,4]
Constraints:

1 <= k <= arr.length <= 10,000.
-10,000 <= arr[i], x <= 10,000
arr is sorted in ascending order.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<
            pair<int , int >
        > pq ;

        int n = arr.size() ; 

        for(int i = 0 ; i < n ; i++){
            int dist = abs( arr[i] - x) ;

            pq.push({dist , arr[i]});

            if( pq.size() > k) pq.pop() ; 
        }
        vector<int> ans ; 

        while(!pq.empty()){
            ans.push_back(pq.top().second) ; 
            pq.pop() ; 
        }


        // The answer should be sorted in order of elements and not the distance so just sort
        sort(ans.begin() , ans.end());

        //TC:O(nlogk + klogk)  nlogk  for pq push and pop and klogk for sorting the k elements in answer 
        //and SC:O( k ) for priority queue and SC:O(logn) for sorting 
        return  ans ;
    }
};