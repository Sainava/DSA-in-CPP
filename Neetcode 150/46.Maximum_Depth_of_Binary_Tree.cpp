/*
Given the root of a binary tree, return its depth.

The depth of a binary tree is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:



Input: root = [1,2,3,null,null,4]

Output: 3
Example 2:

Input: root = []

Output: 0
Constraints:

0 <= The number of nodes in the tree <= 100.
-100 <= Node.val <= 100

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
    int findDepth(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }

        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);

        return max(leftDepth, rightDepth) + 1;

    }
    int maxDepth(TreeNode* root) {
        //TC:O(n) and SC:O(h) = SC:O(n) worst case , skew tree
        return findDepth(root) ; 

    }
};
