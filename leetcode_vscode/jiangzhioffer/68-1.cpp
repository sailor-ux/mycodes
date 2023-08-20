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
    // 二叉排序树，反而更简单！
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        dfs(root, pathP, p);
        dfs(root, pathQ, q);
        int lenP = pathP.size(), lenQ = pathQ.size();
        int idx = 0;
        while (idx < lenP && idx < lenQ && pathP[idx] == pathQ[idx]) {
            idx++;
        }
        return pathP[idx - 1];
    }
    void dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* node) {
        if (!root) {
            return;
        }
        path.push_back(root);
        if (root == node) {
            return;
        } else if (root->val > node->val) {
            dfs(root->left, path, node);
        } else {
            dfs(root->right, path, node);
        }
        // path.pop_back(); // 无需回溯！
    }
};
int main() {

    system("pause");
    return 0;
}