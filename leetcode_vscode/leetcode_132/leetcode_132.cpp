#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 两次dp，好题目，第一次dp是常见的经典题型；第二次dp的状态转移方程思路不是那么好理解！！！
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = L + i - 1;
                if (s[i] != s[j]) {
                    continue;
                }
                if (L < 4) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        vector<int> f(n, n);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            if (dp[0][i]) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (dp[j + 1][i]) {
                        f[i] = min(f[j] + 1, f[i]);
                        // 第一个f[j]+1的值(即f[0]+1, 其实未必是f[0]+1, 后同)必须成功赋值给f[i]！！
                        // f[i]要成为一堆值(f[j]+1, 0 <= j < i)当中最小的那一个，那么f[i]一开始必须拿到这堆值中的第一个值f[0]+1
                        // 第一个进入if里面的f[j]+1的值<=f[i]的初值，最简便的方法不需要思考就是把f[i]初值设为INT_MAX
                        // 左边一定<=n, so: f[i]的初值>=n即可
                    }
                }
            }
        }
        return f[n - 1];
    }
};
int main() {
    Solution sol;
    cout << sol.minCut("aab");
    system("pause");
    return 0;
}