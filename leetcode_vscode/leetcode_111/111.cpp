#include <iostream>
#include <vector>
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
    // 模板：搜索二叉树的所有路径（前序 + 回溯）
    int minDepth(TreeNode* root) {
        int pathLen = 0, minLen = INT_MAX;
        dfs(root, pathLen, minLen);
        return minLen;
    }
    void dfs(TreeNode* root, int& pathLen, int& minLen) {
        if (!root) {
            return;
        }
        pathLen++;
        if (!root->left && !root->right && pathLen < minLen) {
            minLen = pathLen;
        }
        dfs(root->left, pathLen, minLen);
        dfs(root->right, pathLen, minLen);
        pathLen--;
    }
    // 优化加速！
    int minDepth(TreeNode* root) {
        int pathLen = 0, minLen = INT_MAX;
        dfs(root, pathLen, minLen);
        return minLen;
    }
    void dfs(TreeNode* root, int& pathLen, int& minLen) {
        if (!root) {
            return;
        }
        pathLen++;
        if (pathLen == minLen) {
            pathLen--;
            return;
        }
        if (!root->left && !root->right && pathLen < minLen) {
            minLen = pathLen;
        }
        dfs(root->left, pathLen, minLen);
        dfs(root->right, pathLen, minLen);
        pathLen--;
    }
};
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    Solution sol;
    cout << sol.minDepth(root) << "\n";
    system("pause");
    return 0;
}