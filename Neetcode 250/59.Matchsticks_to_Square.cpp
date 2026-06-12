/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You need to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:

Input: matchsticks = [1,3,4,2,2,4]

Output: true

Example 2:

Input: matchsticks = [1,5,6,3]

Output: false
Constraints:

1 <= matchsticks.length <= 15.
1 <= matchsticks[i] <= 100,000,000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool func( int index , int req ,vector<int> &sides ,vector<int>& matchsticks ){
        // Base case 
        if(index == matchsticks.size()) return true ;

        // Try to put this in the sides 
    
        for(int i = 0; i < 4 ; i++){
            if( sides[i] + matchsticks[index] <= req){
                // May be a solution 
                sides[i] += matchsticks[index] ;

                if ( func(index + 1 , req , sides , matchsticks)) return true ; 

                // BackTrack 
                sides[i] -= matchsticks[index];
            }
        }

        return false ; // Basically false ; 

    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0 ; 

        for(int m : matchsticks){
            sum += m ;
        }

        // Now we need to divide this into 4 sides 
        if( sum % 4 != 0 ) return false ; // Say it says 2.5 for each side , that is not possible as we only have integer size mathcsticks 

        // NOW
        // Try All possible combinations so Recursion and Backtracking 
        int index = 0 ; 

        vector<int> sides(4,0) ; // Current sum for each sides -> Size 4  0 is left , 1 is top and so on 
        int req = sum / 4 ; // Each side should be of this 

        sort(matchsticks.begin() , matchsticks.end() , greater<>());

        // Question states : each matchstick must be used exactly one time.
        // Height of recursion tree is n as it ends when index == n and each level has 4 choices 

        // TC:O(4^n) and SC:O(n) for recursion stack , sides is constant and sorting is logn
        return func(index , req , sides ,matchsticks );
    }
};