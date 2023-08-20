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
        return dfs(root, targetSum, hash, curSum);
    }
    // 带返回值的回溯算法，返回以node指向的这棵树中的每一个节点为结尾的路径的数量之和(先写不带返回值的回溯)
    int dfs(TreeNode* node, const int& targetSum, unordered_map<long long, int>& hash, long long& curSum) {
        if (!node) {
            return 0;
        }
        curSum += node->val;
        int res = hash[curSum - targetSum];
        hash[curSum]++;
        res += dfs(node->left, targetSum, hash, curSum);
        res += dfs(node->right, targetSum, hash, curSum);
        hash[curSum]--;
        curSum -= node->val;
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}