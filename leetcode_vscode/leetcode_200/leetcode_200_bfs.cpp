#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int islandNum = 0;

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    islandNum++;
                    grid[row][col] == '2';
                    q.push({row, col});
                    while (!q.empty()) {
                        pair<int, int> Grid = q.front();
                        q.pop();
                        for (const pair<int, int>& direction : directions) {
                            int r = Grid.first + direction.first, c = Grid.second + direction.second;
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '2';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islandNum;
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