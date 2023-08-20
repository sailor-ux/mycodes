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
    // nums���Ƕ�����������������������Ƴ���Ŷ���������(��Ŀ��Ҫ��߶�ƽ�⣬ƽ�������)
    // nums����ѡ������һ��Ԫ����Ϊ���ڵ㣬�����������(������������ƽ�������)���ұ�ͬ��
    // Ϊ�˱�֤ƽ�⣬���ڵ��ѡ�����м䣡����
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, left, mid - 1);
        node->right = dfs(nums, mid + 1, right);
        return node;
    }
};
int main() {

    system("pause");
    return 0;
}