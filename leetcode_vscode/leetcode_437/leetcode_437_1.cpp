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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> hash;
        hash[0] = 1; // 考虑根节点的值=targetSum时，根节点本身也是一条路径！
        long long curSum = 0;
        int res = 0;
        dfs(root, targetSum, hash, curSum, res);
        return res;
    }
    void dfs(TreeNode* node, const int& targetSum, unordered_map<long long, int>& hash, long long& curSum, int& res) {
        if (!node) {
            return;
        }
        curSum += node->val;
        res += hash[curSum - targetSum];
        hash[curSum]++;
        dfs(node->left, targetSum, hash, curSum, res);
        dfs(node->right, targetSum, hash, curSum, res);
        hash[curSum]--;
        curSum -= node->val;
    }
};
int main() {

    system("pause");
    return 0;
}