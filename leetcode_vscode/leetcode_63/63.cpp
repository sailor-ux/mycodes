#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (flag && obstacleGrid[0][i] == 0) {
                memo[0][i] = 1;
            } else {
                memo[0][i] = 0;
                flag = false;
            }
        }
        flag = true;
        for (int i = 0; i < m; i++) {
            if (flag && obstacleGrid[i][0] == 0) {
                memo[i][0] = 1;
            } else {
                memo[i][0] = 0;
                flag = false;
            }
        }
        return dfs(m - 1, n - 1, memo, obstacleGrid, m, n);
    }
    int dfs(int i, int j, vector<vector<int>>& memo, const vector<vector<int>>& obstacleGrid, const int& m, const int& n) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (obstacleGrid[i][j] == 1) {
            memo[i][j] = 0;
            return 0;
        }
        memo[i][j] = dfs(i, j - 1, memo, obstacleGrid, m, n) + dfs(i - 1, j, memo, obstacleGrid, m, n);
        return memo[i][j];
    }
};
int main() {
    // vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obstacleGrid{{0, 1}, {0, 0}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid);
    system("pause");
    return 0;
}