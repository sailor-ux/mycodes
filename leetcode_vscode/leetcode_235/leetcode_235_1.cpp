#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // 考虑二叉排序树的特殊性！ 反而更简单，不需要回溯！
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        dfs(root, p, pathP);
        dfs(root, q, pathQ);
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            ++i;
        }
        return pathQ[i - 1];
    }
    void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (!root) {
            return;
        }
        path.push_back(root);
        if (root == node) {
            return;
        } else if (node->val < root->val) {
            dfs(root->left, node, path);
        } else {
            dfs(root->right, node, path);
        }
    }
};
int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    TreeNode* node = root->right->left;
    Solution sol;
    vector<TreeNode*> path;
    sol.dfs(root, node, path);
    for (TreeNode* node : path) {
        cout << node->val << ' ';
    }
    system("pause");
    return 0;
}