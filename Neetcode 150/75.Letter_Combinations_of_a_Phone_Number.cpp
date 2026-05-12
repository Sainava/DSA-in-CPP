/*
You are given a string digits made up of digits from 2 through 9 inclusive.

Each digit (not including 1) is mapped to a set of characters as shown below:

A digit could represent any one of the characters it maps to.

Return all possible letter combinations that digits could represent. You may return the answer in any order.



Example 1:

Input: digits = "34"

Output: ["dg","dh","di","eg","eh","ei","fg","fh","fi"]
Example 2:

Input: digits = ""

Output: []
Constraints:

0 <= digits.length <= 4
2 <= digits[i] <= 9
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void solve(string digits ,vector<string> &ans , string &temp ,vector<string> &mapping, int index){
        if(index >=digits.length()){
            ans.push_back(temp);
            return ;
        }

        int num = digits[index]-'0' ;
        string current = mapping[num];

        for(int i = 0 ; i < current.size() ; i++){
            temp.push_back(current[i]);
            solve(digits , ans , temp , mapping ,index+1);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};

        unordered_map<int,string> mp ;
        
        vector<string> mapping = {"","","abc" , "def" , "ghi" , "jkl" , "mno" ,"pqrs" , "tuv" , "wxyz"};

        vector<string>  ans ;
        string temp ;
        int index = 0 ; // The index is for digits 
        // We are basically going to implement cartesian product

        // TC:O(3^n*n) as there are n num in digits and and each num is mapped to 3 on average 
        // so it is at every point we have 3 options and copying takes n as each num contributes one 
        // But it some also have 4 so we can say worst
        //TC:O(4^n * n )
        // SC:O(n) for recursion stack and SC:O(n*x) where n is size of each answer and x is the no of answers 

        solve(digits , ans , temp , mapping ,index );

        return ans ;
        
    }
};
