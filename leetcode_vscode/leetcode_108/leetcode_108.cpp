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
    // nums就是二叉搜索树的中序遍历，反推出这颗二叉搜索树(题目还要求高度平衡，平衡二叉树)
    // nums可以选择任意一个元素作为根节点，左边是左子树(二叉搜索树且平衡二叉树)，右边同理
    // 为了保证平衡，根节点的选择在中间！！！
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, left, mid - 1);
        node->right = dfs(nums, mid + 1, right);
        return node;
    }
};
int main() {

    system("pause");
    return 0;
}