/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std ;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // We can consider this question to be 
        // Maximum Subarray ( since select consecutive fruits ) with atmost 2 unique fruits (atmost since picking this one type of fruit (in the case of all same fruits ) is also possible )


        // // Brute force -- All subarrays 
        // int maxLength = 0 ;
        // for(int i  = 0 ; i < fruits.size() ; i++){
        //     set<int> st;
        //     for(int j = i ; j < fruits.size() ; j++ ){
        //         st.insert(fruits[j]);
        //         if(st.size() <= 2){
        //             maxLength = max(maxLength , j - i + 1);
        //         }else{
        //             break;
        //         }
        //     }
        // }

        // //TC :O(n^2) and SC:O(1)
        // // TC of insertion i set is O(k) where k is size of set but since we never let size of set exceed 2 , TC for set O(1) and overall TC:O(n^2)
        // return maxLength;

        // Optimised using sliding window 
        int l = 0;
        int r = 0 ;
        int maxLength = 0 ;
        unordered_map<int,int> mp ; // type of fruit and its count 

        while ( r < fruits.size()){
            // Create the new window 
            mp[fruits[r]] ++ ;

            // Make the window valid 
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }

            if( mp.size() <= 2){ 
                maxLength = max(maxLength , r - l + 1);
            }

            r++;
        }

        // More optimised 
        while ( r < fruits.size()){
            // Create the new window 
            mp[fruits[r]] ++ ;

            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }

            if( mp.size() <= 2){ 
                maxLength = max(maxLength , r - l + 1);
            }

            r++;
        }

        //TC:O(n) and SC:O(1) // Since size of map is constant 
        return maxLength;
        
    }
};