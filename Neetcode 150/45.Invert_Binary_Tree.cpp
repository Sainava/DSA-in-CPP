/*
You are given the root of a binary tree root. Invert the binary tree and return its root.

Example 1:



Input: root = [1,2,3,4,5,6,7]

Output: [1,3,2,7,6,5,4]
Example 2:



Input: root = [3,2,1]

Output: [3,1,2]
Example 3:

Input: root = []

Output: []
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
    void  postorderSwap(TreeNode* root){
        if(root==NULL){
            return;
        }

        postorderSwap(root->left);
        postorderSwap(root->right);

        // Now below this node , every node has their children swapped 
        // so we swap this now 

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp ;

        // or swap(root->left , root->right)
        return ;


    }
    TreeNode* invertTree(TreeNode* root) {

        postorderSwap(root);

        //TC:O(n) 
        // SC:O(n) in worst case , skew tree , it is like a linked list 
        // or SC:(h) h is height of tree
        return root;
    }
};
