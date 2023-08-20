#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 回溯法，暴力搜索，暴力解法。
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        dfs(nums, 0, target, sum);
        return sum;
    }
    void dfs(vector<int>& nums, int index, int target, int& sum) {
        if (index == nums.size()) {
            if (target == 0) {
                sum++;
            }
            return;
        }
        dfs(nums, index + 1, target - nums[index], sum);
        dfs(nums, index + 1, target + nums[index], sum);
    }
};
int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    Solution sol;
    cout << sol.findTargetSumWays(nums, 3);
    system("pause");
    return 0;
}