/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
using namespace std;



 // Definition for a binary tree node.
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
    // Vector to store nodes in sorted order
    vector<TreeNode*> sortedNodes;

    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Perform inorder traversal to get nodes in sorted order
        inorderTraversal(root);
        
        // Step 2: Rebuild the tree from the sorted list
        return buildBalancedTree(0, sortedNodes.size() - 1);
    }

private:
    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        sortedNodes.push_back(node);
        inorderTraversal(node->right);
    }

    TreeNode* buildBalancedTree(int start, int end) {
        if (start > end) return nullptr;

        // Pick the middle element to be the root of this subtree
        int mid = start + (end - start) / 2;
        TreeNode* root = sortedNodes[mid];

        // Recursively build left and right subtrees
        root->left = buildBalancedTree(start, mid - 1);
        root->right = buildBalancedTree(mid + 1, end);

        return root;
    }
};