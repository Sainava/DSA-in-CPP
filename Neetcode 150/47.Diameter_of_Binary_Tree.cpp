/*
The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.

The length of a path between two nodes in a binary tree is the number of edges between the nodes. Note that the path can not include the same node twice.

Given the root of a binary tree root, return the diameter of the tree.

Example 1:



Input: root = [1,null,2,3,4,5]

Output: 3
Explanation: 3 is the length of the path [1,2,3,5] or [5,3,2,4].

Example 2:

Input: root = [1,2,3]

Output: 2
Constraints:

1 <= number of nodes in the tree <= 100
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
    pair<int,int> diameterHelper(TreeNode* root){
        if(root == NULL) return {0,0};

        pair<int,int> left = diameterHelper(root->left);
        pair<int,int> right = diameterHelper(root->right);
        
        int leftHeight = left.second ;
        int rightHeight = right.second ;

        int leftDiameter = left.first ;
        int rightDiameter = right.first ;

        int DiameterIncludingNode = leftHeight + rightHeight + 1 ;

        int maxDiameter = max(max(leftDiameter,rightDiameter) ,DiameterIncludingNode);
        int height = max(leftHeight,rightHeight)+1 ;
        return {maxDiameter , height};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // TC :O(n) and SC:O(h) = SC:O(n) worst case (skew tree)
        return diameterHelper(root).first - 1; // -1 since we are counting nodes but we need edges
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root , int &maxi){
        if( root == NULL){
            return 0 ; 
        }  

        int left = helper(root->left , maxi );
        int right = helper(root->right , maxi ) ; 

        maxi = max( maxi ,1 + left + right ) ;

        return 1 + max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0 ; 
        helper ( root , maxi ) ;
        //TC:O(n) and SC:O(n)
        return maxi - 1 ;  // -1 as we count nodes but they want edges
    }
};
