#include <iostream>
#include <queue>
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
    // ´íÎó
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> oneLayer;
        bool flag = true;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                oneLayer.push_back(node->val);
                if (flag) {
                    if (node->right) {
                        q.push(node->right);
                    }
                    if (node->left) {
                        q.push(node->left);
                    }
                } else {
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            flag = !flag;
            res.push_back(oneLayer);
            oneLayer.clear();
        }
        return res;
    }
    // ÕýÈ·
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> oneLayer;
        bool flag = true;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                oneLayer.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!flag) {
                reverse(oneLayer.begin(), oneLayer.end());
            }
            res.push_back(oneLayer);
            oneLayer.clear();
            flag = !flag;
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}