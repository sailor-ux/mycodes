#include <iostream>
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
    // ²»¶Ô£¡£¡£¡
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!root->left && !root->right) {
            return true;
        }
        if (root->left && !root->right) {
            if (root->left->val >= root->val) {
                return false;
            }
        }
        if (!root->left && root->right) {
            if (root->right->val <= root->val) {
                return false;
            }
        }
        if (root->left && root->right) {
            if (root->left->val >= root->val || root->right->val <= root->val) {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->left->right = new TreeNode(2);
    Solution sol;
    cout << sol.isValidBST(root);
    system("pause");
    return 0;
}