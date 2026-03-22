/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


class Solution {
public:

    int majorityElementI(vector<int>& nums){
        // This is majortiy element I 
        // We will make changes to solve the second question so it is good to have this as reference
        // This essentially uses Moore Voting algorithm which focuses on cancelation 

        int count = 0;
        int element = -1 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                count = 1;
                element = nums[i] ;
            }
            else if (nums[i] == element ){
                count++;
            }
            else{
                count--;
            }
        }

        // Step 2 : check if the number is actually majority 
        int cnt= 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == element){
                cnt++ ;
                if ( cnt >  (nums.size()) /2 ){
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

        // Only slight changes needed 

        //TC:O(n)
        for(int i = 0 ; i < nums.size() ; i++){

            if( cnt1 == 0 && element2 != nums[i]){
                cnt1 = 1;
                element1 = nums[i];
            }
            else if( cnt2 == 0 && element1 != nums[i]){
                cnt2 = 1;
                element2 = nums[i];
            }

            else if (nums[i] == element1 ) {
                cnt1++;
            }
            else if (nums[i] == element2 ){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        // Next for the manual check 

        cnt1 = 0 ;
        cnt2 = 0 ;

        //TC:O(n)
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == element1) cnt1++;
            if(nums[i] == element2) cnt2++; 
        }

        int mini = int(n/3) + 1;

        if(cnt1 >= mini) ans.push_back(element1);
        if(cnt2 >= mini) ans.push_back(element2);

        //TC:O(1) as ans will have at max 2 elements 
        sort(ans.begin() , ans.end());
        

        //TC:O(2n) and SC:(1) extra space 
        return ans ;
    }
};