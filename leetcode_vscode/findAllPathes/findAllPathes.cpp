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
    vector<vector<int>> findAllPathes(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> pathes;
        dfs(root, path, pathes);
        if (path.empty()) {
            cout << "pathÎª¿Õ!!!"
                 << "\n";
        }
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
    vector<vector<int>> pathes = sol.findAllPathes(root);
    for (auto path : pathes) {
        for (int x : path) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}