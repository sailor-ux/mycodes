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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        stack<int> inoder;
        dfs(root, inoder, flag);
        return flag;
    }
    //  参考中序遍历，左根右
    void dfs(TreeNode* root, stack<int>& inoder, bool& flag) {
        if (!flag) {
            return;
        }
        if (!root) {
            return;
        }
        dfs(root->left, inoder, flag);
        if (inoder.empty() || root->val > inoder.top()) {
            inoder.push(root->val);
        } else {
            flag = false;
            return;
        }
        dfs(root->right, inoder, flag);
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