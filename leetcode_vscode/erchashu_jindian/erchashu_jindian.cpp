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
    // 二叉树的最大深度，二叉树的层数
    int maxDepth(TreeNode* root) {
        int maxlen = 0, num = 0;
        dfs(root, num, maxlen);
        return maxlen;
    }
    void dfs(TreeNode* root, int& num, int& maxlen) {
        if (!root) {
            return;
        }
        num++;
        if (!root->left && !root->right && num > maxlen) {
            maxlen = num;
        }
        dfs(root->left, num, maxlen);
        dfs(root->right, num, maxlen);
        num--;
    }

    // 搜索二叉树的所有路径(回溯)，十分经典，很多题目基于它变形
    vector<vector<int>> getAllPath(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> pathes;
        dfs(root, path, pathes);
        return pathes;
    }
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& pathes) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right) {
            pathes.push_back(path);
        }
        dfs(root->left, path, pathes);
        dfs(root->right, path, pathes);
        path.pop_back();
    }
};
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(2);
    root->left->left->right = new TreeNode(2);
    root->right->left->right = new TreeNode(0);
    root->right->left->right->left = new TreeNode(0);
    Solution sol;
    // vector<vector<int>> allpath = sol.getAllPath(root);
    // for (vector<int> path : allpath) {
    //     for (int x : path) {
    //         cout << x << ' ';
    //     }
    //     cout << "\n";
    // }
    // system("pause");
    cout << sol.maxDepth(root);
    system("pause");
    return 0;
}