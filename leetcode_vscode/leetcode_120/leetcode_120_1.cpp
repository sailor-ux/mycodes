#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 递归法，暴力法，超时，存在大量的重复计算！！！
    // 自顶向下的递归 完整的问题，原问题 ----> 最小子问题
    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 0, 0);
    }
    int dfs(const vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }
};
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    system("pause");
    return 0;
}