#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> tempGrid(grid);
        int maxArea = maxAreaOfIsland(tempGrid);
        tempGrid = grid;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 0) {
                    tempGrid[row][col] = 1;
                    maxArea = max(maxArea, maxAreaOfIsland(tempGrid));
                    tempGrid = grid;
                }
            }
        }
        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islandArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    islandArea = max(islandArea, dfs(grid, row, col));
                }
            }
        }
        return islandArea;
    }
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1) {
            return 0;
        }
        grid[row][col] = 2;
        return 1 + dfs(grid, row - 1, col) + dfs(grid, row + 1, col) + dfs(grid, row, col - 1) + dfs(grid, row, col + 1);
    }
};
int main() {

    system("pause");
    return 0;
}