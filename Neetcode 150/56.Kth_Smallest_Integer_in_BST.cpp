/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.

A binary search tree satisfies the following constraints:

The left subtree of every node contains only nodes with keys less than the node's key.
The right subtree of every node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.
Example 1:



Input: root = [2,1,3], k = 1

Output: 1
Example 2:



Input: root = [4,3,5,2,null], k = 4

Output: 5
Constraints:

1 <= k <= The number of nodes in the tree <= 1000.
0 <= Node.val <= 1000
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
    void helper(TreeNode* root, int k,int &cnt,int &ans){
        if(root == NULL){
            return ;
        }

        // If found no need to check further 
        if(ans!= -1 ){
            return;
        }

        // Inorder 
        
        // 1. Process left 
        helper(root->left , k , cnt , ans);

        // Process current 
        cnt++;
        if(cnt == k){
            ans = root->val;
        }

        // Process right 
        helper(root->right,k ,cnt ,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        // Return the k value in the inorder traversal 
        int cnt = 0 ; 
        int ans = -1;
        helper(root,k,cnt,ans);

        //TC:O(n) and SC:O(n)
        return ans ;
    }
};
