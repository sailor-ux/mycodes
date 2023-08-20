#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandNum = 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, directions, row, col, m, n);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
    void dfs(vector<vector<char>>& grid, const vector<pair<int, int>>& directions, const int& row, const int& col, const int& m, const int& n) {
        if (!inArea(row, col, m, n) || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0'; // Â½µØ³ÁÃ»
        for (const pair<int, int>& direction : directions) {
            dfs(grid, directions, row + direction.first, col + direction.second, m, n);
        }
    }
    bool inArea(const int& row, const int& col, const int& m, const int& n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};
int main() {
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    Solution sol;
    cout << sol.numIslands(grid);
    system("pause");
    return 0;
}