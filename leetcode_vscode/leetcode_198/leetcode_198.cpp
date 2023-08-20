#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(2); // 滚动数组压缩，压缩到只有两个元素的空间
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = dp[1];
            dp[1] = max(dp[0] + nums[i], dp[1]);
            dp[0] = temp;
        }
        return dp[1];
    }
};
int main() {
    vector<int> nums{2, 7, 9, 3, 1};
    Solution sol;
    cout << sol.rob(nums);
    system("pause");
    return 0;
}