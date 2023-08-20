#include <iostream>
#include <vector>
using namespace std;
// ±©Á¦³¬Ê±£¡
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int p = i; p <= m; p++) {
                    for (int q = j; q <= n; q++) {
                        int subMatSum = sum[p][q] + sum[i - 1][j - 1] - sum[p][j - 1] - sum[i - 1][q];
                        if (subMatSum <= k) {
                            res = max(res, subMatSum);
                        }
                    }
                }
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}