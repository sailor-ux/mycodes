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
    // ÖÐÐò£¬×ó¸ùÓÒ£¬µÝ¹é
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        dfs(root, vec);
        return vec;
    }
    void dfs(TreeNode* root, vector<int>& vec) {
        if (!root) {
            return;
        }
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
};
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(2);
    root->left->left->right = new TreeNode(2);
    Solution sol;
    vector<int> res = sol.inorderTraversal(root);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}