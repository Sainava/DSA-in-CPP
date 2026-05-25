/*
You are given a 2D array of integers triplets, where triplets[i] = [ai, bi, ci] represents the ith triplet. You are also given an array of integers target = [x, y, z] which is the triplet we want to obtain.

To obtain target, you may apply the following operation on triplets zero or more times:

Choose two different triplets triplets[i] and triplets[j] and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
* E.g. if triplets[i] = [1, 3, 1] and triplets[j] = [2, 1, 2], triplets[j] will be updated to [max(1, 2), max(3, 1), max(1, 2)] = [2, 3, 2].

Return true if it is possible to obtain target as an element of triplets, or false otherwise.

Example 1:

Input: triplets = [[1,2,3],[7,1,1]], target = [7,2,3]

Output: true
Explanation:
Choose the first and second triplets, update the second triplet to be [max(1, 7), max(2, 1), max(3, 1)] = [7, 2, 3].

Example 2:

Input: triplets = [[2,5,6],[1,4,4],[5,7,5]], target = [5,4,6]

Output: false
Constraints:

1 <= triplets.length <= 1000
1 <= ai, bi, ci, x, y, z <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // 2 important points , 
        // 1. We can apply the operation on the same array , so if target already exist in triplets , we can jsut apply the operation whre i and j are the same and we will get the answer
        // 2. We can apply the operation multiple times , like (i , j) gives k and then we apply operation (k,l) where l already in triplets but k is the resultant of i and j 
        
        int n = triplets.size() ; 

        bool foundX = false , foundY = false , foundZ = false ; 

        for(auto triplet : triplets ){
            int x = triplet[0] ;
            int y = triplet[1] ;
            int z = triplet[2] ; 

            // We only take the values who are 
            if( x <= target[0] && y <= target[1] && z <= target[2]){
                // We do this check , as if even one is greater than the target , the operation will pick it and not the required answer 
                if( x == target[0]) foundX = true ;
                if( y == target[1]) foundY = true ;
                if( z == target[2]) foundZ = true ;
            }
        }

        //TC:O(n) and SC:O(1)
        return foundX && foundY && foundZ ; 
    }
};
