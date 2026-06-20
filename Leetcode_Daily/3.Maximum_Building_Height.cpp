// 20 June 2026

// 1840. Maximum Building Height

/*
You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

Return the maximum possible height of the tallest building.

 

Example 1:


Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
Example 2:


Input: n = 6, restrictions = []
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
Example 3:


Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
 

Constraints:

2 <= n <= 109
0 <= restrictions.length <= min(n - 1, 105)
2 <= idi <= n
idi is unique.
0 <= maxHeighti <= 109

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Recursion will not work as suppose restrictions are building 5 ≤ 3 and building 20 ≤ 7
        // If I do recursion or if I CONSIDER just ONE INDEX WISE we may ran into trouble later on 
        // Say if building 5 is atmost height(3) then 6 will be atmost height(4) , 7 - atmost height(5) and so on . 
        // When we reach building 20 we realise that the prvious buildings make it impossible to have height 7 without breaking restriction of height difference 1 

        // So the key idea here is we cannot look building wise 
        // But we can look range wise 
        // If I know the maxHeight at two restrcited conditions ( i , hi) and (j , hj) with i < j 

        // For any two restricted buildings i and j:
        //
        // Since adjacent buildings can differ by at most 1,
        // the height difference between them cannot exceed
        // their distance:
        //
        //      |h[j] - h[i]| <= |j - i|
        //
        // Therefore a restriction at one building imposes
        // an upper bound on nearby restricted buildings.
        //
        // Left -> Right pass:
        // If building i can be at most h[i],
        // then building j can be at most
        //
        //      h[i] + (j - i)
        //
        // so tighten:
        //
        //      h[j] = min(h[j], h[i] + (j - i))
        //
        // Right -> Left pass:
        // The same logic works in reverse.
        // If building j can be at most h[j],
        // then building i can be at most
        //
        //      h[j] + (j - i)
        //
        // so tighten:
        //
        //      h[i] = min(h[i], h[j] + (j - i))
        //
        // We need both passes because a restriction can
        // reduce feasible heights on either side.

        restrictions.push_back( { 1 , 0 });// Implicit restriction 
        // If restrictions is empty -> Ans is ( n - 1 ) for building n 
        // But we only add this if not already present

        sort(restrictions.begin() , restrictions.end()) ;
        
        if( restrictions.back()[0] < n  ) {
            restrictions.push_back({ n , n-1}) ; 
        }

        // Forward pass -> Increase case -> A building is restricted by another building before it 
        for(int ind = 1 ; ind < restrictions.size() ; ind++ ){
            int j = restrictions[ind][0] ; 
            int hj = restrictions[ind][1] ;

            int i = restrictions[ind - 1][0] ; 
            int hi = restrictions[ind - 1][1] ;

            // Now from i to j we can only have a strict increase of j - i 
            // And building 1 is 0 makes sure the restrictions are passed correctly from left to right 

            hj = min( hj ,hi +  j - i);
            restrictions[ind][1] = hj ;

        }

        // Backward pass ->  A building is restricted by another building before it 
        for(int ind = restrictions.size() - 2 ; ind >=0  ; ind-- ){
            int i = restrictions[ind][0] ; 
            int hi = restrictions[ind][1] ;

            int j = restrictions[ind + 1][0] ; 
            int hj = restrictions[ind + 1][1] ;

            // Now from j to i we can only have a strict increase of j - i 

            hi = min( hi ,hj + j - i);
            restrictions[ind][1] = hi ;

        }

        // Basically the first pass handles the case where from i to j it is increasing 
        // And second pass handles the case where from i to j it is decreasing 

        //After the two passes, every restricted point contains its maximum feasible height.
        // But we cannot give answer from it yet as it does not have all the indices or buildings 

        // Say we have two restricted building i and j 

        // We can have a case that the height increases from i until peak and from peak onwards it decreases so that is satisfies the condtion for j 
        // In this case peak will the highest height building 
        // The question is How high can the peak become before it must start descending to reach hj?

        // Let d = j - i
        // Suppose the peak height is P.
        // Then:

        // P - hi <= distance from i to peak
        // P - hj <= distance from peak to j
        // Adding them:
        // (P-hi) + (P-hj) <= d
        // which gives
        // 2P <= hi + hj + d
        // So:
        // P <= (hi + hj + d)/2
        int maxHeight = 0 ;
        for(int ind = 1 ; ind < restrictions.size() ; ind++){
            int j = restrictions[ind][0] ; 
            int hj = restrictions[ind][1] ;

            int i = restrictions[ind - 1][0] ; 
            int hi = restrictions[ind - 1][1] ;

            int d = j - i ;

            int peak = (hi + hj + d)/2 ; 

            maxHeight = max(maxHeight , peak) ;

        }

        //TC: O(m log m) and SC: O(log m) where m = restrictions.size()
        return maxHeight ; 
    }
};