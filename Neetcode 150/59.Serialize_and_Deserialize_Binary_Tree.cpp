/*
Implement an algorithm to serialize and deserialize a binary tree.

Serialization is the process of converting an in-memory structure into a sequence of bits so that it can be stored or sent across a network to be reconstructed later in another computer environment.

You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure. There is no additional restriction on how your serialization/deserialization algorithm should work.

Note: The input/output format in the examples is the same as how NeetCode serializes a binary tree. You do not necessarily need to follow this format.

Example 1:



Input: root = [1,2,3,null,null,4,5]

Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []

Output: []
Constraints:

0 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Lets do level order traveral 

        if(root == NULL) return "";

        queue<TreeNode*> q ;
        q.push(root);
        string ans = "";

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL){
                ans+="#,";
            }else{
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            
        }

        //TC:O(n) and SC:O(n)
        return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream s(data); // cin for strings 
        string str ; 
        getline( s, str , ',') ;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // For left 
            getline(s,str,',');

            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode; 
                q.push(leftNode);
            }

            // For right 
            getline(s,str,',');

            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode; 
                q.push(rightNode);
            }

        }
        //TC:O(n) and SC:O(n)
        return root;
    }
};
