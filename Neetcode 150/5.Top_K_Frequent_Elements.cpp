/*
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
Constraints:

1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // // SC:O(m)
        // unordered_map<int,int> freq ;

        // //TC:O(n)
        // for(int num : nums){
        //     freq[num]++;
        // }

        // // min heap with atmost k elements , if more than k , remove the smallest element at the root 
        // // SC:O(k)
        // priority_queue<
        //     pair<int , int> , 
        //     vector < pair<int ,int>> ,
        //     greater< pair<int , int >> 
        // > pq ; // frequency and element 

        // // Say there are m elements in freq
        // // pq.push and pq.pop have complexity logk since k elements max 
        // // TC :O(mlogk)
        // for (auto &p : freq){           

        //     pq.push({p.second,p.first});

        //     if( pq.size() > k){
        //         pq.pop(); // root element is deleted
        //     }

        // }
        // vector<int> ans ;

        // while( !pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();

        // }

        // // TC:O(n + mlogk) and SC:O(m + k)
        // return ans;

        // Solution 2 : Bucket Sort

        //SC:O(m)
        unordered_map<int,int> freq;

        //TC:O(n)
        for(int num : nums){
            freq[num]++;
        }

        // Since frequencies are from 1 to n  , we treat the index from 1 to n 
        int n = nums.size();

        //SC:O(n)
        vector<vector<int>> bucket(n+1) ;

        // TC:O(m)
        for(auto &p:freq){

            int element = p.first;
            int frequency = p.second;

            bucket[frequency].push_back(element);
        }

        vector<int> ans;
        // Now traverse from the back to get the top k 
        //TC:O(n)
        for(int i = n; i >=1 ; i--){

            for(int num : bucket[i]){

                ans.push_back(num);

                if(ans.size() == k){
                    return ans ;
                }
            }
        }

        //TC:O(n + m)
        //SC:O(n + m)
        return ans;
    }
};
