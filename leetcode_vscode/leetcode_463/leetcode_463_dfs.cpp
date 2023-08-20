#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    return dfs(grid, row, col);
                }
            }
        }
        return -1;
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
        {1, 1},
        {1, 1}};
    Solution sol;
    cout << sol.islandPerimeter(grid);
    system("pause");
    return 0;
}