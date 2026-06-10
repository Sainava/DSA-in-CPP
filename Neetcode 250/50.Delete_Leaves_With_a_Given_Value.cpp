/*
You are given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

Example 1:





Input: root = [1,2,3,5,2,2,5], target = 2

Output: [1,2,3,5,null,null,5]
Example 2:



Input: root = [3,null,3,3], target = 3

Output: []
Explanation: The output is an empty tree after removing all the nodes with value 3.

Constraints:

1 <= number of nodes in the tree <= 3000
1 <= Node.val, target <= 1000
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
    TreeNode* helper(TreeNode* root , int target){
        if( root == NULL){
            return NULL;
        }

        root->left = helper( root ->left , target );
        root->right = helper( root -> right , target);

        if( root->left == NULL && root->right == NULL && root->val == target){
            delete root ;
            return  NULL ; 
        }

        return root ;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Remove LEAF Nodes with given value , only leaf nodes 

        //TC:O(n) and SC:O(h) , SC:O(n) worst case for skewed tree and SC:O(logn) for balanced tree
        return helper(root , target);
    }
};