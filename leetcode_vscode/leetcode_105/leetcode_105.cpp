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
    // 递归法
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
        preorder.assign(preorder.begin() + 1, preorder.begin() + index);             //左前
        inorder.assign(inorder.begin(), inorder.begin() + index - 1);                //左中
        right_preorder.assign(right_preorder.begin() + index, right_preorder.end()); //右前
        right_inorder.assign(right_inorder.begin() + index, right_inorder.end());    //右中
        root->left = buildTree(preorder, inorder);                                   //构建左子树，返回指向左子树根节点的指针
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }

    // 粗略版
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
        index--; // 中序遍历中用index定位根节点的位置，考虑采用哈希表快速定位！ 待！！！
        vector<int> temp_preorder = preorder;
        vector<int> temp_inorder = inorder;
        preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + index);          //左前
        inorder.assign(inorder.begin(), inorder.begin() + index);                     //左中
        temp_preorder.assign(temp_preorder.begin() + index + 1, temp_preorder.end()); //右前
        temp_inorder.assign(temp_inorder.begin() + index + 1, temp_inorder.end());    //右中
        root->left = dfs(preorder, inorder);
        root->right = dfs(temp_preorder, temp_inorder);
        return root;
    }
};
int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    // vector<int> vec = {9, 3, 4};
    // vec.assign(vec.begin() + 1, vec.begin() + 1); //[first, last) 若first=last, vec为空
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