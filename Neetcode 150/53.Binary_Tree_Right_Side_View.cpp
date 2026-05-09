/*
You are given the root of a binary tree. Return only the values of the nodes that are visible from the right side of the tree, ordered from top to bottom.

Example 1:



Input: root = [1,2,3,null,4,null,5]

Output: [1,3,5]
Example 2:



Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]
Example 3:

Input: root = [1,null,2]

Output: [1,2]
Example 4:

Input: root = []

Output: []

Constraints:

0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void helper(TreeNode* root , int level ,vector<int> &ans){
        if(root==NULL){
            return ;
        }

        if( level == ans.size()){
            ans.push_back(root->val);
        }

        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);

        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>  ans ;
        int level = 0 ;
        helper(root,level, ans);
        //TC:O(n) and SC:O(n)
        return ans ;
    }
};
