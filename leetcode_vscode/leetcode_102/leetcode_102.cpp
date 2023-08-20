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
    //  用到二叉树的前序遍历，其实还是深度优先搜索
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, int level) { //前序，发现前序遍历可以用！
        if (!root) {
            return;
        }
        if (res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
    vector<vector<int>> findAllPath(TreeNode* root) {
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
        dfs(root->right, path, pathes); //两条语句的顺序可以互换
        path.pop_back();
    }
    int getMaxDepth(TreeNode* root) {
        int num = 0, maxDepth = 0;
        dfs(root, num, maxDepth);
        return maxDepth;
    }
    void dfs(TreeNode* root, int& num, int& maxDepth) {
        if (!root) {
            return;
        }
        num++;
        if (!root->left && !root->right && num > maxDepth) {
            maxDepth = num;
        }
        dfs(root->left, num, maxDepth);
        dfs(root->right, num, maxDepth);
        num--;
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
    vector<vector<int>> allPath = sol.findAllPath(root);
    for (vector<int> path : allPath) {
        for (int x : path) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    cout << "--------------\n";
    cout << sol.getMaxDepth(root) << endl;
    vector<vector<int>> res = sol.levelOrder(root);
    for (vector<int> vec : res) {
        for (int x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}