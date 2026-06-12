/*
You are given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 3, k = 2

Output: [
    [1,2],
    [1,3],
    [2,3]
]
Example 2:

Input: n = 3, k = 3

Output: [[1,2,3]]
Constraints:

1 <= k <= n <= 20
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void func(int index , int n , int k ,vector<int> &temp , vector<vector<int>> &ans){
        // Base Case 
        if( temp.size() == k ){
            ans.push_back(temp) ;
            return ;
        }

        // Goes from index to n and not from 1 to n as we want to avoid duplicate combinations -> think [1,2] and [2,1] are the same 
        for(int i = index ; i <= n ; i++){
            temp.push_back(i);
            func( i + 1 , n , k , temp , ans);
            temp.pop_back() ; // BackTrack 
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // Basically nCk

        // Return all combinations so recursion 
        vector<vector<int>> ans ; 
        vector<int> temp ; // Will be of size k 

        int index = 1 ; // Imagine an array of [1...n] with 1 based indexing

        func( index , n , k , temp , ans ); 

        // Think of the recursion tree 
        // There are k levels and first level has n choices and then second level has ( n-1 + n-2 + n-3 and so on )

        // SO an approximate bound is TC:O(k * n^k) ( multiplied by k as we need to copy temp to answer)
        // More approximate TC:O( k * n! / (n-k)! * k! ) -> Basicallu k * no of  combination formula 
        // SC:O(k) for tree depth . SC:O(K) for temp and SC:O(x*k) for answer where x is the number of answers 
        return ans ;

    }
};