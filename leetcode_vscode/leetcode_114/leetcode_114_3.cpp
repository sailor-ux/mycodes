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
    // ������
    // �޸ĺ��ǰ������ľ��������ǣ�ÿ�δ�ջ�ڵ���һ���ڵ���Ϊ��ǰ���ʵĽڵ㣬��øýڵ���ӽڵ㣬����ӽڵ㲻Ϊ�գ������ν����ӽڵ�����ӽڵ�ѹ��ջ�ڣ�ע����ջ˳�򣩡�
    // չ��Ϊ������������ǣ�ά����һ�����ʵĽڵ� prev��ÿ�η���һ���ڵ�ʱ���ǰ���ʵĽڵ�Ϊ curr���� prev �����ӽڵ���Ϊ null �Լ��� prev �����ӽڵ���Ϊ curr��Ȼ�� curr ��ֵ�� prev��������һ���ڵ�ķ��ʣ�ֱ��������������Ҫע����ǣ���ʼʱ prev Ϊ null��ֻ���� prev ��Ϊ null ʱ���ܶ� prev �������ӽڵ���и��¡�
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode *prev = nullptr, *curr = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();
            if (prev) {
                prev->left = nullptr;
                prev->right = curr;
            }
            if (curr->right) {
                stk.push(curr->right);
            }
            if (curr->left) {
                stk.push(curr->left);
            }
            prev = curr;
        }

        // while (1) {
        //     if (prev) {
        //         prev->left = nullptr;
        //         prev->right = curr;
        //     }
        //     if (curr->right) {
        //         stk.push(curr->right);
        //     }
        //     if (curr->left) {
        //         stk.push(curr->left);
        //     }
        //     prev = curr;
        //     if (stk.empty()) {
        //         return;
        //     }
        //     curr = stk.top();
        //     stk.pop();
        // }
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