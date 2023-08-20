#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        int maxSide = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    maxSide = max(maxSide, 1);
                    bool flag = true;
                    int possibleMaxSide = min(rows - i, columns - j);
                    for (int k = 1; k < possibleMaxSide; k++) {
                        if (matrix[i + k][j + k] == '0') {
                            break;
                        }
                        for (int m = 0; m < k; m++) {
                            if (matrix[i + m][j + k] == '0' || matrix[i + k][j + m] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            maxSide = max(maxSide, k + 1);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return maxSide * maxSide;
    }
};
int main() {

    system("pause");
    return 0;
}