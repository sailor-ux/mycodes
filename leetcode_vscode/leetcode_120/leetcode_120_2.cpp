#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 递归法+记忆化record  避免大量的重复计算！！！
    // 仍然超时！！！
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> record(triangle.size(), vector<int>(triangle.size(), NULL));
        return dfs(triangle, record, 0, 0);
    }
    int dfs(const vector<vector<int>>& triangle, vector<vector<int>>& record, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        if (record[i][j] != NULL) {
            return record[i][j];
        }
        return record[i][j] = min(dfs(triangle, record, i + 1, j), dfs(triangle, record, i + 1, j + 1)) + triangle[i][j];
    }
};
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    system("pause");
    return 0;
}