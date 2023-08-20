#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 自底向上的动态规划  最小子问题dp[n-1][0 ~ n-1] ----> 原问题，完整的问题dp[0][0]
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    system("pause");
    return 0;
}