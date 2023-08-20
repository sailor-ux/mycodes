#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    // 适用于任意一棵树
    //  unordered_map<int, int>只能对key排序，vector<pair<int, int>>可以对value(second)排序！！！
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        dfs(root, mp);
        vector<pair<int, int>> vec(mp.begin(), mp.end()); // 用unordered_map<int, int>初始化vector<pair<int, int>>
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        // sort(vec.begin(), vec.end(), cmp);
        vector<int> res{vec[0].first};
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[i - 1].second) {
                res.push_back(vec[i].first);
                continue;
            }
            break;
        }
        return res;
    }
    /* static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    } */
    void dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) {
            return;
        }
        mp[root->val]++;
        dfs(root->left, mp);
        dfs(root->right, mp);
    }
    /* // 前序遍历递归
    vector<int> preorder(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    } */
};
int main() {

    system("pause");
    return 0;
}