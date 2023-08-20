// 这两种方法都需要借助哈希表记录被克隆过的节点来避免陷入死循环。
#include <iostream>
#include <queue>
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
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            for (Node* neighbor : curNode->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curNode]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};

int main() {

    system("pause");
    return 0;
}