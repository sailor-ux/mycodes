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
    // 中序，左根右，迭代法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (!stk.empty() || curr) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); // curr指向最左下, curr->left = null
            stk.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
        return ret;
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
    Solution sol;
    vector<int> res = sol.inorderTraversal(root);
    for (const int& x : res) {
        cout << x << ' ';
    }
}

// vector<int> ret;
// stack<TreeNode*> stk;
// TreeNode* curr = root;
// do {
//     while (curr) {
//         stk.push(curr);
//         curr = curr->left;
//     }
//     curr = stk.top();//curr指向最左下, curr->left = null
//     stk.pop();
//     ret.push_back(curr->val);
//     curr = curr->right;
// } while (!stk.empty());
// return ret;