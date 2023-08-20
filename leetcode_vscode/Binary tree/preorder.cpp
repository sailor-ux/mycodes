#include <iostream>
#include <stack>
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
    // ǰ�򣺸�����
    // �ݹ鷨
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }
    // ������
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                res.push_back(cur->val); // ǰ������ĵ���
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            // res.push_back(cur->val); // ��������ĵ���
            cur = cur->right;
        }
        return res;
    }
    // ������
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}