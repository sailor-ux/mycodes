#include <iostream>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inorderHash;
        for (int i = 0; i < inorder.size(); i++) {
            inorderHash[inorder[i]] = i;
        }
        return myBuildTree(inorderHash, inorder, postorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* myBuildTree(const unordered_map<int, int>& inorderHash, const vector<int>& inorder, const vector<int>& postorder, int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
        if (postorderLeft == postorderRight + 1) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorderRight]);
        int index = inorderHash.at(postorder[postorderRight]);
        root->left = myBuildTree(inorderHash, inorder, postorder, inorderLeft, index - 1, postorderLeft, index - inorderLeft + postorderLeft - 1);
        root->right = myBuildTree(inorderHash, inorder, postorder, index + 1, inorderRight, index - inorderLeft + postorderLeft, postorderRight - 1);
        return root;
    }
};
int main() {
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};
    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);
    cout << root->val << "\n";
    cout << root->left->val << ' ' << root->right->val << "\n";
    cout << root->right->left->val << ' ' << root->right->right->val << "\n";
    system("pause");
    return 0;
}