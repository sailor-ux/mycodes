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
class Solution {
  public:
    // ¸ù×óÓÒ£¬µü´ú·¨
    void flatten(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        // vector<TreeNode*> vec;
        auto vec = vector<TreeNode*>();
        while (root || !stk.empty()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                vec.push_back(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (i == vec.size() - 1) {
                vec[i]->left = nullptr;
                vec[i]->right = nullptr;
                break;
            }
            vec[i]->right = vec[i + 1];
            vec[i]->left = nullptr;
        }
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
    sol.flatten(root);
    while (root) {
        cout << root->val << ' ';
        root = root->right;
    }
    system("pause");
    return 0;
}