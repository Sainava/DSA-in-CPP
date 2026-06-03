/*
You are given an integer array nums of size n, find all elements that appear more than ⌊ n/3 ⌋ times. You can return the result in any order.

Example 1:

Input: nums = [5,2,3,2,2,2,2,5,5,5]

Output: [2,5]
Example 2:

Input: nums = [4,4,4,4,4]

Output: [4]
Example 3:

Input: nums = [1,2,3]

Output: []
Constraints:

1 <= nums.length <= 50,000.
-1,000,000,000 <= nums[i] <= 1,000,000,000
Follow up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElementI(vector<int>& nums){
        // This is majortiy element I 
        // We will make changes to solve the second question so it is good to have this as reference
        // This essentially uses Moore Voting algorithm which focuses on cancelation 

        int n = nums.size() ; 
        int cnt = 0;
        int element = -1 ; 
        
        for(int i = 0 ; i < n ; i++){
            if( cnt == 0 ){
                cnt = 1 ;
                element = nums[i];
            } 
            else if (nums[i] == element ){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        // Now check if answer is correct 
        int finalCnt = 0 ; 

        for(int i = 0 ; i < n ; i++){
            if( nums[i] == element ){
                finalCnt ++ ;
                if( finalCnt > n/2){
                    return element ; 
                }
            }
        } 

        return -1 ; 

    }

    vector<int> majorityElement(vector<int>& nums) {
       // Here since the majority elements will be in number >= n/3 .
        // Max 2 majority elements can exists , no greater .

        int n = nums.size() ; 

        // ans will have at max 2 elements so we can treat as constant space SC:O(1)
        vector<int> ans ;

        int cnt1 = 0 ;
        int cnt2 = 0 ;

        int element1 = INT_MIN ;
        int element2 = INT_MIN ;

        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            if( cnt1 == 0 && element2 != nums[i]){
                cnt1 = 1 ;
                element1 = nums[i];
            }
            else if(cnt2 == 0 && element1 != nums[i]){
                cnt2 = 1 ;
                element2 = nums[i] ;
            }
            else if(nums[i] == element1){
                cnt1++;
            }
            else if(nums[i] == element2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        // Now we need to check if our answer is right 
        cnt1 = 0 ;
        cnt2 = 0 ;

        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            if( nums[i] == element1) cnt1++;
            if( nums[i] == element2) cnt2++;
        }

        int mini = (n/3) + 1;

        if(cnt1 >= mini) ans.push_back(element1);
        if(cnt2 >= mini) ans.push_back(element2);

        //TC:O(1) as size is constant
        sort(ans.begin() , ans.end());

        //TC:O(n) and SC:O(1) extra space 
        return ans;
    }
};