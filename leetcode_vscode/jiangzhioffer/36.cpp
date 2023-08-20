#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 基于中序遍历的迭代法来做！
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return NULL;
        }
        Node *pre = NULL, *head = NULL;
        stack<Node*> stk;
        Node* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (pre) {
                pre->right = cur;
                cur->left = pre;
            } else {
                head = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        pre->right = head;
        head->left = pre;
        return head;
    }
    // 基于中序遍历的递归法来做！
    Node *pre = NULL, *head = NULL;
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return NULL;
        }
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void dfs(Node* root) { // root<=>cur
        if (!root) {
            return;
        }
        dfs(root->left);
        if (pre) {
            pre->right = root;
            root->left = pre;
        } else {
            head = root;
        }
        pre = root;
        dfs(root->right);
    }
};
int main() {

    system("pause");
    return 0;
}