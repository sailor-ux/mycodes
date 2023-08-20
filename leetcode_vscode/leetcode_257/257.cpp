#include <iostream>
#include <string>
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
    // 搜索二叉树的所有路径(回溯)，十分经典，该题目基于它变形
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> pathes;
        dfs(root, path, pathes);
        return pathes;
    }
    void dfs(TreeNode* root, string& path, vector<string>& pathes) {
        if (!root) {
            return;
        }
        path += to_string(root->val);
        if (!root->left && !root->right) {
            pathes.push_back(path);
        }
        path += "->";
        dfs(root->left, path, pathes);
        dfs(root->right, path, pathes);
        path = path.substr(0, path.length() - 2 - to_string(root->val).length());
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
}