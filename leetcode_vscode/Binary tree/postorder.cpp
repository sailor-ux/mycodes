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
// ע�⣺
// ǰ���С���������ĵ���������������������û���⣬�����õ��������Ŀ��ȥ����ܿ��ܳ�������
class Solution {
public:
    // �������Ҹ�
    // �ݹ鷨
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
    // ������(��������reverse)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                res.push_back(cur->val);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}