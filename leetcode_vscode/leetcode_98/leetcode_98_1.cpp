#include <iostream>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
        stack<int> stk;
        bool flag = true;
        dfs(root, stk, flag);
        return flag;
    }
    void dfs(TreeNode* root, stack<int>& stk, bool& flag) {
        if (!flag) { // 一旦找到是false，立刻一层一层往回结束dfs，直到第一层的dfs结束，
            return;  //第一次调用的dfs结束，最终返回false。避免后面没必要走的dfs的调用，节省时间！
        }
        if (!root) {
            return;
        }
        dfs(root->left, stk, flag);
        if (!stk.empty() && root->val <= stk.top()) {
            flag = false;
            // return; 可有可无 有稍微快一点！
        } else {
            stk.push(root->val);
        }
        dfs(root->right, stk, flag);
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << sol.isValidBST(root);
    system("pause");
    return 0;
}