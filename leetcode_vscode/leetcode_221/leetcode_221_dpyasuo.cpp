#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> f(columns, 0);
        int maxSide = 0, temp = 0;
        for (int i = 0; i < columns; i++) {
            if (matrix[0][i] == '1') {
                f[i] = 1;
            }
            maxSide = max(maxSide, f[i]);
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j == 0) {
                    temp = f[j];
                    if (matrix[i][j] == '1') {
                        f[j] = 1;
                    } else {
                        f[j] = 0;
                    }
                } else {
                    int temp1 = f[j];
                    if (matrix[i][j] == '0') {
                        f[j] = 0;
                    } else {
                        f[j] = min(min(f[j], f[j - 1]), temp) + 1;
                    }
                    temp = temp1;
                }
                maxSide = max(maxSide, f[j]);
            }
        }
        return maxSide * maxSide;
    }
};
int main() {

    system("pause");
    return 0;
}