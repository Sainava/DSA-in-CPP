/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the
condition that all the values in the left subtree of a node should be less than
all the values in the right subtree of the node. This condition is applied on
all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7

Output : 1 2 3 4 5 6 7
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

Your task :
You don't need to read input or print anything. Your task is to complete the
function convertToMaxHeapUtil() which takes the root of the tree as input and
converts the BST to max heap. Note : The driver code prints the postorder
traversal of the converted BST.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)

Constraints :
1 ≤ n ≤ 105
*/

struct Node {
  int data;
  Node *left, *right;
};

// THIS DOES NOT WORK
// class Solution {
//   public:
//     void helper( Node * root ){
//         if(root == NULL) return ;

//         helper(root->left) ;
//         helper(root->right) ;

//         if( root->right!= NULL){
//             swap(root->data , root->right->data) ;
//         }else if(root->left != NULL){
//             swap(root->data , root->left->data) ;
//         }

//         return ;
//     }

//     void convertToMaxHeapUtil(Node* root) {
//         // Your code goes here
//         helper(root) ;
//     }
// };
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // Store BST values in sorted order.
  void inorder(Node *root, vector<int> &values) {
    if (root == NULL)
      return;

    inorder(root->left, values);

    values.push_back(root->data);

    inorder(root->right, values);
  }

  // Assign values using postorder traversal.
  void postorder(Node *root, vector<int> &values, int &index) {
    if (root == NULL)
      return;

    postorder(root->left, values, index);
    postorder(root->right, values, index);

    root->data = values[index++];
  }

  void convertToMaxHeapUtil(Node *root) {

    vector<int> values;

    // Inorder traversal of BST gives sorted values.
    inorder(root, values);

    int index = 0;

    // Postorder assignment puts larger values
    // at parents than their children.
    postorder(root, values, index);
  }
};
