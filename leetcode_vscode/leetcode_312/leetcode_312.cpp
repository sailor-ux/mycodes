#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; len++) {
            for (int l = 0; l <= n - len; l++) {
                int r = len + l - 1;
                for (int k = l + 1; k <= r - 1; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + nums[l] * nums[k] * nums[r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
int main() {
    vector<int> nums{3, 1, 5, 8};
    Solution sol;
    cout << sol.maxCoins(nums);
    system("pause");
    return 0;
}