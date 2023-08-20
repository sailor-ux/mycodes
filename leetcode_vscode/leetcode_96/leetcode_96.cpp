#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1; // 要单独处理
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    cout << sol.numTrees(3);
    return 0;
}