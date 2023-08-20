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
        hash[0] = 1; // ���Ǹ��ڵ��ֵ=targetSumʱ�����ڵ㱾��Ҳ��һ��·����
        long long curSum = 0;
        return dfs(root, targetSum, hash, curSum);
    }
    // ������ֵ�Ļ����㷨��������nodeָ���������е�ÿһ���ڵ�Ϊ��β��·��������֮��(��д��������ֵ�Ļ���)
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