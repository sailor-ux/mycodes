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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int layerNum = 0;
        TreeNode* temp = root;
        while (temp->left) {
            layerNum++;
            temp = temp->left;
        }
        int low = 1 << layerNum, high = (1 << (layerNum + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low; // 一定要求左偏！！！ 举例：6个结点时
            if (isExist(root, layerNum, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    bool isExist(TreeNode* root, const int& layerNum, int k) {
        int bits = 1 << (layerNum - 1);
        while (bits > 0) { // bits >= 1
            if (bits & k) {
                root = root->right;
            } else {
                root = root->left;
            }
            bits >>= 1;
        }
        return root != nullptr;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution sol;
    cout << sol.countNodes(root);
    system("pause");
    return 0;
}