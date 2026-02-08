/*
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/




#include<iostream>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        // If the helper function returns -1, it means the tree is not balanced.
        return checkHeight(root) != -1;
    }

private:
    // Helper function that returns the height of the tree if balanced,
    // or -1 if the tree is unbalanced.
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Height of an empty tree is 0
        }

        // Recursively check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Propagate unbalance

        // Recursively check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Propagate unbalance

        // Check current node balance
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Not balanced
        }

        // Return actual height of this node
        return max(leftHeight, rightHeight) + 1;
    }
};