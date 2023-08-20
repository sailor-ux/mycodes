#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B || !A) {
            return false;
        }
        if (A->val == B->val) {
            if (doesTree1HaveTree2(A, B)) {
                return true;
            }
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool doesTree1HaveTree2(TreeNode* root1, TreeNode* root2) {
        if (!root2) {
            return true;
        }
        if (!root1) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return doesTree1HaveTree2(root1->left, root2->left) && doesTree1HaveTree2(root1->right, root2->right);
    }
};
int main() {

    system("pause");
    return 0;
}