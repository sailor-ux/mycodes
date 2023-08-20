#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
    // 一维前缀和！！！
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m, vector<int>(n + 1, 0)); // 最前面多一列0，省得列下标为-1时越界要特殊考虑特殊处理！！
            for (int i = 0; i < m; i++) {
                for (int j = 1; j <= n; j++) {
                    sums[i][j] = sums[i][j - 1] + matrix[i][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            sum += sums[row][col2 + 1] - sums[row][col1];
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}