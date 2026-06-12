/*
You are given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [2,4,1,3,5], k = 3

Output: true
Explanation: Given array can be divided into three subsets [5], [2,3], [4,1].


Example 2:

Input: nums = [1,2,3,4], k = 3

Output: false
Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 10,000
The frequency of each element is in the range [1, 4].

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool func(int index , int n , int target ,int currSum , vector<bool> &taken ,vector<int>& nums , int k){
        // MAIN BASE CASE 
        if( k == 0) return true ; // k==1 return works and is faster as we have know that sum(nums) = x* k and solution can be made so if only one subset is left , the remaining elements will form it so we do not check for it

        if(currSum == target){
            // Call the func again for the next subset 
            return func(0 , n , target , 0 , taken , nums ,k - 1) ; // index and currSum back to 0 and k - 1 
        }

        // We start at index because we can assume we have already taken index - 1 
        for(int i = index ; i < n ; i++){
            if( taken[i] || currSum + nums[i] > target ) continue ;

            taken[i] = true ; 
            currSum += nums[i];

            if (func(i + 1 , n , target , currSum , taken , nums , k)) return true ;

            // Backtrack 
            taken[i] = false ; 
            currSum -= nums[i];
        }

        return false ; 
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // So we need k subsets each of same sum x , and partition so all elements need to be used and partitions should be mutually exclusive
        // So k * x = sum(nums)
        // Sum of each subset -> x = sum(nums) / k 

        int n = nums.size() ; 
        int sum = 0 ;

        for(int num : nums){
            sum += num ;
        }

        if ( sum % k != 0 ) return false ; 

        int target = sum / k ;

        vector<bool> taken( n , false) ; // Keeps track of what we have taken thus far 

        // Now for each element we do two choices 
        // Either we take it or no .
        // But we do it k times for k subsets  . But we cannot do a dfs and call it k times as we cannot lock in an answer and then see if the remaining nums can find the other subsets , we need to do this in one go 

        // SO say if we did something like 
        // for(int i = 0 ; i < k ;i++){
            //func()
        // }

        // This might us wrong answer 
        // As we for one subset we lock in x1 , x2. We have made a permanent decision 
        // Now the rest of nums ( nums - {x1,x2}) need to find the remaining subsets 
        // But we may not find this so we return false .
        // But it may be so that x1 cannot find a valid answer with x2 but can with x3 
        // SO {x1,x3} can give rise to all possible remaining subsets 
        // In this loop approach we lock in {x1,x2} as soon as we get it 
        // But when we call func with k as parameted . On finding {x1,x2} ,it will continue and on not finding global correct answer
        // The backtrack will remove x2 and we can still have {x1,x3}

        int index = 0 ; 
        int currSum = 0 ; 

        // Sort in reverse 
        sort( nums.rbegin() , nums.rend()) ; // makes the code faster by backtracking and pruning faster

        if( nums[0] > target) return false ; // As this element cannot be taken in any subset 

        //Time: O(k · 2^n)   (rough upper bound)
        // Time Complexity:
        // O(k * 2^n) (rough upper bound; backtracking explores subsets)
        //
        // Space Complexity:
        // O(n)
        // - O(n) recursion stack
        // - O(n) taken array
        return func(index ,n , target , currSum , taken, nums , k  );
        
    }
};