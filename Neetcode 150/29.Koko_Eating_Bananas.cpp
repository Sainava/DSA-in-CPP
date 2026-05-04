/*
You are given an integer array piles where piles[i] is the number of bananas in the ith pile. You are also given an integer h, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer k such that you can eat all the bananas within h hours.

Example 1:

Input: piles = [1,4,3,2], h = 9

Output: 2
Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.

Example 2:

Input: piles = [25,10,23,4], h = 4

Output: 25
Constraints:

1 <= piles.length <= 1,000
piles.length <= h <= 1,000,000
1 <= piles[i] <= 1,000,000,000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(int k , vector<int>& piles, int h){
        int hrs = 0 ; 

        for(int pile :piles){
            // hrs += ceil(pile / k); pile / k  will give int so no use 
            // hrs += ceil( (float)pile / k); will work but not efficient 

            // Trick ceil(a/b) is (a+b-1) / k;

            hrs += (pile + k - 1)/k;
            if(hrs> h ) return false;
        }

        return true ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int start = 1 ; // k = 1 , one banana per hour 

        int maxi = INT_MIN;

        //TC:O(n)
        for(int pile:piles){
            maxi = max(maxi , pile);
        }

        int end = maxi ; // k = size of max pile ,this would give hours as length of piles  , this is the shortes time we can have 

        // So k is from 1 to max(piles) 
        // In this search space as k increases time decreases and if k decreases time increases
        // If at a value of k , it exceeds hours , then decreasing k would also exceed hour and hence we can eliminate tht apart of search space 
        // if at k we get a value , then better value of k would only be possible on decreasing k , so again we can eliminate search space 
        // so we use binary search on search space of k from 1 to k ;

        int ans = end ;

        //TC:O(nlog(max(pile))) (nlog(end - start)) == nlog(max(pile))
        // As loop runs log(max(pile)) times and each time isPossible has complexity n
        while (start <= end ){
            int k = start + ( end - start ) /2 ;

            if(isPossible(k , piles , h)){
                ans = k ;
                end = k - 1;
            }else{
                start = k + 1;
            }

        }

        //TC:O(n + nlog(max(pile)) and SC:O(1)
        return ans ;
    }
};
