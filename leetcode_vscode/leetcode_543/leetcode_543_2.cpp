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
    int maxVal = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxVal;
    }
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        maxVal = max(maxVal, left + right);
        return max(left, right) + 1;
    }
};
int main() {

    system("pause");
    return 0;
}