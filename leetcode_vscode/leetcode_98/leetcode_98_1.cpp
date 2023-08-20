#include <iostream>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
        stack<int> stk;
        bool flag = true;
        dfs(root, stk, flag);
        return flag;
    }
    void dfs(TreeNode* root, stack<int>& stk, bool& flag) {
        if (!flag) { // һ���ҵ���false������һ��һ�����ؽ���dfs��ֱ����һ���dfs������
            return;  //��һ�ε��õ�dfs���������շ���false���������û��Ҫ�ߵ�dfs�ĵ��ã���ʡʱ�䣡
        }
        if (!root) {
            return;
        }
        dfs(root->left, stk, flag);
        if (!stk.empty() && root->val <= stk.top()) {
            flag = false;
            // return; ���п��� ����΢��һ�㣡
        } else {
            stk.push(root->val);
        }
        dfs(root->right, stk, flag);
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << sol.isValidBST(root);
    system("pause");
    return 0;
}