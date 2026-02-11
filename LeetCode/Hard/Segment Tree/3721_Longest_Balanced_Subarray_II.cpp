/*
You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

 

Example 1:

Input: nums = [2,5,4,3]

Output: 4

Explanation:

The longest balanced subarray is [2, 5, 4, 3].
It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
Example 2:

Input: nums = [3,2,2,5,4]

Output: 5

Explanation:

The longest balanced subarray is [3, 2, 2, 5, 4].
It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
Example 3:

Input: nums = [1,2,3,2]

Output: 3

Explanation:

The longest balanced subarray is [2, 3, 2].
It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    struct Node {
        int mn, mx, lazy;
    };

    vector<Node> st;
    int n;

    Solution() {}

    void build(int p,int l,int r){
        st[p] = {0,0,0};
        if(l==r) return;
        int m=(l+r)/2;
        build(p*2,l,m);
        build(p*2+1,m+1,r);
    }

    void push(int p){
        if(st[p].lazy!=0){
            for(int c:{p*2,p*2+1}){
                st[c].mn+=st[p].lazy;
                st[c].mx+=st[p].lazy;
                st[c].lazy+=st[p].lazy;
            }
            st[p].lazy=0;
        }
    }

    void update(int p,int l,int r,int i,int j,int val){
        if(i>r||j<l) return;

        if(l>=i&&r<=j){
            st[p].mn+=val;
            st[p].mx+=val;
            st[p].lazy+=val;
            return;
        }

        push(p);
        int m=(l+r)/2;
        update(p*2,l,m,i,j,val);
        update(p*2+1,m+1,r,i,j,val);

        st[p].mn=min(st[p*2].mn,st[p*2+1].mn);
        st[p].mx=max(st[p*2].mx,st[p*2+1].mx);
    }

    int queryZero(int p,int l,int r){
        if(st[p].mn>0 || st[p].mx<0) return -1;
        if(l==r) return l;

        push(p);
        int m=(l+r)/2;

        int left=queryZero(p*2,l,m);
        if(left!=-1) return left;
        return queryZero(p*2+1,m+1,r);
    }

    int longestBalanced(vector<int>& nums) {

        n=nums.size();
        st.resize(4*n);
        build(1,0,n-1);

        unordered_map<int,int> last;
        int ans=0;

        for(int r=0;r<n;r++){

            int val=(nums[r]%2==0?1:-1);

            if(!last.count(nums[r])){
                update(1,0,n-1,0,r,val);
            }else{
                int p=last[nums[r]];
                update(1,0,n-1,0,p,-val);
                update(1,0,n-1,0,r,val);
            }

            last[nums[r]]=r;

            int l=queryZero(1,0,n-1);
            if(l!=-1){
                ans=max(ans,r-l+1);
            }
        }

        return ans;
    }
};
