/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
You are given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

Example 1:

Input: senate = "RRDDD"

Output: "Radiant"
Explanation:

The first 'R' takes the rights of the first 'D'.
THe second 'R' takes the rights of the second 'D'.
The next two 'D's have lost their rights.
The last 'D' takes the rights of the first 'R'.
The last remaining 'R' takes the rights of the last 'D'.
As only 'R' is left, he announces the victory.
Example 2:

Input: senate = "RDD"

Output: "Dire"
Constraints:

1 <= senate.length <= 10,000
senate[i] is either 'R' or 'D'.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        // So the idea is R can remove D and D can remove R 
        // Say RRDRD
        // Now the greedy idea here is R will try to remove the D closes to it . 
        // Why ? Because that woild mean that the first D that gets the chance of deletion comes later 
        // So when R deletes the first D it postpones the first time D gets to remove R and gives more R the chance for deletions 
        // This would increase the number of R's and thus increase their chance of winning 

        // Now there are two things -> Index matters as they try to remove the one closest to them 
        // But this also happens until one of R or D is completely depleted . So there could be multiple rounds

        // We need to keep track of R and D 's so we can use queue to do this .
        // using queue helps with the multiple rounds as if we add an offset ( here n ) and push to the back of queue that simulates later rounds
        // And also helps because R and D can remove anyone before them but the chances are given from left to right 

        int n = senate.size() ; 

        queue<int> r ; 
        queue<int> d ;

        for(int i = 0 ; i < n ; i++){
            if( senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        // The moment one becomes empty the other has one 
        while(!r.empty() && !d.empty()){
            int R = r.front() ; 
            r.pop() ; 

            int D = d.front() ; 
            d.pop() ; 

            if( R < D){
                // R eliminates D
                // SO R remains and enters the queue but D is gone 
                r.push( R + n) ; // The offset as a D later can remove it but the way we design it is left deletes right so offset helps me that 
            }
            else{
                // D eliminates R 
                d.push( D + n) ;
            }
        }

        //TC:O(n) as even though the same element can enter the queue multiple times . THe driving factor is the idea that at each step one is deleted forever 
        // Now that would mean if n total elements . We will run this <= n as each time one is deleted forever
        // SC:O(n)
        if ( r.empty()) return "Dire" ;
        else return "Radiant" ; 
    }
};