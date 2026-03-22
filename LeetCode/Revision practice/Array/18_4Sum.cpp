/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std ;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        // // Brute 
        // set<vector<int>> st;

        // for(int i = 0 ; i < n ; i ++){
        //     for(int j = i+1 ; j < n ; j++){
        //         for(int k = j+1 ; k < n ; k++){
        //             for(int l = k+1 ; l < n ; l++){

        //                     long long ans = nums[i] + nums[j] ;
        //                     ans += nums[k] ;
        //                     ans += nums[l] ;

                            

        //                     if(ans==target){

        //                         // Constant space 
        //                         vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]} ;
        //                         sort(temp.begin() , temp.end());
        //                         st.insert(temp);
        //                     } 
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>> ans( st.begin() , st.end());
        // //TC:O(n^4) and SC:O(no of qudruplets)
        // return ans;


        //Better 
        set<vector<int>> st;

        for(int i = 0 ; i < n ; i ++){
            for(int j = i+1 ; j < n ; j++){
                set<long long> hashset ;
                for(int k = j+1 ; k < n ; k++){

                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    int fourth = target - sum;

                    // Search in the set 
                    if(hashset.find(fourth)!=hashset.end()){

                        vector<int> temp = {nums[i] , nums[j] , nums[k] , fourth};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);

                }
            }
        }

        vector<vector<int>> ans( st.begin() , st.end());
        //TC:O(n^3) * log(m) -- m is variable to stote unique elements between j and k 
        // and SC:O(no of qudruplets) + O(n) , n for the hashset
        return ans;

    }
};

// Optimal solution - Two pointer approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // Optimal solution 

        vector<vector<int>>  ans ;

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++ ) {
            if( i > 0 && nums[i]==nums[i-1]) continue;

            for(int j = i + 1 ; j < nums.size() ; j++){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;
                

                // Now try two pointer approach here 
                int k = j + 1 ;
                int l = nums.size() - 1;
    
                while( k < l){
                    long long sum = nums[i] ;
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int> temp = {nums[i] , nums[j] ,nums[k] ,nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while( k < l && nums[k]==nums[k-1]) k++;
                        while( l > k && nums[l]==nums[l+1]) l--;

                    }
                    else if(sum > target){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }

        //TC:O(n^3) and SC:O(1) extra space
        return ans ;
    }
};