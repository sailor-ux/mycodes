#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    //当回溯法（暴力搜索，暴力法）时间复杂度很高，甚至超时时，改用记忆化回溯！！！
    //往往这种题目还有更好dp解法！！！
    unordered_map<string, int> hashMemo;
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        return dfs(nums, 0, target);
    }
    int dfs(vector<int>& nums, int index, int target) {
        string str = to_string(index) + "-" + to_string(target);
        if (hashMemo.count(str)) {
            return hashMemo[str];
        }
        if (index == nums.size()) {
            if (target == 0) {
                hashMemo[str] = 1; // 不注释更好，有更好
                return 1;
            }
            hashMemo[str] = 0;
            return 0;
        }
        hashMemo[str] = dfs(nums, index + 1, target - nums[index]) + dfs(nums, index + 1, target + nums[index]);
        return hashMemo[str];
    }
};
int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    Solution sol;
    cout << sol.findTargetSumWays(nums, 3);
    system("pause");
    return 0;
}