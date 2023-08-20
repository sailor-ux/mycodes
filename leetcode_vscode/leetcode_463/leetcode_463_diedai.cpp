#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    perimeter += 4;
                    if (col > 0 && grid[row][col - 1] == 1) {
                        perimeter -= 2;
                    }
                    if (row > 0 && grid[row - 1][col] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
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