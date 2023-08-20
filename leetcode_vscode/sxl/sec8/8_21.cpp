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
    // �ݹ�
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { // û���ҵ�Ҫɾ���Ľڵ�
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {                               // root�ڵ㼴ΪҪɾ���Ľڵ�
            if (!root->left && !root->right) { // Ҷ�ӽڵ�
                return nullptr;
            } else if (!root->left) { // ����Ϊ�գ��Һ��Ӳ�Ϊ��
                return root->right;
            } else if (!root->right) { // ���Ӳ�Ϊ�գ��Һ���Ϊ��
                return root->left;
            } else { // ���Һ��Ӷ���Ϊ�գ�ɾ���ڵ�������������������������£������������ĸ��ڵ�(ɾ���ڵ���Һ���)
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
    // �����������ذѸýڵ��ͷŵ����ݹ鷨��
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
    // �����������ذѸýڵ��ͷŵ�����������
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
        if (!cur) { // Ҫɾ���Ľڵ㲻����
            return root;
        }
        if (!pre) { // Ҫɾ�����ڵ�
            return deleteNodeOperation(root);
        }
        if (pre->left == cur) { // Ҫɾ��cur�ڵ㲢������pre������
            pre->left = deleteNodeOperation(cur);
        }
        if (pre->right == cur) { // Ҫɾ��cur�ڵ㲢������pre���Һ���
            pre->right = deleteNodeOperation(cur);
        }
        return root;
    }
    TreeNode* deleteNodeOperation(TreeNode* node) { // ɾ��node�ڵ�
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