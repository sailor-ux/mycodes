#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
        return root;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty(

            )) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return root;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
    }
};
int main() {

    system("pause");
    return 0;
}