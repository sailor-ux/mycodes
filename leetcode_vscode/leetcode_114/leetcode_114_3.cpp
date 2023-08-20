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
    // 根左右
    // 修改后的前序遍历的具体做法是，每次从栈内弹出一个节点作为当前访问的节点，获得该节点的子节点，如果子节点不为空，则依次将右子节点和左子节点压入栈内（注意入栈顺序）。
    // 展开为单链表的做法是，维护上一个访问的节点 prev，每次访问一个节点时，令当前访问的节点为 curr，将 prev 的左子节点设为 null 以及将 prev 的右子节点设为 curr，然后将 curr 赋值给 prev，进入下一个节点的访问，直到遍历结束。需要注意的是，初始时 prev 为 null，只有在 prev 不为 null 时才能对 prev 的左右子节点进行更新。
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