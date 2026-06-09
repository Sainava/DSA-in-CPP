/*
You are given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:



Input: root = [1,2,3,4,5,6,7]

Output: [4,2,5,1,6,3,7]
Example 2:



Input: root = [1,2,3,null,4,5,null]

Output: [2,4,1,5,3]
Example 3:

Input: root = []

Output: []
Constraints:

0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 100
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    TreeNode* findPred(TreeNode* curr){
        // Find the righmost node in the left subtree
        TreeNode* pred  = curr->left ; 

        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }

        return pred ; 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Will try morrisTraversal 
        vector<int> ans ; 

        TreeNode* curr = root ; 

        while(curr != NULL){

            if( curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right ;  

            }
            else{
                // left exists 

                // Find predecessor
                TreeNode * pred = findPred(curr);

                if(pred->right == NULL){
                    pred->right = curr ; 
                    curr = curr -> left ; 
                }
                else{
                    pred->right = NULL ;
                    ans.push_back(curr->val);
                    curr = curr -> right ; 
                }
            }
        }

        //TC:O(n) and SC:O(1) excluding ans array 
        return ans ; 
    }
};