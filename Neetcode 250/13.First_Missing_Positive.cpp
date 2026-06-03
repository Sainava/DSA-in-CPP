/*
You are given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [-2,-1,0]

Output: 1
Example 2:

Input: nums = [1,2,4]

Output: 3
Example 3:

Input: nums = [1,2,4,5,6,3,1]

Output: 7
Constraints:

1 <= nums.length <= 100,000
-(2^31) <= nums[i] <= ((2^31)-1)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // There are 3 solutions 
        
        // Solution 1 

        int n = nums.size();
        sort(nums.begin() , nums.end());

        int ans = 1 ; // As this can be the lowest positive integer
        // Possible answers can be [ 1 ,2 ,3 ...., n,n+1]
        // We cannot have an answer greater than n+1 
        // Eg : Ans cannot be n+2 as that would mean 1 till n+1 exist in array 
        // But these are n + 1 numbers and nums is of size n so not possible 

        for(int i = 0 ; i < n ; i++){
            
            if( nums[i] == ans ){
                // This is not the answer , lets try the next integer 
                ans++;
            }
            else if (nums[i] > ans){
                // We have found our answer as we now everything to the left will also be greater
                return ans ;
            }
        }

        //TC:O(nlogn) and SC:O(1)
        return ans ; // Maximum ans : n + 1 
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // There are 3 solutions 
        
        // Solution 2
        // Possible answers can be [ 1 ,2 ,3 ...., n,n+1]
        // We cannot have an answer greater than n+1 
        // Eg : Ans cannot be n+2 as that would mean 1 till n+1 exist in array 
        // But these are n + 1 numbers and nums is of size n so not possible 

        // We need to optimise space so we basically go from 1 till n+1 and see if that ans exist in nums
        // we need quick check to see if that number exist so we use hash set

        int n = nums.size() ;
        unordered_set<int> st ;

        for(int num : nums){
            st.insert(num);
        }

        int minAns = 1;
        int maxAns = n+1 ;

        for(int i = minAns ; i < maxAns ;i++){
            if(!st.count(i)){
                return i ;
            }
        } 

        // if did not return there , means ans is maxAns;
        //TC:O(n) and SC:O(n)
        return maxAns;
         
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // There are 3 solutions 
        
        // Solution 3
        int n = nums.size();

        // We now need to optimise space 
        // We used hashSet to see if the number exist in not in O(1) time 
        // We need to do  this in constant time 
        // For that we will use the original nums 

        // Basic Idea we know ans can be from [1 - n+1]
        // nums has size n so we map 1 to index 0 , 2 to index 1 and so on 
        // If number exist we mark that index as negative
        // Meaning if 1 exist , index 0 will have a negative number 
        // Problem is nums already may have negative numbers , those are of no use to us so we make them zero 

        // Step 1 : Make preExisting numbers zero 
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0) nums[i] = 0 ;
        }

        // step 2 : Do the mapping if that number exists , make corresponding index negative

        for( int i = 0 ; i < n ; i++){
            int element = abs(nums[i]) ; // Abs as it is possible we may have marked this index as negative

            int index = element - 1;

            if( index >= 0 && index < n){
                // Now consider this case ,
                // Say we have 2 so we get index = 1 but at index 1 we have 0 so making it negative makes no difference 
                // We handle this case separately 
                //  We cannot just make it negative as say we make it -1 then later when we arrive here we may think 1 exist so we have to make a number that does it exist so -(n+1)
                if(nums[index] == 0 ){
                    nums[index] = -(n+1) ; 
                }
                else{
                    nums[index] = -abs(nums[index]);
                }
                
            }
        }

        // Step 3 just check the answer 
        int minAns = 1 ;
        int maxAns = n + 1 ;

        for(int i = minAns ; i < maxAns ; i++){
            int index = i - 1 ;
            
            if(nums[index] >= 0) return i ; 
            // if nums[index] == 0 ; it is also answer as we never needed to change that index so number corresponding to that index does not exist 
            // Hence in original loop if we found a number and in index corresponding to that number 0 existed we needed to change that  
        }

        // If it reached here ans is maxAns 
        //TC:O(n) and SC:O(1)
        return maxAns ; 
    }
};