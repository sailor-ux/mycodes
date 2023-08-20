#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxVal = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
int main() {
    vector<int> nums{1, -2, 3, 10, -4, 7, 2, -5};
    Solution sol;
    cout << sol.maxSubArray(nums);
    system("pause");
    return 0;
}