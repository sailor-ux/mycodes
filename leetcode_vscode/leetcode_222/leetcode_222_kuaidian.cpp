#include <iostream>
#include <queue>
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
        int num = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int curLayerNodeNum = q.size();
            num += curLayerNodeNum; // 一次性＋这么多，比起每次＋1，时间效率高很多！！
            for (int i = 0; i < curLayerNodeNum; i++) {
                TreeNode* node = q.front();
                q.pop();
                // num++; 每次＋1
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return num;
    }
};
int main() {

    system("pause");
    return 0;
}