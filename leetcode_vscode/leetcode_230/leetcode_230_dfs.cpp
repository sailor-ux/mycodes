#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        dfs(root, res, k);
        return res;
    }
    void dfs(TreeNode* root, int& res, int& k) {
        if (!root) {
            return;
        }
        dfs(root->left, res, k);
        if (k == 0) {
            return;
        }
        if (--k == 0) {
            res = root->val;
            return;
        }
        dfs(root->right, res, k);
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution sol;
    cout << sol.kthSmallest(root, 3);
    system("pause");
    return 0;
}