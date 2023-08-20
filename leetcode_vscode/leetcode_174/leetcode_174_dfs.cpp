#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int pathSum = 0, minInitVal = 1, res = INT_MAX; // 考虑[[为正]]这种情况，所以minInitVal的初值为1
        dfs(0, 0, pathSum, minInitVal, res, dungeon);
        return res;
    }
    void dfs(int i, int j, int& pathSum, int& minInitVal, int& res, const vector<vector<int>>& dungeon) {
        if (i == dungeon.size() || j == dungeon[0].size()) {
            return;
        }
        int preState = pathSum + minInitVal;
        if (preState + dungeon[i][j] < 1) {
            minInitVal += (1 - preState - dungeon[i][j]);
        }
        pathSum += dungeon[i][j];
        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            res = min(res, minInitVal);
        }
        dfs(i, j + 1, pathSum, minInitVal, res, dungeon);
        dfs(i + 1, j, pathSum, minInitVal, res, dungeon);
        pathSum -= dungeon[i][j];
        if (preState + dungeon[i][j] < 1) {
            minInitVal -= (1 - preState - dungeon[i][j]);
        }
    }
};
int main() {
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution sol;
    cout << sol.calculateMinimumHP(dungeon);
    system("pause");
    return 0;
}