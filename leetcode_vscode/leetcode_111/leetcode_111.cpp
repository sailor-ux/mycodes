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
    // 自己写的太慢了，题解的方法要再去看！！！
    int minDepth(TreeNode* root) {
        int num = 0, minDep = 0;
        bool flag = true;
        dfs(root, num, minDep, flag);
        return minDep;
    }
    void dfs(TreeNode* root, int& num, int& minDep, bool& flag) {
        if (!root) {
            return;
        }
        num++;
        if (num == minDep && !flag) { // 此时路径再继续往下搜索，最终的长度num>=minDep，不对minDep产生任何影响！没必要往下走了，可以回溯了！！！
            num--;                    // 相当于出栈，做回溯
            return;
        }
        if (!root->left && !root->right && (num < minDep || flag)) { // flag的目的：保证第一次搜索到的路径的长度num一定赋值给minDep
            minDep = num;
            flag = false;
        }
        dfs(root->right, num, minDep, flag);
        dfs(root->left, num, minDep, flag);
        num--;
    }
    // leetcode_129:
    int sumNumbers(TreeNode* root) {
        int tempSum = 0, allSum = 0;
        dfs(root, tempSum, allSum);
        return allSum;
    }
    void dfs(TreeNode* root, int& tempSum, int& allSum) {
        if (!root) {
            return;
        }
        tempSum = 10 * tempSum + root->val;
        if (!root->left && !root->right) {
            allSum += tempSum;
        }
        dfs(root->right, tempSum, allSum);
        dfs(root->left, tempSum, allSum);
        tempSum /= 10;
    }
    vector<vector<int>> findALLPath(TreeNode* root) { //搜索二叉树的所有路径
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
        dfs(root->right, path, pathes);
        dfs(root->left, path, pathes);
        path.pop_back();
    }
};
int main() {
    // TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(9);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(2);
    // root->left->left->right = new TreeNode(2);
    // root->right->left->right = new TreeNode(0);
    // root->right->left->right->left = new TreeNode(0);
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    Solution sol;
    cout << sol.minDepth(root) << "\n";
    cout << sol.sumNumbers(root) << "\n";
    vector<vector<int>> pathes = sol.findALLPath(root);
    for (vector<int> path : pathes) {
        for (int x : path) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}