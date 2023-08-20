#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ดํมหฃก
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[1][1] = max(1 - dungeon[0][0], 1);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
                if (dungeon[i - 1][j - 1] < 0) {
                    dp[i][j] -= dungeon[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution sol;
    cout << sol.calculateMinimumHP(dungeon);
    system("pause");
    return 0;
}