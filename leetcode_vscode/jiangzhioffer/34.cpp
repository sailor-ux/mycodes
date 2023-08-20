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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        int pathSum = 0;
        vector<int> path;
        vector<vector<int>> pathes;
        dfs(root, path, pathes, pathSum, target);
        return pathes;
    }
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& pathes, int& pathSum, const int& target) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        pathSum += root->val;
        if (!root->left && !root->right && pathSum == target) {
            pathes.push_back(path);
        }
        dfs(root->left, path, pathes, pathSum, target);
        dfs(root->right, path, pathes, pathSum, target);
        path.pop_back();
        pathSum -= root->val;
    }
};
int main() {

    system("pause");
    return 0;
}