/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:



Input: root = [1,2,3,4,5], subRoot = [2,4,5]

Output: true
Example 2:



Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]

Output: false
Constraints:

1 <= The number of nodes in both trees <= 100.
-100 <= root.val, subRoot.val <= 100
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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p== NULL && q==NULL) return true ;
        if( p==NULL && q!=NULL) return false;
        if( p!=NULL && q==NULL) return false;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        if( (p->val == q->val) && left && right ){
            return true ;
        }else{
            return false;
        } 

        //TC:O(n) and SC:(n) worst case skew tree 
        // n is no of nodes in each 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Find a node where the subtree might start

        if( root== NULL){
            return false;
        }

        bool isSame= false;
        if(root->val==subRoot->val){
            isSame = isSameTree(root,subRoot);
        }

        if(!isSame){
            bool left = isSubtree(root->left,subRoot);
            bool right = isSubtree(root->right,subRoot) ;

            if(left || right){
                return true;
            }else{
                return false;
            }
        }else{
            //TC:O(n*m) and SC:O(n+m)
            return true ;
        }      
    }
};
