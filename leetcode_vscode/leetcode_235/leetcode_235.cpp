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
    // 任意的二叉树都行，适用面更广，同236题！！ 没考虑二叉搜索树的特殊性！
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        bool flag = false;
        dfs(root, p, pathP, flag);
        flag = false;
        dfs(root, q, pathQ, flag);
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            ++i;
        }
        return pathQ[i - 1];
    }
    void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path, bool& flag) {
        if (!root) {
            return;
        }
        path.push_back(root);
        if (root == node) {
            flag = true;
            return;
        }
        dfs(root->left, node, path, flag);
        if (flag) {
            return;
        }
        dfs(root->right, node, path, flag);
        if (!flag) {
            path.pop_back();
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
    TreeNode* node = root->left;
    Solution sol;
    bool flag = false;
    vector<TreeNode*> path;
    sol.dfs(root, node, path, flag);
    for (TreeNode* node : path) {
        cout << node->val << ' ';
    }
    system("pause");
    return 0;
}