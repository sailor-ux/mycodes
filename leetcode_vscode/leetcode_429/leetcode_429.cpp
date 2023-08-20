#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back({});
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                res.back().push_back(node->val);
                for (Node* ptr : node->children) {
                    q.push(ptr);
                }
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}