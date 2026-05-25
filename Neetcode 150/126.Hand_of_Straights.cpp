/*
You are given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize.

You want to rearrange the cards into groups so that each group is of size groupSize, and card values are consecutively increasing by 1.

Return true if it's possible to rearrange the cards in this way, otherwise, return false.

Example 1:

Input: hand = [1,2,4,2,3,5,3,4], groupSize = 4

Output: true
Explanation: The cards can be rearranged as [1,2,3,4] and [2,3,4,5].

Example 2:

Input: hand = [1,2,3,3,4,5,6,7], groupSize = 4

Output: false
Explanation: The closest we can get is [1,2,3,4] and [3,5,6,7], but the cards in the second group are not consecutive.

Constraints:

1 <= hand.length <= 1000
0 <= hand[i] <= 1000
1 <= groupSize <= hand.length
*/
#include <iostream>
#include <vector>
#include <map>  
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Watch neetcode video
        int n = hand.size() ; 

        if( n % groupSize != 0 ) return false ; // Not possible to partition

        map<int,int> freq ; // Stores the frequency sorted by the keys 

        for(int hn : hand){
            freq[hn]++ ;
        }

        // Now we know an answer may be possible 
        while(!freq.empty()){
            auto start = *(freq.begin()) ;
            int num = start.first ;
            freq[num]--;

            if(freq[num]==0){
                freq.erase(num);
            }

            for(int i = 1 ; i < groupSize ; i++){
                int next = num + i ;

                if(freq.find(next)!= freq.end()){
                    // can continue 
                    freq[next]--;
                    if(freq[next]==0){
                        freq.erase(next);
                    }
                }else{
                    return false ; 
                }
            }
        }

        //TC:O(nlogn) and SC:O(n)
        return true ;
    }
};
