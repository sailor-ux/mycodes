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
    // ²»Í×£¡£¡
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        if (root->val == targetSum) {
            return 1 + pathSum(root->left, targetSum - (root->val)) + pathSum(root->right, targetSum - (root->val)) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        }
        return pathSum(root->left, targetSum - (root->val)) + pathSum(root->right, targetSum - (root->val)) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
int main() {

    return 0;
}