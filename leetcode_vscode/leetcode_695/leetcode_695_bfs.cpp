#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int curIslandArea = 0, maxIslandArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 2;
                    curIslandArea = 1;
                    q.push({row, col});
                    while (!q.empty()) {
                        pair<int, int> Grid = q.front();
                        q.pop();
                        for (const pair<int, int>& direction : directions) {
                            int r = Grid.first + direction.first, c = Grid.second + direction.second;
                            if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1) {
                                grid[r][c] = 2;
                                curIslandArea++;
                                q.push({r, c});
                            }
                        }
                    }
                    maxIslandArea = max(curIslandArea, maxIslandArea);
                }
            }
        }
        return maxIslandArea;
    }
};
int main() {

    system("pause");
    return 0;
}