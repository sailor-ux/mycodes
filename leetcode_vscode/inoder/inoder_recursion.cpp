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
void dfs(TreeNode* root, vector<int>& res);
vector<int> inorder(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
}
void dfs(TreeNode* root, vector<int>& res) {
    if (!root) {
        return;
    }
    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    vector<int> res = inorder(root);
    for (int x : res) {
        cout << x << " ";
    }
    system("pause");
    return 0;
}