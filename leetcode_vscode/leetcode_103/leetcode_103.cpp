#include <algorithm>
#include <iostream>
#include <queue>
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
    // bfs ∂”¡–queue
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        bool flag = false;
        q.push(root);
        while (!q.empty()) {
            res.push_back({});
            int currLayerNodeNum = q.size();
            for (int i = 1; i <= currLayerNodeNum; i++) {
                TreeNode* node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (flag) {
                reverse(res.back().begin(), res.back().end());
            }
            flag = !flag;
        }
        return res;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    vector<vector<int>> res = sol.zigzagLevelOrder(root);
    for (const vector<int>& vec : res) {
        for (const int& x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}