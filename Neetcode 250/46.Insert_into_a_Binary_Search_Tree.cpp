/*
You are given the root node of a binary search tree (BST) and a value val to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note: There may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:



Input: root = [5,3,9,1,4], val = 6

Output: [5,3,9,1,4,6]
Example 2:

Input: root = [5,3,6,null,4,null,10,null,null,7], val = 9

Output: [5,3,6,null,4,null,10,null,null,7,null,null,9]
Constraints:

0 <= The number of nodes in the tree <= 10,000.
-100,000,000 <= val, Node.val <= 100,000,000
All the values Node.val are unique.
It's guaranteed that val does not exist in the original BST.

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


// Solution 1 - recursive approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // FInd where it should have been in the BST , if it is null there insert
        if( root == NULL){
            return new TreeNode(val) ;
        }
        else if ( val > root->val){
            root->right = insertIntoBST(root->right , val);
        }
        else {
            root->left = insertIntoBST(root->left , val);
        }
       
        //TC:O(h) and SC:O(h) where h is height of the tree 
        return root ; 
    }
};

//Solution 2 - iterative approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL){
            return new TreeNode(val);
        }

        TreeNode* curr = root; 

        while( true ){
            
            if( val > curr-> val){
                if( curr->right == NULL){
                    curr->right = new TreeNode(val);
                    break ; 
                }
                curr = curr->right ;
            }
            else{
                if( curr->left == NULL){
                    curr->left = new TreeNode(val);
                    break ; 
                }
                curr = curr->left;
            }
        }

        //TC:O(h) and SC:O(1)
        return root ;
    }
};