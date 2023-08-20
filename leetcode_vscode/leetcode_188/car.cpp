#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, 0));
        for (int i = 0; i < 2 * k; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            /* dp[i][0] = max(-prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] - prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][2] + prices[i], dp[i - 1][3]); */
            dp[i][0] = max(-prices[i], dp[i - 1][0]);
            int j = 1;
            for (; j <= 2 * k - 3; j += 2) {
                dp[i][j] = max(dp[i - 1][j - 1] + prices[i], dp[i - 1][j]);
                dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
            }
            dp[i][j] = max(dp[i - 1][j - 1] + prices[i], dp[i - 1][j]);
        }
        return dp[n - 1][2 * k - 1];
    }
};
int main() {
    vector<int> prices{2, 4, 1};
    Solution sol;
    cout << sol.maxProfit(2, prices);
    system("pause");
    return 0;
}
