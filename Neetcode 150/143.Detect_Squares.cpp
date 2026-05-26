/* 
You are given a stream of points consisting of x-y coordinates on a 2-D plane. Points can be added and queried as follows:

Add - new points can be added to the stream into a data structure. Duplicate points are allowed and should be treated as separate points.
Query - Given a single query point, count the number of ways to choose three additional points from the data structure such that the three points and the query point form a square. The square must have all sides parallel to the x-axis and y-axis, i.e. no diagonal squares are allowed. Recall that a square must have four equal sides.
Implement the CountSquares class:

CountSquares() Initializes the object.
void add(int[] point) Adds a new point point = [x, y].
int count(int[] point) Counts the number of ways to form valid squares with point point = [x, y] as described above.
Example 1:



Input: 
["CountSquares", "add", [[1, 1]], "add", [[2, 2]], "add", [[1, 2]], "count", [[2, 1]], "count", [[3, 3]], "add", [[2, 2]], "count", [[2, 1]]]
       
Output:
[null, null, null, null, 1, 0, null, 2]

Explanation:
CountSquares countSquares = new CountSquares();
countSquares.add([1, 1]);
countSquares.add([2, 2]);
countSquares.add([1, 2]);

countSquares.count([2, 1]);   // return 1.
countSquares.count([3, 3]);   // return 0.
countSquares.add([2, 2]);     // Duplicate points are allowed.
countSquares.count([2, 1]);   // return 2. 
Constraints:

point.length == 2
0 <= x, y <= 1000
*/

/*
Can use custom has here 
struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {

        return hash<int>()(p.first) ^ 
               (hash<int>()(p.second) << 1);
    }
};
Then use : unordered_map<pair<int,int>, int, hash_pair> freq;
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class CountSquares {
public:

    map<pair<int,int> , int> freq ; // not unordered_map as that cannot have pair as key 
    vector<vector<int>> pnts;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        //TC:O(1)
        pnts.push_back(point) ;

        //TC:O(logn) -> total number of distinct points in map 
        freq[{point[0] , point[1]}]++ ; 

        // SC:O(1)
    }
    
    int count(vector<int> point) {  
        
        int px = point[0] ; 
        int py = point[1] ;
        int ans = 0 ; 
        // We traverse along the vector but we only care for diagonal points 
        // TC:O(k) for traversal  if total added points is k 
        // And each map lookup if logn ( n being unique points )
        // SO TC:O(klogn)
        for(int i = 0 ; i < pnts.size() ; i++){
            int x = pnts[i][0] ; 
            int y = pnts[i][1] ;

            // Check if this is a diagonal point 

            if( abs( px - x ) == abs( py - y) && x!=px and y!= py){
                // We cannot use overlapping points and call it a square
                // Now check if this diagonal and query point can form sqaure 

                int cnt1 = freq[{x , py}] ; // If no points exist , we will get 0 
                int cnt2 = freq[{px , y}] ;

                // possible squares if both these points exist 
                ans += cnt1 * cnt2 ;
            }
        }
        //TC:O(klogn) and SC:O(1)
        return ans ; 
    }
};
