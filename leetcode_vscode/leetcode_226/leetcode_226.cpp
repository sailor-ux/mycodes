#include <iostream>
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
    // ���¶��ϵĵݹ飡
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = left;
        return root;
    }

    // ���϶��µĵݹ飡
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // root->left = invertTree(root->right);
    // root->right = invertTree(root->left);
    // �����д����������ҵģ������⣡
};
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution sol;
    root = sol.invertTree(root);
    system("pause");
    return 0;
}