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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        bool flagP = false, flagQ = false;
        dfs(root, pathP, p, flagP);
        dfs(root, pathQ, q, flagQ);
        int lenP = pathP.size(), lenQ = pathQ.size();
        int idx = 0;
        while (idx < lenP && idx < lenQ && pathP[idx] == pathQ[idx]) {
            idx++;
        }
        return pathP[idx - 1];
    }
    void dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* node, bool& flag) {
        if (!root) {
            return;
        }
        path.push_back(root);
        if (root == node) {
            flag = true;
            return;
        }
        dfs(root->left, path, node, flag);
        if (flag) {
            return;
        }
        dfs(root->right, path, node, flag);
        if (flag) {
            return;
        }
        path.pop_back();
    }
};
int main() {

    system("pause");
    return 0;
}