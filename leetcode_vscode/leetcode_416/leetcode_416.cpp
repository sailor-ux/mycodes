#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
        }
        int n = sum / 2;
        if (2 * n < sum) {
            return false;
        }
        int m = nums.size();
        vector<vector<bool>> dp(m, vector<bool>(n + 1, false));
        if (nums[0] <= n) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums[i] == j || dp[i - 1][j]) {
                    dp[i][j] = true;
                } else if (nums[i] < j) {
                    dp[i][j] = dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[m - 1][n];
    }
};
int main() {
    Solution sol;
    vector<int> nums{1, 5, 11, 5};
    cout << sol.canPartition(nums);
    system("pause");
    return 0;
}