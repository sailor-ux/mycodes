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
    // µÝ¹é
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    // µü´ú
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            pre = cur;
            if (val < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (val < pre->val) {
            pre->left = new TreeNode(val);
        } else {
            pre->right = new TreeNode(val);
        }
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}