/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int checkSign( int a){
        if ( a > 0 ) return 1;
        else if ( a == 0 ) return 0 ;
        else return -1;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;

        st.push(asteroids[0]);

        //TC:O(2n) in the worst case 
        for(int i = 1 ; i < n ; i++){
            int curr = asteroids[i];

            bool destroyed = false ;

            while( !st.empty() && st.top() > 0 and curr<0)

                //case 1 : if top is greater than or equal to curr

                if( abs(st.top()) > abs(curr)){
                    // curr is destroyed 
                    destroyed = true ;
                    break;
                }else if (abs(st.top()) == abs(curr)){
                    //both destroyed 
                    destroyed = true ;
                    st.pop();
                    break;
                }
                else{

                    // curr destroyed the top , now we keep checking if it can destroy more of previous 
                    st.pop();
                }

            if( !destroyed){
                // we need to push curr
                st.push(curr);
            }
           
        }

        vector<int> ans ; 
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        //TC:O(n) and SC:O(n)
        return ans;
    }

};