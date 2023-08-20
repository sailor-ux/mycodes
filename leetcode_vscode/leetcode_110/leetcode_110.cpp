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
    // ƽ�������
    // ��������·����������д
    // �ٷ������ܻ��и��õķ���������  û��
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int maxDepth(TreeNode* root) {
        int num = 0, maxDep = 0;
        dfs(num, maxDep, root);
        return maxDep;
    }
    void dfs(int& num, int& maxDep, TreeNode* root) {
        if (!root) {
            return;
        }
        num++;
        if (!root->left && !root->right && num > maxDep) {
            maxDep = num;
        }
        dfs(num, maxDep, root->left);
        dfs(num, maxDep, root->right);
        num--;
    }
    vector<vector<int>> findAllPath(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> pathes;
        dfs(pathes, path, root);
        return pathes;
    }
    void dfs(vector<vector<int>>& pathes, vector<int>& path, TreeNode* root) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right) {
            pathes.push_back(path);
        }
        dfs(pathes, path, root->left);
        dfs(pathes, path, root->right);
        path.pop_back();
    }
};
int main() {

    system("pause");
    return 0;
}