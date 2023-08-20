#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 平衡二叉树！
class Solution {
public:
    // 需要重复遍历节点多次，很慢！！！
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int leftTreeDepth = maxDepth(root->left);
        int rightTreeDepth = maxDepth(root->right);
        int diff = abs(leftTreeDepth - rightTreeDepth);
        if (diff > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    // 计算二叉树的深度也可以不用模板
    // 二叉树本身就是由递归定义的，所以很多二叉树的题目都可以用递归来解
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftTreeDepth = maxDepth(root->left);
        int rightTreeDepth = maxDepth(root->right);
        return max(leftTreeDepth, rightTreeDepth) + 1;
    }
    // 每个节点只遍历一次的做法，快很多！
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }
    int recur(TreeNode* root) { // 后序(左右根)，包含剪枝的技巧，计算root指向的这棵树的深度，若root指向的这棵树不平衡，返回-1
        if (!root) {
            return 0;
        }
        int left = recur(root->left); // left表示左子树的深度，若为-1，说明左子节点不平衡，那么root指向的这棵树也不平衡！
        if (left == -1) {
            return -1;
        }
        int right = recur(root->right); // right表示右子树的深度，若为-1，说明右子节点不平衡，那么root指向的这棵树也不平衡！
        if (right == -1) {
            return -1;
        }
        int diff = abs(left - right);
        return diff < 2 ? max(left, right) + 1 : -1;
    }
};
int main() {

    system("pause");
    return 0;
}