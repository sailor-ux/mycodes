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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> pathes;
        dfs(root, path, pathes);
        // if (path.empty()) {
        //     cout << "pathÎª¿Õ£¡" << endl;
        // }
        return pathes;
    }
    void dfs(TreeNode* node, string& path, vector<string>& pathes) {
        if (!node) {
            return;
        }
        path += to_string(node->val);
        path += "->";
        if (!node->left && !node->right) {
            pathes.push_back(path.substr(0, path.length() - 2));
        }
        dfs(node->left, path, pathes);
        dfs(node->right, path, pathes);
        path = path.substr(0, path.length() - to_string(node->val).length() - 2);
    }
    vector<vector<int>> findAllPathes(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> pathes;
        dfs(root, path, pathes);
        return pathes;
    }
    void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& pathes) {
        if (!node) {
            return;
        }
        path.push_back(node->val);
        if (!node->left && !node->right) {
            pathes.push_back(path);
        }
        dfs(node->left, path, pathes);
        dfs(node->right, path, pathes);
        path.pop_back();
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
    vector<string> pathes = sol.binaryTreePaths(root);
    for (const string& path : pathes) {
        cout << path << "\n";
    }
    system("pause");
    return 0;
}