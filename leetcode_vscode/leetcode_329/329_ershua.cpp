#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        this->m = matrix.size(), this->n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(matrix, memo, i, j));
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int x, int y) {
        if (memo[x][y] != 0) {
            return memo[x][y];
        }
        int maxLen = 1; // 初值应该为1
        // 本来for循环之前要对路径走过的网格matrix[x][y]进行标记，防止后续路径再走它（for循环结束之后再恢复网格）
        // 后续路径如果要再走这个网格，这个网格的值必须大于当前网格的值，而实际上这个网格的值一定小于当前网格的值
        // 所以说后续路径不可能再走这个网格，这个网格不需要进行标记！！！
        // 路径不可能再走已经走过的网格，所以路径走过的网格（路径上的网格）无需进行标记！！
        // 路径走过的网格如果再走，会出现死循环，而且也不符合题目要求
        for (int i = 0; i < 4; i++) {
            int dx = x + dirs[i][0], dy = y + dirs[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] > matrix[x][y]) {
                maxLen = max(maxLen, dfs(matrix, memo, dx, dy) + 1);
            }
        }
        memo[x][y] = maxLen;
        return maxLen;
    }
};
int main() {

    system("pause");
    return 0;
}