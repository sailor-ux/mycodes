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
    // �����ڶ���������
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
    /* void dfs(TreeNode* cur) { // �������
        if (!cur) {
            return;
        }
        dfs(cur->left);
        if (!pre) { // curָ����������ĵ�һ����㣬�����������������½��
            count = 1;
        } else {
            if (cur->val == pre->val) {
                count++;
            } else {
                if (count == maxCount) {
                    res.push_back(pre->val);
                } else if (count > maxCount) {
                    res.clear();
                    res.push_back(pre->val); // ������bug��
                    maxCount = count;
                }
                count = 1;
            }
        }
        pre = cur;
        dfs(cur->right);
    } */
    void dfs(TreeNode* cur) { // �������
        if (!cur) {
            return;
        }
        dfs(cur->left);
        // count��ʾpreָ��Ľ���val�ڶ���������(��ǰ��һ����)�г��ֵ�Ƶ�Σ�count��û��ͳ��cur
        if (!pre) { // curָ����������ĵ�һ����㣬�����������������½��
            count = 1;
        } else {
            if (cur->val == pre->val) {
                count++;
            } else {
                count = 1;
            }
        }
        // count��ʾcurָ��Ľ���val��{���������������������ǰ��һ����(��������ĵ�һ��->cur��һ��)}�г��ֵ�Ƶ�Σ�countͳ������cur
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