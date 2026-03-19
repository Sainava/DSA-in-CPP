/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  ≤  a.size(), b.size()  ≤  105
-109 ≤ a[i], b[i] ≤109


*/

#include <iostream>
#include <vector>
#include<set>
using namespace std;


// Brute Force : TC:O(n log n) + O(m log m) + O(n + m) and SC:O(n + m)
#include<set>
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int> st; // Ordered Set by default
        
        // TC:O(nlogN) where N is size of set
        for(int i:a){
            st.insert(i);
        }
        // TC:O(mlogN) where N is size of set
        for(int j:b){
            st.insert(j);
        }   
        
        vector<int> ans;
        //TC:O(n + m) worst case
        for(int element : st){
            ans.push_back(element);
        }
        
        //TC:O(nlogN + mlogN + (n+m ) and SC:O(n+m)
        return ans;
    }
};

//Best and Optimal : TC:O(n + m) and SC:O(n + m) for result vector SC:O(1) extra space
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        
        // Optimal Two pointer approach 
        
        int i = 0 ;
        int j = 0 ;
        
        vector<int> ans ;
        
        while(i < a.size() && j< b.size()){
            if( a[i]<= b[j]){
                
                // We need to handle duplicates so if it is already there do no take 
                // But arr.back() gives undefined behaviour on empty array so if this is first element to be added just add it 
                if(ans.size()==0 || ans.back()!= a[i]){
                    ans.push_back(a[i]);
                }
                i++;
            }else{
                if(ans.size()==0 || ans.back()!= b[j]){
                    ans.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i < a.size() ){
            if(ans.size()==0 || ans.back()!= a[i]){
                    ans.push_back(a[i]);
                }
            i++;
        }
        
        while(j< b.size()){
            if(ans.size()==0 || ans.back()!= b[j]){
                    ans.push_back(b[j]);
                }
            j++;
        }
        
        //TC:O(n + m) and SC:O(1)  extra space
        return ans;
    }
};