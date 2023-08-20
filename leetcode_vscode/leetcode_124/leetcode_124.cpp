#include <algorithm>
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
    // 复现了题解的思路，思路确并不怎么理解！！！
    int maxPathSum(TreeNode* root) {
        // int maxSum = -1001;
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
    int maxGain(TreeNode* root, int& maxSum) {
        if (!root) {
            return 0;
        }
        int maxGainLeft = max(maxGain(root->left, maxSum), 0); // 注意！！！
        int maxGainRight = max(maxGain(root->right, maxSum), 0);
        maxSum = max(root->val + maxGainLeft + maxGainRight, maxSum);
        return max(maxGainLeft, maxGainRight) + root->val;
    }
};
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << sol.maxPathSum(root);
    system("pause");
    return 0;
}