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
    vector<TreeNode*> path;
    bool flag;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag = false;
        dfs(root, p);
        vector<TreeNode*> pathRootP = path;
        path.clear();
        flag = false;
        dfs(root, q);
        int i = 0;
        for (; i < pathRootP.size() && i < path.size() && pathRootP[i] == path[i]; i++) {
        }
        return path[i - 1];
    }
    // ����д�Ĳ��Ǻܺã���235�����Ľ��棡
    void dfs(TreeNode* root, TreeNode* node) { // �ص㣺root-->node������·��������dfs�������������������Ŷ�����(��node���)
        if (!root) {
            return;
        }
        if (root == node) {
            path.push_back(root);
            flag = true;
            return;
        }
        path.push_back(root);
        dfs(root->left, node);
        if (flag) {
            return;
        }
        dfs(root->right, node);
        if (flag) {
            return;
        }
        path.pop_back();
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* node = root->left->right->right;
    Solution sol;
    sol.flag = false;
    sol.dfs(root, node);
    for (TreeNode* node : sol.path) {
        cout << node->val << ' ';
    }

    // TreeNode* p = root->left->left;
    // TreeNode* q = root->left->right->right;
    // Solution sol;
    // cout << sol.lowestCommonAncestor(root, p, q)->val;
    system("pause");
    return 0;
}