#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /* int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int curMax = arr[i];
            // int curMax = 0;
            for (int j = i - 1; i - j <= k && j >= 0; j--) {
                curMax = max(curMax, arr[j + 1]); // 区间内求最大值不需要遍历区间，新区间的最大值 = max(新纳入区间的数, 原区间的最大值)
                dp[i] = max(dp[i], dp[j] + (i - j) * curMax);
            }
        }
        return dp[n - 1];
    } */
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            // int curMax = arr[i];
            int curMax = 0;
            for (int j = i - 1; i - j <= k && j >= -1; j--) { // 注意j最小要到-1！！！
                curMax = max(curMax, arr[j + 1]);             // 区间内求最大值不需要遍历区间，新区间的最大值 = max(新纳入区间的数, 原区间的最大值)
                dp[i] = max(dp[i], (j == -1 ? 0 : dp[j]) + (i - j) * curMax);
            }
        }
        return dp[n - 1];
    }
};
int main() {
    vector<int> nums{1, 15, 7, 9, 2, 5, 10};
    Solution sol;
    cout << sol.maxSumAfterPartitioning(nums, 3);
    system("pause");
    return 0;
}