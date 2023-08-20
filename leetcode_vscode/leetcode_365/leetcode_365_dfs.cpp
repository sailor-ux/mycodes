#include <iostream>
#include <vector>
using namespace std;
// dfs必定陷入死循环！！！
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        vector<vector<int>> memo(jug1Capacity + 1, vector<int>(jug2Capacity + 1, -1));
        return dfs(0, 0, memo, targetCapacity, jug1Capacity, jug2Capacity);
    }
    bool dfs(int remainJug1, int remainJug2, vector<vector<int>>& memo, const int& targetCapacity, const int& jug1Capacity, const int& jug2Capacity) {
        if (memo[remainJug1][remainJug2] != -1) {
            return memo[remainJug1][remainJug2];
        }
        if (remainJug1 == targetCapacity || remainJug2 == targetCapacity || remainJug1 + remainJug2 == targetCapacity) {
            memo[remainJug1][remainJug2] = 1;
            return true;
        }
        memo[remainJug1][remainJug2] = dfs(max(remainJug1 - (jug2Capacity - remainJug2), 0), min(remainJug1 + remainJug2, jug2Capacity), memo, targetCapacity, jug1Capacity, jug2Capacity) ||
                                       dfs(min(remainJug1 + remainJug2, jug1Capacity), max(remainJug2 - (jug1Capacity - remainJug1), 0), memo, targetCapacity, jug1Capacity, jug2Capacity) ||
                                       dfs(jug1Capacity, remainJug2, memo, targetCapacity, jug1Capacity, jug2Capacity) ||
                                       dfs(remainJug1, jug2Capacity, memo, targetCapacity, jug1Capacity, jug2Capacity) ||
                                       dfs(0, remainJug2, memo, targetCapacity, jug1Capacity, jug2Capacity) ||
                                       dfs(remainJug1, 0, memo, targetCapacity, jug1Capacity, jug2Capacity);
        return memo[remainJug1][remainJug2];
    }
};
int main() {
    Solution sol;
    cout << sol.canMeasureWater(3, 5, 4);
    system("pause");
    return 0;
}