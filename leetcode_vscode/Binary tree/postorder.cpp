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
// 注意：
// 前、中、后序遍历的迭代法，单纯地做个遍历没问题，但是用到具体的题目中去解题很可能出错！！！
class Solution {
public:
    // 后序：左右根
    // 递归法
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
    // 迭代法(根右左，再reverse)
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