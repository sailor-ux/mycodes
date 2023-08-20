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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> arr;
        vector<int> record;
        dfs(root, arr);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i]->val < arr[i - 1]->val) {
                if (!record.empty()) {
                    record.push_back(i);
                    break;
                }
                record.push_back(i - 1);
            }
        }
        if (record.size() == 2) {
            int temp = arr[record[0]]->val;
            arr[record[0]]->val = arr[record[1]]->val;
            arr[record[1]]->val = temp;
        } else {
            int temp = arr[record[0]]->val;
            arr[record[0]]->val = arr[record[0] + 1]->val;
            arr[record[0] + 1]->val = temp;
        }
    }
    void dfs(TreeNode* root, vector<TreeNode*>& arr) {
        if (!root) {
            return;
        }
        dfs(root->left, arr);
        arr.push_back(root);
        dfs(root->right, arr);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    Solution sol;
    sol.recoverTree(root);
    cout << root->val << ' ' << root->left->val;
    system("pause");
    return 0;
}