/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    static bool cmp(string a , string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {

        vector<string> arr ;

        //TC:O(n)
        for(int num : nums){
            arr.push_back(to_string(num));
        }

        //TC:O(nlogn)

        // comparison also takes O(k) as k digits average so TC:O(nlogn*k) but since k is small we ignore 
        sort( arr.begin() , arr.end() , cmp );

        // edge case if all zeroes 
        if(arr[0] == "0") return "0";

        string ans = "";

        for(string s : arr){
            ans += s;
        }

        //TC :(nlogn)

        // SC:O(logn) for sorting 
        // SC:O(n*k) to store digits of average size k but since k is small we ignore so 
        // SC:O(n) final
        return ans ;

    }
};