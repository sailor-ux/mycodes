#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
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
    unordered_map<Node*, Node*> hashVisited;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        if (hashVisited.count(node)) {
            return hashVisited[node];
        }
        Node* cloneNode = new Node(node->val);
        hashVisited[node] = cloneNode;
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
int main() {

    system("pause");
    return 0;
}