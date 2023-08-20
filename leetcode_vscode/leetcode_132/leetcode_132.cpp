#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // ����dp������Ŀ����һ��dp�ǳ����ľ������ͣ��ڶ���dp��״̬ת�Ʒ���˼·������ô����⣡����
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
                        // ��һ��f[j]+1��ֵ(��f[0]+1, ��ʵδ����f[0]+1, ��ͬ)����ɹ���ֵ��f[i]����
                        // f[i]Ҫ��Ϊһ��ֵ(f[j]+1, 0 <= j < i)������С����һ������ôf[i]һ��ʼ�����õ����ֵ�еĵ�һ��ֵf[0]+1
                        // ��һ������if�����f[j]+1��ֵ<=f[i]�ĳ�ֵ������ķ�������Ҫ˼�����ǰ�f[i]��ֵ��ΪINT_MAX
                        // ���һ��<=n, so: f[i]�ĳ�ֵ>=n����
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