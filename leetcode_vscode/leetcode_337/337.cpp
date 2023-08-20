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
    // ����dp+�������
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    // vector<int>[0]: ��͵root������ܻ�õ����Ǯ�ң�vector<int>[1]: ͵root������ܻ�õ����Ǯ��
    vector<int> robTree(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        // ͵root������ܻ�õ����Ǯ��
        int val1 = root->val + left[0] + right[0];
        // ��͵root������ܻ�õ����Ǯ��
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};
int main() {

    system("pause");
    return 0;
}