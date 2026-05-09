/*
Given the root of a binary tree, return true if it is a valid binary search tree, otherwise return false.

A valid binary search tree satisfies the following constraints:

The left subtree of every node contains only nodes with keys less than the node's key.
The right subtree of every node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.
Example 1:



Input: root = [2,1,3]

Output: true
Example 2:



Input: root = [1,2,3]

Output: false
Explanation: The root node's value is 1 but its left child's value is 2 which is greater than 1.

Constraints:

1 <= The number of nodes in the tree <= 1000.
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
    void helper(TreeNode* root , int &prevNode , bool &isBST){
        if(root==NULL){
            return ;
        }
        // Inorder

        //Process Left
        helper(root->left,prevNode,isBST);

        //Process Current
        if(prevNode >= root->val){
            isBST = false;
        }
        prevNode = root->val ;
        
        //Process right
        helper(root->right,prevNode,isBST);

        return ;
        
    }
    bool isValidBST(TreeNode* root) {
        //A binary tree is a BST iff its inorder traversal is strictly increasing.
        int prevNode = INT_MIN;
        
        bool isBST = true ;

        helper(root,prevNode,isBST);

        //TC:O(n) and SC:O(n)
        return isBST;
    }
};
