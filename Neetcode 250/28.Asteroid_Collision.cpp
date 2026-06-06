/*
You are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [2,4,-4,-1]

Output: [2]
Example 2:

Input: asteroids = [5,5]

Output: [5,5]
Example 3:

Input: asteroids = [7,-3,9]

Output: [7,9]
Constraints:

2 <= asteroids.length <= 10,000.
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size() ;

        stack<int> st ;

        //TC:O(n) as each pushed and pop exactly once 
        for(int i = 0 ; i < n ; i++){
            int curr = asteroids[i] ; 
            bool isAlive = true ; 

            while(isAlive &&  !st.empty() && (st.top() > 0 && curr < 0)){
                // Collison condition 

                if( abs(curr) > st.top()){
                    // curr will destroy it 
                    st.pop();
                }
                else if ( abs(curr) < st.top()){
                    // asteroid destroyed 
                    isAlive = false ; 
                }
                else{
                    // Both destroyed 
                    st.pop();
                    isAlive = false ; 
                }
            }

            if( isAlive) st.push(curr);
        }
        vector<int> ans ; 

        //TC:O(n)
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        //TC:O(n)
        reverse(ans.begin() , ans.end());

        //TC:O(n) and SC:O(n)
        return ans ; 
    }
};