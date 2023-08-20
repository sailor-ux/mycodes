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
        vector<bool> dp(n + 1, false);
        if (nums[0] <= n) {
            dp[nums[0]] = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = n; j >= 0; j--) {
                if (j == 0) {
                    dp[j] = false;
                } else if (!dp[j]) {
                    if (nums[i] == j) {
                        dp[j] = true;
                    } else if (nums[i] < j) {
                        dp[j] = dp[j - nums[i]];
                    }
                }
            }
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    vector<int> nums{1, 5, 11, 5};
    cout << sol.canPartition(nums);
    system("pause");
    return 0;
}