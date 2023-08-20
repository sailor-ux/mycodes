#include <iostream>
#include <set>
#include <vector>
using namespace std;
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
        set<int> st;
        for (int top = 1; top <= m; top++) {
            for (int bot = top; bot <= m; bot++) {
                st.clear();
                st.insert(0); // 注意！
                for (int r = 1; r <= n; r++) {
                    int subMatSum = sum[bot][r] - sum[top - 1][r];
                    if (subMatSum == k) { // 优化，加一点速
                        return k;
                    }
                    auto iter = st.lower_bound(subMatSum - k);
                    if (iter != st.end()) {
                        res = max(res, subMatSum - *iter);
                    }
                    st.insert(subMatSum);
                }
            }
        }
        return res;
    }
};
int main() {
    vector<vector<int>> matrix{{2, 2, -1}};
    Solution sol;
    cout << sol.maxSumSubmatrix(matrix, 3);
    system("pause");
    return 0;
}