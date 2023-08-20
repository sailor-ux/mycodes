#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        for (; i < n; i++) {
            if (inorder[i] == preorder[0]) {
                break;
            }
        }
        vector<int> leftTreePreorder, leftTreeInorder, rightTreePreorder, rightTreeInorder;
        leftTreePreorder.assign(preorder.begin() + 1, preorder.begin() + i + 1);
        leftTreeInorder.assign(inorder.begin(), inorder.begin() + i);
        rightTreePreorder.assign(preorder.begin() + i + 1, preorder.end());
        rightTreeInorder.assign(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(leftTreePreorder, leftTreeInorder);
        root->right = buildTree(rightTreePreorder, rightTreeInorder);
        return root;
    }
};
int main() {

    system("pause");
    return 0;
}