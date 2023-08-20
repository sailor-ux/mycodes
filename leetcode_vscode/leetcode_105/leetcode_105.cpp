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
    // �ݹ鷨
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int index = 0;
        while (1) {
            if (inorder[index++] == preorder[0]) {
                break;
            }
        }
        vector<int> right_preorder = preorder;
        vector<int> right_inorder = inorder;
        preorder.assign(preorder.begin() + 1, preorder.begin() + index);             //��ǰ
        inorder.assign(inorder.begin(), inorder.begin() + index - 1);                //����
        right_preorder.assign(right_preorder.begin() + index, right_preorder.end()); //��ǰ
        right_inorder.assign(right_inorder.begin() + index, right_inorder.end());    //����
        root->left = buildTree(preorder, inorder);                                   //����������������ָ�����������ڵ��ָ��
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }

    // ���԰�
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int index = 0;
        while (1) {
            if (inorder[index++] == preorder[0]) {
                break;
            }
        }
        index--; // �����������index��λ���ڵ��λ�ã����ǲ��ù�ϣ����ٶ�λ�� ��������
        vector<int> temp_preorder = preorder;
        vector<int> temp_inorder = inorder;
        preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + index);          //��ǰ
        inorder.assign(inorder.begin(), inorder.begin() + index);                     //����
        temp_preorder.assign(temp_preorder.begin() + index + 1, temp_preorder.end()); //��ǰ
        temp_inorder.assign(temp_inorder.begin() + index + 1, temp_inorder.end());    //����
        root->left = dfs(preorder, inorder);
        root->right = dfs(temp_preorder, temp_inorder);
        return root;
    }
};
int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    // vector<int> vec = {9, 3, 4};
    // vec.assign(vec.begin() + 1, vec.begin() + 1); //[first, last) ��first=last, vecΪ��
    // if (vec.empty()) {
    //     cout << "kong"
    //          << "\n";
    // }
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << root->val << "\n";
    cout << root->left->val << ' ' << root->right->val << "\n";
    cout << root->right->left->val << ' ' << root->right->right->val << "\n";
    system("pause");
    return 0;
}