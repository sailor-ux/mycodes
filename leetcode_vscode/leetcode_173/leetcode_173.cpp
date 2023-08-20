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
// 这题参考中序遍历的迭代法！
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        int ans = node->val;
        node = node->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }
        return ans;
    }

    bool hasNext() {
        return !stk.empty();
    }
};
// 中序遍历的迭代法！
class Solution {
public:
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}