#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
        return dp[0][0];
    }
    // 滚动数组压缩
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n);
        f[n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                if (i == m - 1) {
                    f[j] = f[j + 1] + grid[i][j];
                    continue;
                }
                if (j == n - 1) {
                    f[j] = f[j] + grid[i][j];
                    continue;
                }
                f[j] = min(f[j], f[j + 1]) + grid[i][j];
            }
        }
        return f[0];
    }
    // 滚动数组压缩
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n + 1, INT_MAX); // 这样子规定f数组，代码更简洁，不需要考虑那么多边界情况，不需要进行那么多分类讨论
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    f[j] = grid[i][j];
                    continue;
                }
                f[j] = min(f[j], f[j + 1]) + grid[i][j];
            }
        }
        return f[0];
    }
    // 滚动数组压缩
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n + 1, INT_MAX); // 这样子规定f数组，代码更简洁，不需要考虑那么多边界情况，不需要进行那么多分类讨论
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                /* if (i == m - 1 && j == n - 1) {
                    f[j] = grid[i][j];
                    continue;
                } */
                f[j] = (min(f[j], f[j + 1]) == INT_MAX ? 0 : min(f[j], f[j + 1])) + grid[i][j];
            }
        }
        return f[0];
    }
};
int main() {

    system("pause");
    return 0;
}