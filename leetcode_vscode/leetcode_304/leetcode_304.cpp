#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        sums[i][j] = matrix[i][j];
                    } else {
                        sums[i][j] = sums[i][j - 1] + matrix[i][j]; // 应该要想到最前面增加一列0，避免分类讨论、特殊考虑、特殊处理！！！
                    }
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            if (col1 == 0) {
                sum += sums[row][col2];
            } else {
                sum += sums[row][col2] - sums[row][col1 - 1];
            }
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}