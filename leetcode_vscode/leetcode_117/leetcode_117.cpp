#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if (!root || (!root->left && !root->right)) {
            return root;
        }
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        if (root->next && (root->left || root->right)) {
            Node* node = root->next;
            while (node && !node->left && !node->right) {
                node = node->next;
            }
            (root->right ? root->right : root->left)->next = node == NULL ? NULL : node->left ? node->left
                                                                                              : node->right;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}

// queue<Node*> q;
// q.push(root);
// while (!q.empty()) {
//     int curLayerNodeSum = q.size();
//     for (int i = 0; i < curLayerNodeSum; i++) {
//         Node* node = q.front();
//         q.pop();
//         if (i == 0) {
//             node->next = NULL;
//         } else if (i < curLayerNodeSum - 1) {
//             q.front()->next = node;
//         }
//         if (node->right) {
//             q.push(node->right);
//         }
//         if (node->left) {
//             q.push(node->left);
//         }
//     }
// }
// return root;