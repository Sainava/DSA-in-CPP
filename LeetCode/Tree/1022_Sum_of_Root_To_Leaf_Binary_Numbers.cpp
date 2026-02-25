/*
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
*/


 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<iostream>
using namespace std;

class Solution {
public:
    int dfs(TreeNode* root , int curr){
        if(root == NULL){
            return 0;
        }

        // Update current binary number
        curr = (curr << 1 ) | root-> val; // curr stores the decimal value even after the operations are binary as it is int type 
        // curr = curr * 2 | root -> val;
        // since curr << 1 is same as curr * 2
        // so when we shift we add 0 at the end and any number OR 0 is the number is itself 
        // SO 100 --> 100 << 1 = 1000 --> 1000 OR 1 -->> 1001

        if(root -> left == NULL && root->right==NULL){
            return curr;
        }

        return dfs(root->left,curr) + dfs(root->right , curr);  
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root , 0 );

        //TC:O(n) and SC:O(n)
    }
};