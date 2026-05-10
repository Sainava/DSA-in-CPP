/*
Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. A node can not appear in the sequence more than once. The path does not necessarily need to include the root.

The path sum of a path is the sum of the node's values in the path.

Example 1:



Input: root = [1,2,3]

Output: 6
Explanation: The path is 2 -> 1 -> 3 with a sum of 2 + 1 + 3 = 6.

Example 2:



Input: root = [-15,10,20,null,null,15,5,-5]

Output: 40
Explanation: The path is 15 -> 20 -> 5 with a sum of 15 + 20 + 5 = 40.

Constraints:

1 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000
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
    int helper(TreeNode* root , int &maxi){
        if(root == NULL){
            return 0 ;
        }
        // max since we will ignore if it gives negative value 
        int left = max(0 , helper(root->left , maxi));
        int right = max(0 , helper(root->right , maxi));

        maxi = max( maxi , root->val + left + right);

        return root->val + max(left , right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);

        // TC:O(n) and SC:O(n)
        return maxi ; 
    }
};
