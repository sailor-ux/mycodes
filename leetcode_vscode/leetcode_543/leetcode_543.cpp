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
    // 有问题，无法全部通过！！！
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return 0;
        }
        if (root->left && root->right) {
            return 2 + diameterOfBinaryTree(root->left) + diameterOfBinaryTree(root->right);
        }
        return 1 + diameterOfBinaryTree(root->left) + diameterOfBinaryTree(root->right);
    }
};
int main() {

    system("pause");
    return 0;
}