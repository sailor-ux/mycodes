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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxVal = 0;
        dfs(root, maxVal);
        return maxVal;
    }
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
    void dfs(TreeNode* root, int& maxVal) {
        if (!root) {
            return;
        }
        maxVal = max(maxVal, depth(root->left) + depth(root->right));
        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }
};
int main() {

    system("pause");
    return 0;
}