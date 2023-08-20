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
    // ����������������·��(ǰ�� + ����)��ʮ�־��䣬�ܶ���Ŀ����������
    // ����ǰ�����
    vector<vector<int>> getALLPath(TreeNode* root) {
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
    // ��������(���)��ȣ��������Ĳ�����maxPathLen����������ģ�����
    int maxDepth(TreeNode* root) {
        int pathLen = 0, maxPathLen = 0;
        dfs(root, pathLen, maxPathLen);
        return maxPathLen;
    }
    void dfs(TreeNode* root, int& pathLen, int& maxPathLen) {
        if (!root) {
            return;
        }
        pathLen++;
        /* if (!root->left && !root->right) {
            maxPathLen = max(maxPathLen, pathLen);
        } */
        if (!root->left && !root->right && pathLen > maxPathLen) {
            maxPathLen = pathLen;
        }
        dfs(root->left, pathLen, maxPathLen);
        dfs(root->right, pathLen, maxPathLen);
        pathLen--;
    }
    // ��������������Ҳ���Բ���ģ��
    // ��������������ɵݹ鶨��ģ����Ժܶ����������Ŀ�������õݹ�����
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftTreeDepth = maxDepth(root->left);
        int rightTreeDepth = maxDepth(root->right);
        return max(leftTreeDepth, rightTreeDepth) + 1;
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