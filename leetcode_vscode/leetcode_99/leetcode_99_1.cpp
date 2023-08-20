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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<TreeNode*> vec;
        bool flag = false;
        dfs(root, stk, vec, flag);
        swap(vec[0]->val, vec[1]->val);
    }
    void dfs(TreeNode* root, stack<TreeNode*>& stk, vector<TreeNode*>& vec, bool& flag) {
        if (!root) {
            return;
        }
        dfs(root->left, stk, vec, flag);
        if (flag) {
            return;
        }
        if (stk.empty()) {
            stk.push(root);
        } else if (root->val > stk.top()->val) {
            stk.pop();
            stk.push(root);
        } else if (vec.empty()) {
            vec.push_back(stk.top());
            vec.push_back(root);
            stk.pop();
            stk.push(root);
        } else {
            vec.pop_back();
            vec.push_back(root);
            flag = true;
            return;
        }
        dfs(root->right, stk, vec, flag);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    Solution sol;
    sol.recoverTree(root);
    cout << root->val << ' ' << root->left->val;
    system("pause");
    return 0;
}