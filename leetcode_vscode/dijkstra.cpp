#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--; // 顶点归到[0, n - 1]
        vector<vector<int>> arc(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            arc[i][i] = 0;
        }
        for (const vector<int>& time : times) {
            arc[time[0] - 1][time[1] - 1] = time[2];
        } // 初始化邻接矩阵arc
        vector<int> final(n, 0);
        final[k] = 1; // 初始化final数组
        vector<int> D(n, 0);
        for (int i = 0; i < n; i++) {
            D[i] = arc[k][i];
        } // 初始化D数组，为arc的第k行
        for (int i = 1; i < n; i++) {
            int minn = INT_MAX, idx = -1;
            for (int j = 0; j < n; j++) {
                if (final[j] == 0 && D[j] < minn) {
                    minn = D[j];
                    idx = j;
                }
            }
            if (idx == -1) {
            }
            final[idx] = 1;
            for (int j = 0; j < n; j++) {
                if (final[j] == 0 && arc[idx][j] != INT_MAX && D[idx] + arc[idx][j] < D[j]) {
                    D[j] = minn + arc[idx][j];
                }
            }
        }
        return *max_element(D.begin(), D.end()) == INT_MAX ? -1 : *max_element(D.begin(), D.end());
    }
};
int main() {
    vector<vector<int>> times{{1, 2, 1}};
    Solution sol;
    cout << sol.networkDelayTime(times, 2, 2);
    system("pause");
    return 0;
}