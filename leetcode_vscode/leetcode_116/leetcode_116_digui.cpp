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
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    root = sol.connect(root);
    Node* node = root->left->left;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    system("pause");
    return 0;
}