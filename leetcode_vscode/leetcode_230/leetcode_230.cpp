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
    int kthSmallest(TreeNode* root, int k) {
    }
    void dfs(TreeNode* root, int& minVal, TreeNode*& node) { // ��ʱ�������ô��ݣ���
        if (!root) {
            return;
        }
        if (root->val < minVal) {
            minVal = root->val;
            node = root;
        }
        dfs(root->left, minVal, node);
        dfs(root->right, minVal, node);
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int minVal = INT_MAX;
    // TreeNode* node = new TreeNode(-100);
    TreeNode* node = nullptr;
    Solution sol;
    sol.dfs(root, minVal, node); // ע����ʵ����������ֵ���ݣ���nodeһֱָ��-100�Ľ�㣡
    cout << minVal << ' ' << node->val;
    system("pause");
    return 0;
}