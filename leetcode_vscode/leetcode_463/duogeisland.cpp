#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 如果允许存在多个岛屿，求所有岛屿的周长之和：
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeterSum = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    perimeterSum += dfs(grid, row, col);
                }
            }
        }
        return perimeterSum;
    }
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
            return 1;
        }
        if (grid[row][col] == 2) {
            return 0;
        }
        grid[row][col] = 2;
        return dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1);
    }
};
int main() {
    vector<vector<int>> grid{
        {1},
        {1},
        {1},
        {0},
        {1},
        {1}};
    Solution sol;
    cout << sol.islandPerimeter(grid);
    system("pause");
    return 0;
}