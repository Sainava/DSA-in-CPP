/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
*/
#include<iostream>
#include<vector>
using namespace std ;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        // You can pick up k from the start or k from the end or some from front and some from end such that total is k cards 

        // CONSTAINT WINDOW PROBLEM SO USE SLIDING WINDOW 

        // Approach : Try all such combinations that i wrote above 

        int n = cardPoints.size();

        int leftSum = 0 ;
        int rightSum = 0 ;

        int left = k  - 1  ;
        int right = n - 1  ;

        // First window 
        //TC:O(k)
        for(int i = 0 ; i < k ; i++){
            leftSum += cardPoints[i];
        }

        int maxSum = leftSum ;// Store the first window 

        // For the next windows , remove one from the leftwindow and add one from the right 
        //TC:O(K) since left goes from k-1 to 0 
        while (left >= 0){
            // Step 1 - Create the next window 
            leftSum = leftSum - cardPoints[left];
            left--;

            rightSum = rightSum + cardPoints[right];
            right--;

            int sum = leftSum + rightSum ;
            
            maxSum = max(maxSum, sum);
        }

        //TC : O(K) and SC:O(1)
        return maxSum;


    }
};