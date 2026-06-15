/*
You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

Example 1:

Input: nums = [4,3,12]

Output: true
Explanation: There exists three possible pairsof indices. For each pair, the sequence of traversals are:

(0,1) -> [0,2,1]
(0,2) -> [0,2]
(1,2) -> [1,2]

Example 2:

Input: nums = [2,3,7]

Output: false
Constraints:

1 <= nums.length <= 100,000
1 <= nums[i] <= 100,000

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU{
    public:
        vector<int> parent ; 
        vector<int> rank ;

        int count ; // IMPORTANT -> NO of components of disjoint set or graph 
        // We decrement each time union set is called 

        DSU(int n){
            parent.resize(n);

            rank.resize(n,0);

            count = n ; 

            for(int i = 0 ; i < n ; i++){
                parent[i] = i ;
            }
        }

        int findParent(int u){
            if(parent[u] == u) return u ;

            return parent[u] = findParent(parent[u]);
        }


        void unionSet(int u , int v){
            u = findParent(u);
            v = findParent(v);


            if( rank[u] < rank[v]){
                parent[u] = v;
            }
            else if( rank[v] < rank[u]){
                parent[v] = u ;
            }
            else {
                parent[v] = u;
                rank[u]++ ; 
            }
        
        count-- ; // IMPORTANT 
        }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        //WATCH NEETCODE VIDEO AND DO DRY RUNS 
        // DIFFICULT QUESTION 

        int n = nums.size() ;

        DSU dsu(n) ; 

        unordered_map<int,int> factor_index;  //prime factor -> index of the number it is prime factor of 
        // We basically only store one index or one element -> because we treat it like the parent of that set 
        // So multiple numbers could have this as a prime factor . And we just attach it to the parent of that set
        // We store elements as there can be duplicate elements 

        for(int i = 0 ; i < n ; i++){
            int num = nums[i];

            // Now we need the prime factors of num other than 1 ofcourse 
            // We do this sqrt(num) because after that it is symmetric
            for(int fact = 2 ; fact * fact <= num ; fact++){
                if( num % fact == 0){
                    // Is a facor of num 

                    // If there are other nums with this factor already 

                    if( factor_index.find(fact) != factor_index.end()){
                        // Need to make union set
                         if( dsu.findParent(factor_index[fact]) !=  dsu.findParent(i) ) dsu.unionSet( factor_index[fact] , i); 
                    }
                    else {
                        // First time finding this factor
                        factor_index[fact] = i ;  
                    }

                    // Now we need prime factors and not all factors , so we do the next step 
                    // Say if 2 is the factor we found , now it may be possible that may be 4 ,8 as factors too but we do not want that 

                    // So if we repeatedly divide by 2 we will get rid of it 
                    // (Try to write a number as product of prime factors and then divide you will understand )

                    while( num % fact == 0){
                        num = num / fact ; 
                    }
                }
            }

            // We may have missed a factor from the above loop ( because num is getting changed )
            if ( num > 1){
                // Num itself is a prime number ( not this need be the original num as we change num )

                if(  factor_index.find(num) != factor_index.end()){
                    
                    if( dsu.findParent(factor_index[num]) !=  dsu.findParent(i) ) dsu.unionSet( factor_index[num] , i); 

                }
                else {
                        // First time finding this factor
                        factor_index[num] = i ;  
                }
            }
            
        } 

        return dsu.count == 1 ; 



        // IDEA:
        //
        // Think of each element in nums as a node in a graph.
        //
        // There is an edge between nums[i] and nums[j]
        // if gcd(nums[i], nums[j]) > 1.
        //
        // We need to determine whether ALL nodes belong to a
        // single connected component.
        //
        // ----------------------------------------------------
        // KEY OBSERVATION
        // ----------------------------------------------------
        //
        // If gcd(a, b) > 1, then a and b share at least one
        // PRIME FACTOR.
        //
        // Example:
        //
        // 12 = 2² × 3
        // 18 = 2 × 3²
        //
        // gcd(12,18) = 6 > 1
        //
        // Notice that they share prime factors {2,3}.
        //
        // Therefore:
        //
        // Instead of explicitly checking gcd between every pair,
        // we can connect numbers that share a prime factor.
        //
        // ----------------------------------------------------
        // HOW DSU IS USED
        // ----------------------------------------------------
        //
        // factor_index[p] stores ONE index of a number that
        // already contains prime factor p.
        //
        // Example:
        //
        // nums = [6,10,15]
        //
        // 6  -> {2,3}
        // 10 -> {2,5}
        // 15 -> {3,5}
        //
        // Process 6:
        // factor_index[2] = 0
        // factor_index[3] = 0
        //
        // Process 10:
        // factor 2 already seen at index 0
        // => union(0,1)
        //
        // Process 15:
        // factor 3 already seen at index 0
        // => union(0,2)
        //
        // Now all three indices belong to the same DSU component.
        //
        // ----------------------------------------------------
        // WHY PRIME FACTORIZATION WORKS
        // ----------------------------------------------------
        //
        // Any common factor > 1 must contain at least one
        // prime factor.
        //
        // Therefore two numbers have gcd > 1 iff they share
        // at least one prime factor.
        //
        // Connecting numbers through shared prime factors is
        // equivalent to connecting numbers through gcd > 1.
        //
        // ----------------------------------------------------
        // FINAL CHECK
        // ----------------------------------------------------
        //
        // DSU maintains the number of connected components.
        //
        // Every successful union merges two components and
        // decreases component count by 1.
        //
        // If after processing all numbers:
        //
        // dsu.count == 1
        //
        // then every number is connected (directly or indirectly)
        // to every other number and traversal is possible.
        //
        // Otherwise traversal is impossible.


        // Time Complexity:
        //
        // Let:
        // n = nums.size()
        // M = max(nums)
        //
        // For each number, we compute its prime factors using
        // trial division up to sqrt(num).
        //
        // Cost per number:
        // O(sqrt(num))
        //
        // Worst case:
        // O(sqrt(M))
        //
        // Therefore:
        //
        // O(n * sqrt(M))
        //
        // DSU operations (find/union) are nearly constant:
        //
        // O(alpha(n))
        //
        // where alpha(n) is the inverse Ackermann function.
        //
        // Total:
        //
        // O(n * sqrt(M))


        // Space Complexity:
        //
        // DSU:
        // parent + rank arrays
        // O(n)
        //
        // factor_index:
        //
        // Stores distinct prime factors encountered.
        // In the worst case this is bounded by the number
        // of distinct primes up to M.
        //
        // O(n) for practical analysis.
        //
        // Total:
        //
        // O(n)
        //
        // More precisely:
        //
        // O(n + number_of_distinct_prime_factors_seen)

        // Time Complexity:  O(n * sqrt(M))
        // Space Complexity: O(n)
    }
};