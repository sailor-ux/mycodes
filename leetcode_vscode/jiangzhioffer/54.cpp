#include <iostream>
#include <stack>
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
    // �������������ص�kС��Ԫ��(��������ĵ�k���ڵ㡢Ԫ��)
    int kthMin(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (--k == 0) {
                return cur->val;
            }
            cur = cur->right;
        }
        return -1; // ֻ��Ϊ�˱�֤�����з���ֵ�����������ﷵ��
    }
    // �������������ص�k���Ԫ��
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        int n = res.size();
        return res[n - k];
    }
    // �������������
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}