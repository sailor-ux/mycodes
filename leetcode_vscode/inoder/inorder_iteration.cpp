#include <iostream>
#include <stack>
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
vector<int> inorder(TreeNode* root) { // 中序遍历的顺序参考(就是)下落落地的顺序
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while (!stk.empty() || cur) { // 考虑当栈中只有一个根节点的时候！！！
        while (cur) {
            stk.push(cur);
            cur = cur->left; // 走到最左下，再转右
        }
        cur = stk.top();
        stk.pop();
        res.push_back(cur->val);
        cur = cur->right; // 走到最左下，再转右
    }
    return res;
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