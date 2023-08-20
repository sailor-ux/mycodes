#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};
// https://www.acwing.com/problem/content/31/
class Solution {
public:
    TreeNode* getNextNode(TreeNode* pNode) {
        if (!pNode) {
            return NULL;
        }
        if (pNode->right) {
            TreeNode* next = pNode->right;
            while (next->left) {
                next = next->left;
            }
            return next;
        } else {
            TreeNode* fa = pNode->father;
            if (!fa) {
                return NULL;
            }
            if (fa->left == pNode) {
                return fa;
            }
            // 以fa为根节点的这棵树已经完成了中序遍历！
            TreeNode* f = NULL;
            while (1) {
                f = fa->father;
                if (!f) {
                    return NULL;
                }
                if (fa == f->left) {
                    return f;
                }
                fa = f;
            }
        }
        return NULL;
    }
    // else中的代码合并一下
    TreeNode* getNextNode(TreeNode* pNode) {
        if (!pNode) {
            return NULL;
        }
        if (pNode->right) {
            TreeNode* next = pNode->right;
            while (next->left) {
                next = next->left;
            }
            return next;
        } else {
            TreeNode* fa = NULL;
            while (1) {
                fa = pNode->father;
                if (!fa) {
                    return NULL;
                }
                if (fa->left == pNode) {
                    return fa;
                }
                pNode = fa;
            }
        }
        return NULL;
    }
};
int main() {

    system("pause");
    return 0;
}