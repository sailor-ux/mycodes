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
    // 适用于二叉搜索树
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
    TreeNode* pre;
    int count;
    int maxCount;
    vector<int> res;
    Solution() : pre(nullptr), count(0), maxCount(0) {
    }
    /* void dfs(TreeNode* cur) { // 中序遍历
        if (!cur) {
            return;
        }
        dfs(cur->left);
        if (!pre) { // cur指向中序遍历的第一个结点，二叉排序树的最左下结点
            count = 1;
        } else {
            if (cur->val == pre->val) {
                count++;
            } else {
                if (count == maxCount) {
                    res.push_back(pre->val);
                } else if (count > maxCount) {
                    res.clear();
                    res.push_back(pre->val); // 这样有bug！
                    maxCount = count;
                }
                count = 1;
            }
        }
        pre = cur;
        dfs(cur->right);
    } */
    void dfs(TreeNode* cur) { // 中序遍历
        if (!cur) {
            return;
        }
        dfs(cur->left);
        // count表示pre指向的结点的val在二叉搜索树(的前面一部分)中出现的频次，count还没有统计cur
        if (!pre) { // cur指向中序遍历的第一个结点，二叉排序树的最左下结点
            count = 1;
        } else {
            if (cur->val == pre->val) {
                count++;
            } else {
                count = 1;
            }
        }
        // count表示cur指向的结点的val在{二叉搜索树的中序遍历的前面一部分(中序遍历的第一个->cur那一个)}中出现的频次，count统计完了cur
        if (count == maxCount) {
            res.push_back(cur->val);
        } else if (count > maxCount) {
            res.clear();
            res.push_back(cur->val);
            maxCount = count;
        }
        pre = cur;
        dfs(cur->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    Solution sol;
    vector<int> res = sol.findMode(root);
    for (int x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}