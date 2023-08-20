#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// ƽ���������
class Solution {
public:
    // ��Ҫ�ظ������ڵ��Σ�����������
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
    // ��������������Ҳ���Բ���ģ��
    // ��������������ɵݹ鶨��ģ����Ժܶ����������Ŀ�������õݹ�����
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftTreeDepth = maxDepth(root->left);
        int rightTreeDepth = maxDepth(root->right);
        return max(leftTreeDepth, rightTreeDepth) + 1;
    }
    // ÿ���ڵ�ֻ����һ�ε���������ܶ࣡
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }
    int recur(TreeNode* root) { // ����(���Ҹ�)��������֦�ļ��ɣ�����rootָ������������ȣ���rootָ����������ƽ�⣬����-1
        if (!root) {
            return 0;
        }
        int left = recur(root->left); // left��ʾ����������ȣ���Ϊ-1��˵�����ӽڵ㲻ƽ�⣬��ôrootָ��������Ҳ��ƽ�⣡
        if (left == -1) {
            return -1;
        }
        int right = recur(root->right); // right��ʾ����������ȣ���Ϊ-1��˵�����ӽڵ㲻ƽ�⣬��ôrootָ��������Ҳ��ƽ�⣡
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