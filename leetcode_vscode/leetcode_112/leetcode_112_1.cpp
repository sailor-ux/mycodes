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
    // 最简约的版本！！！
    // 基于经典的算法：搜索二叉树的所有路径！！！
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag = false;
        dfs(root, sum, targetSum, flag);
        cout << "sum = " << sum << endl;
        return flag;
    }
    void dfs(TreeNode* root, int& sum, const int& targetSum, bool& flag) {
        if (!root || flag) {
            return;
        }
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == targetSum) {
                flag = true;
            }
        }
        dfs(root->left, sum, targetSum, flag); // 左子树能不能行，能flag变true，不能仍为false
        dfs(root->right, sum, targetSum, flag);
        sum -= root->val;
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    Solution sol;
    cout << sol.hasPathSum(root, 22);
    system("pause");
    return 0;
}