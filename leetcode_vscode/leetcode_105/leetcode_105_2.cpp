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
    // �������ı�����ǰ�к��򶼿ɲ���dfs�ݹ�(ֻ������˳��һ��)
    // ͬ����ǰ����������ȥ���������ʱ��Ҳ���Բ��õݹ飡
    // �ݹ鷨, �����˹�ϣ����ٵ�����������ж�λ���ڵ��λ��
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashInorder;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            hashInorder[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, hashInorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, unordered_map<int, int>& hashInorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorder_left]);
        int index = hashInorder[preorder[preorder_left]];
        root->left = myBuildTree(preorder, inorder, hashInorder, preorder_left + 1, index - inorder_left + preorder_left, inorder_left, index - 1); //��������ǰ�������������򣬹���������������ָ�����������ڵ��ָ��
        root->right = myBuildTree(preorder, inorder, hashInorder, index - inorder_left + preorder_left + 1, preorder_right, index + 1, inorder_right);
        return root;
    }
};
int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << root->val << "\n";
    cout << root->left->val << ' ' << root->right->val << "\n";
    cout << root->right->left->val << ' ' << root->right->right->val << "\n";
    system("pause");
    return 0;
}