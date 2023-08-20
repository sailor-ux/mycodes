#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int islandNum = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '2'; // 改变，置为2，必须在先，dfs的递归调用在后；否则dfs递归调用陷入死循环
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + directions[i].first, col + directions[i].second);
        }
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