/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

In this new place, there are houses and each house has its only one parent house. All houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken.

You are given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

Example 1:



Input: root = [1,4,null,2,3,3]

Output: 7
Explanation: Maximum amount of money the thief can rob = 4 + 3 = 7

Example 2:



Input: root = [1,null,2,3,5,4,2]

Output: 12
Explanation: Maximum amount of money the thief can rob = 1 + 4 + 2 + 5 = 12

Constraints:

1 <= The number of nodes in the tree <= 10,000.
0 <= Node.val <= 10,000

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
    pair<int,int> helper( TreeNode* root){
        if( root == NULL){
            return {0,0} ; 
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Now if I choose to rob this house , I cannot rob the children node
        int willRob = root-> val + left.second + right.second ;

        // But if I do not rob the house I can can choose if I want to rob the child houses
        // Check example 2 
        int willNotRob = 0 + max(left.first , left.second) + max(right.first , right.second) ;

        return {willRob , willNotRob};

        
    }

    int rob(TreeNode* root) {
        // pair { steal  , notSteal }

        auto ans = helper(root);

        //TC:O(n) and SC:O(n)
        return max( ans.first , ans.second);
    }
};