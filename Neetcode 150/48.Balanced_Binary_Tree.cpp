/*
Given a binary tree, return true if it is height-balanced and false otherwise.

A height-balanced binary tree is defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:



Input: root = [1,2,3,null,null,4]

Output: true
Example 2:



Input: root = [1,2,3,null,null,4,null,5]

Output: false
Example 3:

Input: root = []

Output: true
Constraints:

The number of nodes in the tree is in the range [0, 1000].
-1000 <= Node.val <= 1000
*/
#include <iostream>
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
    pair<bool , int >  balancedHelper(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        pair<bool,int> leftTree = balancedHelper(root->left);
        pair<bool,int> rightTree = balancedHelper(root->right);

        int height = max(leftTree.second, rightTree.second) + 1;

        // We && because even if one node does not satisfy this , we need answer to propagate upwards
        bool isBalanced = (abs(leftTree.second - rightTree.second) <=1)&& leftTree.first && rightTree.first;

        return {isBalanced,height};
    }
    bool isBalanced(TreeNode* root) {
        //TC:O(n) and SC:O(h) = SC:O(n) skew tree worst case 
        return balancedHelper(root).first;
    }
};
