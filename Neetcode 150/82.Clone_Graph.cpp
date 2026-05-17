/*
Given a node in a connected undirected graph, return a deep copy of the graph.

Each node in the graph contains an integer value and a list of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
The graph is shown in the test cases as an adjacency list. An adjacency list is a mapping of nodes to lists, used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

For simplicity, nodes values are numbered from 1 to n, where n is the total number of nodes in the graph. The index of each node within the adjacency list is the same as the node's value (1-indexed).

The input node will always be the first node in the graph and have 1 as the value.

Example 1:



Input: adjList = [[2],[1,3],[2]]

Output: [[2],[1,3],[2]]
Explanation: There are 3 nodes in the graph.
Node 1: val = 1 and neighbors = [2].
Node 2: val = 2 and neighbors = [1, 3].
Node 3: val = 3 and neighbors = [2].

Example 2:



Input: adjList = [[]]

Output: [[]]
Explanation: The graph has one node with no neighbors.

Example 3:

Input: adjList = []

Output: []
Explanation: The graph is empty.

Constraints:

0 <= The number of nodes in the graph <= 100.
1 <= Node.val <= 100
There are no duplicate edges and no self-loops in the graph.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        // We will try bfs 

        if(node == NULL) return NULL;

        Node * root = new Node(node->val) ; 
        queue<Node*> q ;
        q.push(node);

        // Og -> its clone 
        unordered_map<Node*,Node*> visited ; // This prevents from duplicate addition as in a graph , a node can be reached from multiple paths
        visited[node] = root;
        while(!q.empty()){
             Node* og = q.front();
            q.pop();

            Node* copy = visited[og];
            for(auto ogNeighbor:og->neighbors){
                Node* newNode = NULL;

                // check if already made , if yes no need to make . Just make connections or edges
                if(visited.find(ogNeighbor)==visited.end()){
                    newNode = new Node(ogNeighbor -> val);
                    q.push(ogNeighbor);
                    visited[ogNeighbor] = newNode;
                }else{
                    newNode = visited[ogNeighbor];
                }
                copy->neighbors.push_back(newNode);
            }
        }

        //TC:O(V+E) and SC:O(V) for visited and queue
        return root ; 
  
    }
};
