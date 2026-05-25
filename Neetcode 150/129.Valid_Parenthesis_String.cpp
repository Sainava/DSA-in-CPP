/*
You are given a string s which contains only three types of characters: '(', ')' and '*'.

Return true if s is valid, otherwise return false.

A string is valid if it follows all of the following rules:

Every left parenthesis '(' must have a corresponding right parenthesis ')'.
Every right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
A '*' could be treated as a right parenthesis ')' character or a left parenthesis '(' character, or as an empty string "".
Example 1:

Input: s = "((**)"

Output: true
Explanation: One of the '*' could be a ')' and the other could be an empty string.

Example 2:

Input: s = "(((*)"

Output: false
Explanation: The string is not valid because there is an extra '(' at the beginning, regardless of the extra '*'.

Constraints:

1 <= s.length <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool func(int index , int cnt  ,int n , string s , vector<vector<int>> &dp){

        if(cnt < 0) return false ;
        if(index == n ) return cnt == 0 ;

        if(dp[index][cnt]!= -1 ) return dp[index][cnt] ;

        if( s[index] == '('){
            return  dp[index][cnt] = func( index + 1 , cnt + 1 , n , s ,dp);
        }
        else if ( s[index] == ')'){
            return dp[index][cnt]= func( index + 1 , cnt - 1 , n , s ,dp);
        }
        else{
            // '*' can be ( , ) or nothing 
            int first = func( index + 1 , cnt + 1 , n , s ,dp); // (
            int second = func( index + 1 , cnt - 1 , n , s ,dp); // )
            int third = func( index + 1 , cnt , n , s,dp) ;

            return dp[index][cnt] = first || second || third ;


        }



    }
    bool checkValidString(string s) {
        int n = s.size() ; 

        // int cnt = 0 ; 
        // int index = 0 ;
        // // TC:O(3^n) at every index -> 3 choices in worst case 
        // // SC:O(n)
        // // Can apply DP on index 0 to n and cnt 0 to n so DP[n][n] to take TC:O(n^2)
        // // SC:O(n) for space optimised 
        // vector<vector<int>> dp(n , vector<int> (n + 1,-1)) ;
        // return func(index , cnt , n ,s ,dp ) ;

        // Optimised -> I keep a range of all possible values that are possible till then point , discarding -1 as they never give answer
        // Think we are doing the same as the recusrion solution but instead of keeping track of the entire func , we just keep track of the values that are possible till then 
        // So if we draw a recursion tree and compare with the cnts at every level ,we will see that they are of the 
        // range min to max -> Just think level by level recursion where all branches are opened in that level

        int mini = 0 ;
        int maxi = 0 ;

        for(int index = 0 ; index < n ; index++){
            if( s[index] == '('){
                mini++ ;
                maxi++ ;

            }
            else if ( s[index] == ')'){
                
                mini = max( mini- 1 ,0 ); // discard negatives 
                maxi-- ; 
                if( maxi < 0 ){
                    // Basically we know range is min to max 
                    // if max itself is negative , it means a closed bracket with no opening 
                    // (Remember even in the recursion case , if cnt < 0 we return negative )
                    // This basically is the case where every branch is now negative and will return false
                    return false ; 
                }
            }
            else{
                //Three possible cases for each 
                // But maxi >= mini so maxi + 1 >= mini + 1 so we only take care of maxi + 1
                // Likewise maxi - 1 >= mini - 1 so we only do mini - 1

                mini = max( mini - 1 , 0);
                maxi++;
            }

           
        }

        //TC:O(n) and SC:O(1)
        return mini == 0 ; // We have already dealt with the cases where ) does not have a opening to deal with it
    }   
};
