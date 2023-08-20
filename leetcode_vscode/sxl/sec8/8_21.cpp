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
    // 递归
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { // 没有找到要删除的节点
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {                               // root节点即为要删除的节点
            if (!root->left && !root->right) { // 叶子节点
                return nullptr;
            } else if (!root->left) { // 左孩子为空，右孩子不为空
                return root->right;
            } else if (!root->right) { // 左孩子不为空，右孩子为空
                return root->left;
            } else { // 左右孩子都不为空，删除节点的左子树移至右子树的最左下，返回右子树的根节点(删除节点的右孩子)
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            }
        }
        return root;
    }
    // 做到了真正地把该节点释放掉！递归法！
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        if (key == root->val) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->right) {
                TreeNode* tmp = root;
                root = root->left;
                delete tmp;
            } else if (!root->left) {
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            } else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            }
        }
        return root;
    }
    // 做到了真正地把该节点释放掉！迭代法！
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (key == cur->val) {
                break;
            } else if (key < cur->val) {
                pre = cur;
                cur = cur->left;
            } else {
                pre = cur;
                cur = cur->right;
            }
        }
        if (!cur) { // 要删除的节点不存在
            return root;
        }
        if (!pre) { // 要删除根节点
            return deleteNodeOperation(root);
        }
        if (pre->left == cur) { // 要删除cur节点并且它是pre的左孩子
            pre->left = deleteNodeOperation(cur);
        }
        if (pre->right == cur) { // 要删除cur节点并且它是pre的右孩子
            pre->right = deleteNodeOperation(cur);
        }
        return root;
    }
    TreeNode* deleteNodeOperation(TreeNode* node) { // 删除node节点
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->left) {
            TreeNode* tmp = node;
            node = node->right;
            delete tmp;
        } else if (!node->right) {
            TreeNode* tmp = node;
            node = node->left;
            delete tmp;
        } else {
            TreeNode* cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }
            cur->left = node->left;
            TreeNode* tmp = node;
            node = node->right;
            delete tmp;
        }
        return node;
    }
};